#include <vector>
#include "sfinae.hpp"
#include <stdexcept>
#include <iostream>
#include <memory>
#include <iterator>

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
		    // typedef RandomAccessIterator<value_type> iterator;
		    // typedef RandomAccessIterator<const value_type> const_iterator;
		    // typedef reverse_iterator<const_iterator> const_reverse_iterator;
		    // typedef reverse_iterator<iterator> reverse_iterator;

		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_array;
			allocator_type	_allocator;

		public:

			/*
				Default constructor creates an empty vector
			*/
			explicit vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _array(NULL), _allocator(alloc) {
				std::cout << "fuck#1\n";
			}

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
			vector(InputIt first, InputIt last, char c, const allocator_type& alloc = allocator_type())
			{
				//TODO: enable_if?
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
					//TODO: push_back:)
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
				Destructor, deconstructs the vector object
			*/
			~vector()
			{
				std::cout << "lower your appetite:)\n";
				this->clear();
				if (this->_array != 0)
					this->_allocator.deallocate(this->_array, this->_capacity);
			}

			//TODO: ASSIGN(for iterators), GET_ALLOCATOR, ITERATORS


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
					throw std::length_error("you don't have enough memory");
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
			/*						Modifiers							*/
			/*															*/
			//////////////////////////////////////////////////////////////

			/*
				Replaces the contents with count copies of value value
			*/
			void assign(size_type count, const T& value)
			{
				this->clear();
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

