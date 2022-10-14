#pragma once
#include <deque>

//TODO: when finish vector, replace deque with ft::vector

namespace ft
{
    template <class T, class Container = std::deque<T> >  class stack
    {
        public:
            typedef Container                                container_type;
            typedef typename container_type::value_type      value_type;
            typedef typename container_type::reference       reference;
            typedef typename container_type::const_reference const_reference;
            typedef typename container_type::size_type       size_type;

        protected:
            container_type c;
        
        public:
            
            explicit stack(const container_type &cont = container_type()): c(cont) {}

            stack &operator=(const stack &rhs)
            {
                c = rhs.c;
                return *this;
            }

            /*
                Checks if stack is empty, or not
            */
            bool empty() 
            {
                return c.empty();
            }

            /*
                Returns the size of the stack
            */
            size_type size()
            {
                return c.size();
            }

            /*
                Returns the top element of the stack
            */
            value_type top()
            {
                return c.back();
            }

            /*
                Adds an element to stack from the front
            */
            void push(const value_type &el)
            {
                c.push_back(el);
            }

            /*
                Removes the top from the stack
            */
            void pop()
            {
                c.pop_back();
            }

            template <class T1, class Cont>
                friend bool operator==(const stack<T1, Cont>& x, const stack<T1, Cont>& y)
                {
                    return x.c == y.c;
                }

            template <class T1, class Cont>
                friend bool operator< (const stack<T1, Cont>& x, const stack<T1, Cont>& y)
                {
                    return x.c < y.c;
                }

            template <class T1, class Cont>
                friend bool operator!=(const stack<T1, Cont>& x, const stack<T1, Cont>& y)
                {
                    return x.c != y.c;
                }
            
            template <class T1, class Cont>
                friend bool operator> (const stack<T1, Cont>& x, const stack<T1, Cont>& y)
                {
                    return x.c > y.c;
                }  
            
            template <class T1, class Cont>
                friend bool operator>=(const stack<T1, Cont>& x, const stack<T1, Cont>& y)
                {
                    return x.c >= y.c;
                }
            
            
            template <class T1, class Cont>
                friend bool operator<=(const stack<T1, Cont>& x, const stack<T1, Cont>& y)
                {
                    return x.c <= y.c;
                }
    };
}