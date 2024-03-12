#include <iostream>
#include <list>
#include <random>
#include <fstream>
#include <ctime>

int* randA(int N); // Предварительное объявление функции
int shell_sort(int *R, int size);

int main()
{
    int N = 10; // Размер массива
    int* R = randA(N); // Генерация случайного массива
    std::cout << shell_sort(randA(N), N);

    delete[] R; // Освобождение памяти

    return 0;
}

int* randA(int N)
{
    int* R = new int[N]; // Выделение памяти под массив
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100000);

    for (int i = 0; i < N; i++)
    {
        R[i] = dist(gen);
    }
    
    return R; // Возвращаем указатель на массив
}

int shell_sort(int *R, int size) 
{
    int countn = 3;
    for (int s = size / 2; s > 0; s /= 2) {
        countn += 2;
        for (int i = s; i < size; ++i) {
            countn += 2;
            for (int j = i - s; j >= 0 && R[j] > R[j + s]; j -= s) {
                countn += 5;
                int temp = R[j];
                R[j] = R[j + s];
                R[j + s] = temp;
                countn += 4;
            }
        }
    }
    return countn;
}