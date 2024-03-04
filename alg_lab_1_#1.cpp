#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <fstream>
#include <ctime>

// Объявляем функцию f вне функции main
int f(int* R);

int main()
{
    int N = 1000000;
    int* R = new int[N];
    std::random_device rd; // Используем генератор случайных чисел

    std::mt19937 gen(rd()); // Создаем генератор случайных чисел на основе seed
    std::uniform_int_distribution<int> dist(0, 10000); // Определение диапазона случайных чисел

    for (int i = 0; i < N; i++) // Вывод исходного массива 
    {
        R[i] = dist(gen);
    }

    f(R);

    int* P = new int[N];
    for (int i = 0; i < N; i++) // Заполняем исходный массив
    {
        P[i] = i;
    }
    f(P); // Вызываем функцию f

    int* T = new int[N];
    for (int i = 0; i < N; i++) // Заполняем исходный массив
    {
        T[i] = 10000 - i; // Устанавливаем значения в обратной последовательности
    }
    f(T); // Вызываем функцию f

    return 0;
}


int f(int* R)
{
    std::ofstream myfile;
    myfile.open("alg1.csv");
    myfile << "randmsec;randk;maxmsec;maxk;minmsec;mink\n";
    int y2, y3;
    int k = 0;
    unsigned int start_time = clock();

    int n = 0;
    int m = 0;
    int max_sum;

    unsigned int end_time = clock();
    k += 3;
    myfile << end_time - start_time; 
    myfile << ";"; 
    unsigned int end_time = clock();
    for (int i = 0; i < 10000; i++)
    {
        n = n + R[i];
        if (m < R[i])
        {
            m = R[i];
            max_sum = n;
        }
        k += 6;
    }
    //std::cout << "maximum sum on left side " << max_sum << std::endl;
    //std::cout << "maximum sum on right side "  << n - max_sum << std::endl;
    end_time = clock(); // конечное врем
    //std::cout << "time " << end_time << std::endl;
    return 0;
}

