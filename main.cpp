#include "stack.hpp"
#include <iostream>

int main()
{
    ft::stack<int> k;
    ft::stack<int> m;

    k.push(7);
    k.push(7);
    m.push(7);
    if (k == m)
        std::cout << "ZIBIL1\n";
    if (k != m)
        std::cout << "ZIBIL2\n";
    if (k <= m)
        std::cout << "ZIBIL3\n";
    if (k >= m)
        std::cout << "ZIBIL4\n";
    if (k > m)
        std::cout << "ZIBIL5\n";
    if (k < m)
        std::cout << "ZIBIL6\n";
}