#pragma once

#include <vector>
#include "sfinae.hpp"
#include "iterator.hpp"
#include <stdexcept>
#include <iostream>
#include <memory>
#include <iterator>
#include <type_traits>

namespace ft
{
    template<typename T, class Allocator = std::allocator<T> > class vector 
    {
        public:
            typedef T value_type;
		    typedef Allocator allocator_type;
		    typedef std::size_t size_type;
		    typedef std::ptrdiff_t difference_type;
		    typedef value_type& reference;
		    typedef const value_type& const_reference;
		    typedef typename Allocator::pointer pointer;
		    typedef typename Allocator::const_pointer const_pointer;
		    typedef typename ft::random_access_iterator<value_type> iterator;
		    typedef typename ft::random_access_iterator<const value_type> const_iterator;
		    typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		    typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_array;
			allocator_type	_allocator;

		public:

			/*
				Default constructor creates an empty vector
			*/
			explicit vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _array(NULL), _allocator(alloc) {}

			/*
				Parametryzed constructor, creates a vector of n copies of val
			*/
			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()): _size(0), _capacity(n), _allocator(alloc)
			{
				if (n == 0)
					_array = NULL;
				else
					_array = _allocator.allocate(n);
				try
				{
					for (size_type i = 0; i < n; ++i)
					{
						_allocator.construct(_array + i, val);
						++_size;
					}
				}
				catch(...)
				{
					this->clear();
					_allocator.deallocate(_array, n);
					throw;
				}
			}

			/*
				Creates a vector from the range[first, last)
			*/
			template<class InputIt>
			vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
					typename enable_if<!is_integral<InputIt>::value, bool>::type* = 0)
			{
				difference_type dist = distance(first, last);
				this->_array = this->_allocator.allocate(dist);
				this->_capacity = dist;
				this->_size = 0;
				this->_allocator = alloc;
				try
				{
					while(first != last)
					{
						this->push_back(*first);
						++first;
					}
				}
				catch(...)
				{
					this->clear();
					_allocator.deallocate(_array, dist);
					throw;
				}
			}

			/*
				Copy constructor, creates a new object, as a copy of v
			*/
			vector(const vector &v)
			{
				this->_allocator = v._allocator;
				this->_size = v._size;
				this->_capacity = v._capacity;
				this->_array = this->_allocator.allocate(this->_capacity);
				for(size_type i = 0; i < this->size(); ++i)
					this->push_back(v._array[i]);
			}

			/*
				Copy assignment operator
			*/
			vector &operator=(const vector &v)
			{
				if (this != &v)
				{
					this->clear();
					this->_allocator = v._allocator;
					this->_size = v._size;
					this->_capacity = v._capacity;
					this->_array = this->_allocator.allocate(this->_capacity);
					for(size_type i = 0; i < this->size; ++i)
						this->push_back(v._array[i]);
				}
				return (*this);
			}

			/*
				Returns a copy of the allocator object associated with the vector.
			*/
			allocator_type get_allocator() const
			{
				return this->_allocator;
			}

			/*
				Destructor, deconstructs the vector object
			*/
			~vector()
			{
				this->clear();
				if (this->_array != 0)
					this->_allocator.deallocate(this->_array, this->_capacity);
			}

			//////////////////////////////////////////////////////////////
			/*															*/
			/*						Capacity							*/
			/*															*/
			//////////////////////////////////////////////////////////////

			/*
				Returns the amount of elements in the vector
			*/
			size_type size()const
			{
				return this->_size;
			}

			/*
				Return the maximal amount of elements, the vector can keep
			*/
			size_type max_size()const
			{	
				return this->_allocator.max_size();
			}

			/*
				Returns true, if container is empty, otherwise false
			*/
			bool empty()const
			{
				return this->_size == 0;
			}

			/*
				Returns currently allocated storage
			*/
			size_type capacity()const
			{
				return this->_capacity;
			}

			/*
				Reserves new_cap amount of memory, if can't allocate throws bad_alloc, or length_error
			*/
			void reserve(size_type new_cap)
			{
				pointer temp_arr;
				size_type temp_size;

				if (this->_capacity == this->max_size() || new_cap > this->max_size())
					throw std::length_error("ara, es edqan tex chunem, ara, zpi qez ara!\n");
				if (new_cap > this->_capacity)
				{
					try
					{
						temp_arr = this->_allocator.allocate(new_cap);
						for(temp_size = 0; temp_size < this->_size; ++temp_size)
							this->_allocator.construct(temp_arr + temp_size, this->_array[temp_size]);
					}
					catch(...)
					{
						for(size_type i = 0; i < temp_size; ++i)
							this->_allocator.destroy(temp_arr + i);
						this->_allocator.deallocate(temp_arr, new_cap);
					}
				}
				for (size_type k = 0; k < this->_size; ++k)
					this->_allocator.destroy(this->_allocator.address(this->_array[k]));
				this->_allocator.deallocate(this->_array, this->_capacity);
				this->_array = temp_arr;
				this->_capacity = new_cap;
				this->_size = temp_size;
			}

			//////////////////////////////////////////////////////////////
			/*															*/
			/*					 Element access							*/
			/*															*/
			//////////////////////////////////////////////////////////////

			/*
				Returns a reference to the element at specified location pos. 
				No bounds checking is performed.
			*/
			reference operator[](size_type pos)
			{
				return this->_array[pos];
			}

			const_reference operator[](size_type pos)const
			{
				return this->_array[pos];
			}

			/*
				Returns a reference to the first element in the container.
			*/
			reference front()
			{
				return this->_array[0];
			}

			const_reference front() const
			{
				return this->_array[0];
			}

			/*
				Returns a reference to the last element in the container.
			*/
			reference back()
			{
				return this->_array[this->_size - 1];
			}

			const_reference back()const
			{
				return this->_array[this->_size - 1];
			}

			/*
				Returns pointer to the underlying array serving as element storage.
			*/
			T* data()
			{
				return this->_array;
			}

			const T* data()const
			{
				return this->_array;
			}

			/*
				Returns a reference to the element at specified location pos.
				Bound check is performed.
			*/
			reference at(size_type pos)
			{
				if (pos >= this->_size)
					throw std::out_of_range("gna gti qez vektori taracqum ara");
				return this->_array[pos];
			}	

			const_reference at(size_type pos)const
			{
				if (pos >= this->_size)
					throw std::out_of_range("gna gti qez vektori taracqum ara");
				return this->_array[pos];
			}

			//////////////////////////////////////////////////////////////
			/*															*/
			/*					 	Iterators							*/
			/*															*/
			//////////////////////////////////////////////////////////////

			iterator				begin()
			{
				return iterator(this->_array);
			}

    		const_iterator			cbegin() const
			{
				return const_iterator(this->_array);
			}

			iterator				end()
			{
				return iterator(this->_array + this->_size);
			}

			const_iterator			cend()const
			{
				return const_iterator(this->_array + this->_size);
			}

			reverse_iterator 		rbegin()
			{
				return reverse_iterator(this->end());
			}

			const_reverse_iterator crbegin()const
			{
				return reverse_iterator(this->cend());
			}

			reverse_iterator 		rend()
			{
				return reverse_iterator(this->begin());
			}

			const_reverse_iterator crend()const
			{
				return reverse_iterator(this->cbegin());
			}


			//////////////////////////////////////////////////////////////
			/*															*/
			/*						Modifiers							*/
			/*															*/
			//////////////////////////////////////////////////////////////

			/*
				Replaces the contents with count copies of value value
			*/
			void assign(size_type count, const T& value)
			{
				this->clear();
				if (count > this->max_size())
					throw std::length_error("ara, es edqan tex chunem, ara, zpi qez ara!");
				if (count > this->_capacity)
				{
					this->_allocator.deallocate(this->_array, this->_capacity);
					this->_array = this->_allocator.allocate(count);
					this->_capacity = count;
				}
				while (this->_size < count)
				{
					this->_allocator.construct(this->_array + this->_size, value);
					++this->_size;
				}			
			}

			template <class InputIt>
			void assign(InputIt first, InputIt last,
				typename enable_if<!is_integral<InputIt>::value, bool>::type* = 0)
			{
				difference_type dist = ft::distance(first, last);
				this->clear();
				if (dist > this->_capacity)
				{
					this->_allocator.deallocate(this->_array, this->_capacity);
					this->_array = this->_allocator.allocate(dist);
					this->_capacity = dist;
				}
				while(this->_size < this->_capacity)
				{
					this->push_back(*first);
					++first;
				}
			}

			/*
				Resizes the container to contain count elements.
			*/
			void resize(size_type count)
			{
				if (count > this->max_size())
					throw std::length_error("ara, es edqan tex chunem, ara, zpi qez ara!\n");
				if (count < this->_size)
				{
					while (this->_size > count)
					{
						this->_allocator.destroy(this->_array + this->_size);
						--this->_size;
					}
				}
				else 
				{
					this->_capacity = count;
					while (this->_size < this->_capacity)
						this->push_back(T());
				}
			}

			void resize(size_type count, T value)
			{
				if (count > this->max_size())
					throw std::length_error("you don't have enough memory, ara");
				if (count < this->_size)
				{
					while (this->_size > count)
					{
						this->_allocator.destroy(this->_array + this->_size);
						--this->_size;
					}
				}
				else 
				{
					this->_capacity = count;
					while (this->_size < this->_capacity)
						this->push_back(value);
				}
			}

			/*
				Inserts elements at the specified location in the container.
			*/
			iterator insert(const_iterator pos, const T& value)
			{
				pointer _temp;
				

			}
			
			/*
				Appends the given element value to the end of the container.
			*/
			void push_back(const T& value)
			{
				if (this->_size + 1 > this->_capacity)
					this->reserve(this->_capacity + 1);
				this->_allocator.construct(this->_array + this->_size, value);
				++_size;
			}

			/*
				Removes the last element of the container.
			*/
			void pop_back()
			{
				this->_allocator.destroy(this->_array + this->_size);
				--this->_size;
			}

			/*
				Deletes the vector
			*/
			void clear()
			{
				for (size_type i = 0; i < this->_size; ++i)
					this->_allocator.destroy(this->_array + i);
				this->_size = 0;
			}
    };
}

