#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <ctime>

int main(int mylist)
{
    int n = 0;
    int m = 0;
    int max_sum;
    int lst1[25] = { 27, 83, 14, 62, 75, 41, 29, 6, 97, 50, 18, 67, 9, 32, 89, 55, 23, 79, 38, 91, 12, 58, 21, 72, 43 };
    for (int k : mylist)
    {
        n = n + k;
        if (m < k)
        {
            m = k;
            max_sum = n;
        }
    }

    std::cout << max_sum << std::endl;
    std::cout << n - max_sum;
    return 0;
}

int random() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_value = std::rand();
    std::list<int> mylist;

    for (int n = 0; n != 25; n++)
    {
        int x = std::rand(); // Note: 1 + rand() % 6 is biased
        mylist.push_back(x);
    }
    int a = 0;
    return mylist;
}