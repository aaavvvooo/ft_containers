#include "stack.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include "vector.hpp"

int main()
{
    // ft::vector<int> v(2, 3);
    // ft::vector<int>v1 = v;
    // ft::vector<int>v2(v);
    // std::cout << v2.size();
    // std::cout << v1.size();
    // std::cout << v.size();

    //std::vector<int> v;
    ft::vector<int> v(5, 6);

    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    v.reserve(10);
    std::cout << v.capacity() << " " << v.size() << "\n";
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    v.assign(3, 5);
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }

    // std::cout << m << "\n\n\n";
    std::cout << "\n";
    // std::cout << v.at(2) << " " << v.at(3);
}