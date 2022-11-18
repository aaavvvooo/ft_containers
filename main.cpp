#include "stack.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include "vector.hpp"

int main()
{
    //resize
    // ft::vector<int> m(4, 8);
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

    ft::vector<int> m(5, 9);
    std::vector<int> mo(8, 6);
    m.reserve(-1);
    m.assign(0,9);
    for(int i = 0; i < m.size(); ++i)
        std::cout << m[i] << " ";
    std::cout << "\n";
    std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";
    m.assign(mo.begin(), mo.end());
    for(int i = 0; i < m.size(); ++i)
        std::cout << m[i] << " ";
    std::cout << "\n";
    std::cout << "\nSize = " << m.size() << "Capacity = " << m.capacity() << "\n";

}