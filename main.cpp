#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <fstream>
#include <ctime>
  
void add(int* R);
void subtract(int, int);
void multiply(int, int);
  
int main()
{
    int N = 10000;
    int* R = new int[N];
    std::random_device rd; // Используем генератор случайных чисел

    std::mt19937 gen(rd()); // Создаем генератор случайных чисел на основе seed
    std::uniform_int_distribution<int> dist(0, 10000); // Определение диапазона случайных чисел

    for (int i = 0; i < N; i++) // Вывод исходного массива 
    {
        R[i] = dist(gen);
    }   
    void (*operations[1])(int, int) = {add};
       
    // получаем длину массива
    unsigned length = std::size(operations);
       
    for(unsigned i{}; i < length; i++)
    {
        operations[i](R);    // вызов функции по указателю
    }
}
void add(int* R)
{
    std::ofstream myfile;
    myfile.open("example.csv");
    myfile << "X;Y2;Y3\n"; // запись заголовка из двух ячеек
    int y2, y3;

    int k = 0;
    unsigned int start_time = clock();
    int n = 0;
    int m = 0;
    int max_sum;
    k += 3;

    for (int i = 0; i < 25; i++)
    {
        n = n + R[i];
        if (m < R[i])
        {
            m = R[i];
            max_sum = n;
        }
        k += 6;
    }
    std::cout << max_sum << std::endl;
    std::cout << n - max_sum << std::endl;
    unsigned int end_time = clock(); // конечное врем
    std::cout << end_time << std::endl;
}