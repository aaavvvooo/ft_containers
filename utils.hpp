#include <iostream>

namespace ft
{
    template<typename T>
	void swap(T &a, T &b)
	{
		T temp = b;
		b = a;
		a = temp;
	}

    template <class Input1, class Input2>
    bool equal(Input1 first1, Input1 last1, Input2 first2, Input2 last2)
    {
        if (ft::distance(first1, last1) != ft::distance(first2, last2))
            return false;
        while (first1 != last1)
        {
            if (*first1 != *first2)
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
        {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template<class InputIt1, class InputIt2, typename Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2, Compare comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
        {
            if (comp(*first1, *first2))
                return true;
            if (comp(*first2, *first1))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <typename T1, typename T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;
        pair(): first(), second() {}

        pair(const first_type &x, const second_type &y): first(x), second(y) {}

        template<typename U, typename V>
        pair(const pair<U, V> &p): first(p.first), second(p.second) {}

        pair(const pair &p): first(p.first), second(p.second) {}
        
        pair &operator=(const pair &other)
        {
            first = other.first;
            second = other.second;
            return *this;
        }

        void swap(pair &p)
        {
            ft::swap(first, p1.first);
            ft::swap(second, p.second);
        }
    };

    template <typename T1, typename T2>
    pair<T1, T2> make_pair(const T1 &first, const T2 &second)
    {
        return pair<T1, T2>(first, second);
    }

    template <typename T1, typename T2>
    bool operator==(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return p1.first == p2.first && p1.second == p2.second;
    }

    template <typename T1, typename T2>
    bool operator!=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return !(p1 == p2);
    }

    template <typename T1, typename T2>
    bool operator<(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return p1.first < p2.first || (p1.first <= p2.first && p2.first < p2.second);
    }

    template <typename T1, typename T2>
    bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return !(p1 < p2);
    }

    template <typename T1, typename T2>
    bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return p2 < p1;
    }

    template <typename T1, typename T2>
    bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return !(p1 > p2);
    }

    template <class T>
    struct less : binary_function<T, T, bool>
    {
        bool operator() (const T& x, const T& y) const { return (x < y); }
    };
}