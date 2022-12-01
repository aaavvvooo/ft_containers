#include "stack.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include "vector.hpp"
#include <deque>

#define NS ft
#define TP int

template <typename T>
void	printSize(NS::vector<T> const &deq, bool print_content = 1)
{
	std::cout << "size: " << deq.size() << std::endl;
	std::cout << "max_size: " << deq.max_size() << std::endl;
    std::cout << "capacity: " << deq.capacity() << std::endl;
	if (print_content)
	{
		typename NS::vector<T>::const_iterator it = deq.cbegin();
		typename NS::vector<T>::const_iterator ite = deq.cend();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int main()
{
    // std::vector<int>::const_iterator it = v.begin()
    //resize;
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // m.resize(3);
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // m.resize(10, 7);
    // std::cout << "Size = " << m.size() << "Capacity = " << m.capacity() << "\n";
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";

    //assign
   	// NS::vector<int> vct(7);
	// NS::vector<int> vct_two(4);
	// NS::vector<int> vct_three;
	// NS::vector<int> vct_four;
    

	// for (unsigned long int i = 0; i < vct.size(); ++i)
	// 	vct[i] = (vct.size() - i) * 3;
	// for (unsigned long int i = 0; i < vct_two.size(); ++i)
	// 	vct_two[i] = (vct_two.size() - i) * 5;

    // vct_three.assign(vct.begin(), vct.end());
    // vct.assign(vct_two.begin(), vct_two.end());
    // printSize(vct_three);
    // printSize(vct);

    //reserve, assign
    // ft::vector<int> m(5, 9);
    // std::vector<int> mo(8, 6);
    // m.reserve(-1);
    // m.assign(0,9);
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    // m.assign(mo.begin(), mo.end());
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";

    // std::vector<int> m(4, 8);
    //insert 
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    // std::cout << *m.insert(m.cbegin() + 2, 5) << "\n";
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";

    //insert-count
    // ft::vector<int> m;
    // for(int i = 0; i < 10; ++i)
    //     m.push_back(i);
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    // std::cout << "Insert ret val === " << *m.insert(m.cbegin() + 2, 0, 5) << "\n";
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";

    //insert-range
    // ft::vector<int> m(4, 8);
    // ft::vector<int> mo(9, 3);
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    // std::cout << "Iter === " << *m.insert(m.cbegin() + 2, mo.begin(), mo.end()) << "\n";
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";

    //erase
    // ft::vector<int> m;
    // for(int i = 0; i < 10; ++i)
    //     m.push_back(i);
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    // std::cout << "Iter === " << *m.erase(m.begin()+ 3) << "\n";
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";

    //erase-range
    // ft::vector<int> m;
    // for(int i = 0; i < 10; ++i)
    //     m.push_back(i);
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    // std::cout << "Iter === " << *m.erase(m.begin()+ 3, m.begin() + 6) << "\n";
    // for(int i = 0; i < m.size(); ++i)
    //     std::cout << m[i] << " ";
    // std::cout << "\n";
    // std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    

    // return 0;

    //mli-inspired main for assign

	NS::vector<TP> vct(5);
	NS::vector<TP>::iterator it = vct.begin(), ite = vct.end();

	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
    NS::vector<TP>::iterator gven = ite;
    std::cout << "ite is: " << gven - ite << "\n";
    ite = ite - 2;
	NS::vector<TP> vct_range(it, ite);
    std::cout << "ite is: " << gven - ite << "\n";
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	NS::vector<TP> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(vct);
	printSize(vct_range);
	printSize(vct_copy);

	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(vct);
	printSize(vct_range);
	printSize(vct_copy);
	return (0);
}