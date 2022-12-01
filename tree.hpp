#pragma once

#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
    template <typename T>
    struct Tree_Node
    {
        typedef T value_type;

        value_type  _data;
        Tree_Node   *_left;
        Tree_Node   *_right;
        Tree_Node   *_parent;

        Tree_Node(): _data(0), _left(0), _right(0), _parent(0) {}

        Tree_Node(const value_type &v, l = 0, r = 0, p = 0): _data(v), _left(l), _right(r), _parent(p) {}

        Tree_Node(const Tree_Node &tn): _data(tn._data), _left(tn._left), _right(tn._right), _parent(tn._parent) {}

        Tree_Node &operator=(const Tree_Node &rhs)
        {
            if (rhs == *this)
                return *this;
            
            this->_data = rhs._data;
            this->_left = rhs._left;
            this->_parent = rhs._parent;
            this->_right = rhs._right;
            return *this;
        }

        bool operator==(const Tree_Node &rhs)
        {
            return this->_data == rhs._data;
        }

        virtual ~Tree_Node();
    };

    template <typename T, class Compare>
    class BST_Iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
            typedef typename T::value_type                                                                  value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;

        private:
            T           *_node;
            T           *_last_node;
            Compare     _comp;

        public:
            BST_Iterator(const Compare &comp = Compare()): _node(), _last_node(), _comp(comp) {}
            BST_Iterator(T *node, T *last_node, const Compare &comp = Compare()): _node(node), _last_node(last_node), _comp(comp) {}
            BST_Iterator(const BST_Iterator &rhs): _node(rhs._node), _last_node(rhs._last_node), _comp(rhs._comp) {}
            BST_Iterator &operator=(const BST_Iterator &rhs)
            {
                if (*this == rhs)
                    return *this;
                this->_node = rhs._node;
                this->_last_node = rhs._last_node;
                this->_comp = rhs._comp;
                return *this;
            }

            bool operator==(BST_Iterator &rhs)
            {
                return this->_node == rhs._node;
            }

            bool operator!=(BST_Iterator &rhs)
            {
                return !(*this == rhs);
            }

            reference operator*()const
            {
                return this->_node->value;
            }

            pointer operator->()const
            {
                return &this->_node->value;
            }



            virtual ~BST_Iterator();




    };

    template <typename T, typename Compare = ft::less<T>, typename Node = ft::Tree_Node<T>,
			typename Type_Alloc = std::allocator<T>, typename Node_Alloc = std::allocator<Node> >
    class BST
    {
        public:
            typedef T                       value_type;
            typedef size_t                  size_type;
            typedef Node                    node_type;
            typedef Node *                  node_pointer;
            typedef Node_Alloc              allocator_type;
            //iterator
            //const_iterator

        private:
            node_pointer        _node;
            allocator_type      _alloc;

        public:
            BST(const allocator_type& alloc = allocator_type()): _alloc(alloc)
            {
                this->_alloc.allocate(1);
                this->_alloc.construct(_node, Node(_node, _node, _node));
            }

            ~BST()
            {
                this->_alloc.destroy(_node);
                this->_alloc.deallocate(1);
            }



    };

    
}