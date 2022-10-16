#pragma once

#include <iterator>
#include <cstddef>

namespace ft
{
	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag : public ft::input_iterator_tag {};
	struct	bidirectional_iterator_tag : public ft::forward_iterator_tag {};
	struct	random_access_iterator_tag : public bidirectional_iterator_tag {};

	///////////////////////////////////////////////////////////////
	/*															 */
	/*						Iterator							 */
	/*															 */
	///////////////////////////////////////////////////////////////

	template <class Category, class T, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};


	///////////////////////////////////////////////////////////////
	/*															 */
	/*					Iterator_traits							 */
	/*															 */
	///////////////////////////////////////////////////////////////

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <typename _Tp>
	struct iterator_traits<_Tp*>
	{
		typedef random_access_iterator_tag				iterator_category;
		typedef _Tp										value_type;
		typedef ptrdiff_t								difference_type;
		typedef _Tp*										pointer;
		typedef _Tp&										reference;
	};

	template <typename _Tp>
	struct iterator_traits<const _Tp*>
	{
		typedef random_access_iterator_tag				iterator_category;
		typedef _Tp										value_type;
		typedef ptrdiff_t								difference_type;
		typedef const _Tp*								pointer;
		typedef const _Tp&								reference;
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
		private:
			typename T::pointer	_ptr;

		public:
			typedef std::iterator<ft::random_access_iterator_tag, T>	iterator_type;

			random_access_iterator(): _ptr(0) {}

			random_access_iterator(typename T::pointer p): _ptr(p) {}

			random_access_iterator(const random_access_iterator &r)
			{
				this->_ptr = r.ptr;
			}

			random_access_iterator &operator=(const random_access_iterator &r)
			{
				if (this != &r)
					this->_ptr = r.ptr;
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

			typename T::reference operator*()const
			{
				return *this->_ptr;
			}

			typename T::pointer operator->()const
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
				random_access_iterator temp;
				temp = *this;
				this->_ptr -= 1;
				return temp;
			}

			typename T::reference operator[](typename T::difference_type n)const
			{
				return *(this->_ptr + n);
			}

			random_access_iterator operator+=(typename T::difference_type n)
			{
				this->_ptr += n;
				return this;
			}

			random_access_iterator operator-=(typename T::difference_type n)
			{
				this->_ptr -= n;
				return this;
			}

			random_access_iterator operator+(typename T::difference_type n)
			{
				random_access_iterator temp = *this;
				temp._ptr += n;
				return temp;
			}

			random_access_iterator operator-(typename T::difference_type n)
			{
				random_access_iterator temp = *this;
				temp._ptr -= n;
				return temp;
			}

			typename T::difference_type operator-(const random_access_iterator &rhs)
			{
				typename T::difference_type diff = 0;
				diff = this->_ptr - rhs._ptr;
				return diff;
			}

			typename T::pointer base()const
			{
				return this->_ptr;
			}
	};

}