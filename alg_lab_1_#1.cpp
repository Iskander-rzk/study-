#include <iostream>
#include <list>
#include <random>
#include <cstdlib>

int main()
{
    int n = 0;
    int m = 0;
    int max_sum;
    int lst1[25] = { 27, 83, 14, 62, 75, 41, 29, 6, 97, 50, 18, 67, 9, 32, 89, 55, 23, 79, 38, 91, 12, 58, 21, 72, 43 };
    for (int i = 0; i < 25; i++)
    {
        n = n + lst1[i];
        if (m < lst1[i])
        {
            m = lst1[i];
            max_sum = n;
        }
    }
    std::cout << max_sum << std::endl;
    std::cout << n - max_sum;
    return 0;
}