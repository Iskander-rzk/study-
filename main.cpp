#include <iostream>

int main()
{
    int n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;
    if (n1 == n2 && n1 == n3) std::cout << 3;
    else if ( n1 != n2 && n1 != n3 && n2 != n3) std::cout << 0;
    else std::cout << 2;
    return 0;
}