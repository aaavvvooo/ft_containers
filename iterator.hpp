#pragma once

#include <iterator>
#include <cstddef>

namespace ft
{
	class	input_iterator_tag {};
	class	output_iterator_tag {};
	class	forward_iterator_tag {};
	class	bidirectional_iterator_tag {};
	class	random_access_iterator_tag {};

	///////////////////////////////////////////////////////////////
	/*															 */
	/*						Iterator							 */
	/*															 */
	///////////////////////////////////////////////////////////////


template <class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&>
        class iterator
        {
            public:
               
                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;
                typedef Category    iterator_category;
        };


	///////////////////////////////////////////////////////////////
	/*															 */
	/*					Iterator_traits							 */
	/*															 */
	///////////////////////////////////////////////////////////////


	template <class Iterator>
	struct iterator_traits
    {   typedef typename Iterator::difference_type       difference_type;
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
        typedef typename Iterator::iterator_category     iterator_category;
    };

    template <class T> 
	struct iterator_traits<T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };
    

    template <class T> 
	class iterator_traits<const T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };


	template <class Iterator>
	typename iterator_traits<Iterator>::difference_type    distance (Iterator first, Iterator last)
	{
		
		typename ft::iterator_traits<Iterator>::difference_type diff = 0;
		while (first != last)
		{
			++first;
			++diff;
		}
		return diff;
	}


	///////////////////////////////////////////////////////////////
	/*															 */
	/*					Random Access Iterator					 */
	/*															 */
	///////////////////////////////////////////////////////////////

	template <typename T>
	class	random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
           	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
           	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
           	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer               pointer;
           	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference             reference;

		private:
			pointer		_ptr;

		public:

			random_access_iterator(): _ptr(0) {}

			random_access_iterator(pointer p): _ptr(p) {}

			random_access_iterator(const random_access_iterator &r)
			{
				this->_ptr = r._ptr;
			}

			random_access_iterator &operator=(const random_access_iterator &r)
			{
				if (this != &r)
					this->_ptr = r._ptr;
				return *this;
			}

			~random_access_iterator() {}

			bool operator==(const random_access_iterator &r)const
			{
				return this->_ptr == r._ptr;
			}

			bool operator!=(const random_access_iterator &r)const
			{
				return this->_ptr != r._ptr;
			}

			bool operator>(const random_access_iterator &r)const
			{
				return this->_ptr > r._ptr;
			}

			bool operator<(const random_access_iterator &r)const
			{
				return this->_ptr < r._ptr;
			}

			bool operator>=(const random_access_iterator &r)const
			{
				return this->_ptr >= r._ptr;
			}

			bool operator<=(const random_access_iterator &r)const
			{
				return this->_ptr <= r._ptr;
			}

			reference operator*()const
			{
				return *this->_ptr;
			}

			pointer operator->()const
			{
				return this->_ptr;
			}

			random_access_iterator operator++()
			{
				this->_ptr += 1;
				return this->_ptr;
			}

			random_access_iterator operator++(int i)
			{
				(void) i;
				random_access_iterator temp;
				temp = *this;
				this->_ptr += 1;
				return temp;
			}

			random_access_iterator operator--()
			{
				this->_ptr -= 1;
				return this->_ptr;
			}

			random_access_iterator operator--(int i)
			{
				(void) i;
				random_access_iterator temp;
				temp = *this;
				this->_ptr -= 1;
				return temp;
			}

			reference operator[](difference_type n)const
			{
				return *(this->_ptr + n);
			}

			random_access_iterator operator+=(difference_type n)
			{
				this->_ptr += n;
				return this;
			}

			random_access_iterator operator-=(difference_type n)
			{
				this->_ptr -= n;
				return this;
			}

			random_access_iterator operator+(difference_type n)
			{
				random_access_iterator temp = *this;
				temp._ptr += n;
				return temp;
			}

			random_access_iterator operator-(difference_type n)
			{
				random_access_iterator temp = *this;
				temp._ptr -= n;
				return temp;
			}

			difference_type operator-(const random_access_iterator &rhs)
			{
				difference_type diff = 0;
				diff = this->_ptr - rhs._ptr;
				return diff;
			}

			pointer base()const
			{
				return this->_ptr;
			}
	};

	template <typename T>
	class	reverse_iterator
	{
		public:
			typedef T    iterator_type;

            /* Preserves Iterator's category. */
            typedef typename ft::iterator_traits<T>::iterator_category 	iterator_category;
            
            /* Preserves Iterator's value type. */
            typedef typename ft::iterator_traits<T>::value_type      	value_type;
            
            /* Preserves Iterator's difference type. */
            typedef typename ft::iterator_traits<T>::difference_type    difference_type;
            
            /* Preserves Iterator's pointer. */
            typedef typename ft::iterator_traits<T>::pointer    		pointer;
            
            /* Preserves Iterator's reference. */
            typedef typename ft::iterator_traits<T>::reference   		reference;

		private:
			pointer		_ptr;

		public:

			reverse_iterator(): _ptr(0) {}

			reverse_iterator(pointer p): _ptr(p) {}

			reverse_iterator(const reverse_iterator &r)
			{
				this->_ptr = r._ptr;
			}

			reverse_iterator &operator=(const reverse_iterator &r)
			{
				if (this != &r)
					this->_ptr = r._ptr;
				return *this;
			}

			~reverse_iterator() {}

			bool operator==(const reverse_iterator &r)const
			{
				return this->_ptr == r._ptr;
			}

			bool operator!=(const reverse_iterator &r)const
			{
				return this->_ptr != r._ptr;
			}

			bool operator>(const reverse_iterator &r)const
			{
				return this->_ptr > r._ptr;
			}

			bool operator<(const reverse_iterator &r)const
			{
				return this->_ptr < r._ptr;
			}

			bool operator>=(const reverse_iterator &r)const
			{
				return this->_ptr >= r._ptr;
			}

			bool operator<=(const reverse_iterator &r)const
			{
				return this->_ptr <= r._ptr;
			}

			reference operator*()const
			{
				return *this->_ptr;
			}

			pointer operator->()const
			{
				return this->_ptr;
			}

			reverse_iterator operator++()
			{
				this->_ptr -= 1;
				return this->_ptr;
			}

			reverse_iterator operator++(int i)
			{
				(void) i;
				reverse_iterator temp;
				temp = *this;
				this->_ptr -= 1;
				return temp;
			}

			reverse_iterator operator--()
			{
				this->_ptr += 1;
				return this->_ptr;
			}

			reverse_iterator operator--(int i)
			{
				(void) i;
				reverse_iterator temp;
				temp = *this;
				this->_ptr += 1;
				return temp;
			}

			reference operator[](difference_type n)const
			{
				return *(this->_ptr + n);
			}

			reverse_iterator operator+=(difference_type n)
			{
				this->_ptr += n;
				return this;
			}

			reverse_iterator operator-=(difference_type n)
			{
				this->_ptr -= n;
				return this;
			}

			reverse_iterator operator+(difference_type n)
			{
				reverse_iterator temp = *this;
				temp._ptr -= n;
				return temp;
			}

			reverse_iterator operator-(difference_type n)
			{
				reverse_iterator temp = *this;
				temp._ptr += n;
				return temp;
			}

			difference_type operator-(const reverse_iterator &rhs)
			{
				difference_type diff = 0;
				diff = this->_ptr - rhs._ptr;
				return diff;
			}

			pointer base()const
			{
				return this->_ptr;
			}
	};

}