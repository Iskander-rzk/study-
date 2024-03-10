#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <fstream>
#include <ctime>

// Объявляем функцию f вне функции main
int f(int* R, int size);

int main()
{
    
    std::ofstream myfile;
    myfile.open("alg1.csv");
    myfile << "X;sec;oper\n";
    int N = 100;
    int n = 0;
    int* R = new int[N];
    std::random_device rd; // Используем генератор случайных чисел

    std::mt19937 gen(rd()); // Создаем генератор случайных чисел на основе seed
    std::uniform_int_distribution<int> dist(0, 10000); // Определение диапазона случайных чисел
    unsigned int start_time = clock();
    unsigned int end_time = clock();
    for (int a = 0; a < 100; a++)
    {
        int* R = new int[N];
        for (int i = 0; i < N; i++) // Вывод исходного массива 
        {
            R[i] = dist(gen);
        }
        
        n = f(R, N);
        end_time = clock();
        myfile << N << ";" << end_time - start_time << ";";
        myfile << n << "\n";
        N += 100;
        delete[] R;
    }

    /*/
    /// Best caase
    for (int a = 0; a < 100; a++)
    {
        int* R = new int[N];
        for (int i = 0; i < N; i++) // Заполняем исходного массива 
        {
            R[i] = i;
        }
        
        n = f(R, N);
        end_time = clock();
        myfile << end_time - start_time << ";";
        myfile << n << "\n";
        N += 100;
        delete[] R;
    }
    /// Worst case
     for (int a = 0; a < 100; a++)
    {
        int* R = new int[N];
        for (int i = 0; i < N; i++) // Вывод исходного массива 
        {
            R[i] = N - i;
        }
        
        n = f(R, N);
        end_time = clock();
        myfile << end_time - start_time << ";";
        myfile << n << "\n";
        N += 100;
        delete[] R;
    } 
/*///
    return 0;
}


int f(int* R, int size)
{
    int y2, y3;
    int k = 0;

    int n = 0;
    int m = -1000000;
    int max_sum;
    k += 3;
    
    //int A[11] = {2, 5, 6, 1, 13, 12, 25, 22, 12, 17, 4};
    for (int i = 0; i < size; i++)
    {
        n = n + R[i];
        if (m < R[i])
        {
            m = R[i];
            max_sum = n;
        }
        k += 6;
    }
    k += 1;
    //std::cout << "maximum sum on left side " << max_sum - m << std::endl;
    //std::cout << "maximum sum on right side "  << n - max_sum << std::endl;


    //std::cout << "time " << end_time << std::endl;
    return k;
}

