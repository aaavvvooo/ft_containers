#include <vector>
#include <memory>

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
		    typedef RandomAccessIterator<value_type> iterator;
		    typedef RandomAccessIterator<const value_type> const_iterator;
		    typedef reverse_iterator<const_iterator> const_reverse_iterator;
		    typedef reverse_iterator<iterator> reverse_iterator;

		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_array;
			allocator_type	_allocator;

		public:
			explicit vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _array(NULL), _allocator(alloc) {}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_capacity = n;
				if ()
			}
    };
}