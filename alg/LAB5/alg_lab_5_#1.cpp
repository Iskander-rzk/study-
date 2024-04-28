#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <fstream>
#include <ctime>


int* randA(int N); // Предварительное объявление функции
int shell_sort(int *R, int size);
int* best_sort(int N); 
int* worst_sort(int N); 

int main()
{
    std::ofstream myfile;
    myfile.open("alg3_1.csv");
    myfile << "X;Roper;sec;X;Boper;sec;X;Woper;sec\n";
    int N = 1000; // Размер массива
    int* R = randA(N); // Генерация случайного массива
    unsigned int start_time = clock();
    unsigned int end_time = clock();
    for (int i = 0; i < 10; i++ )
    {
        myfile << N << ";";
        myfile << shell_sort(randA(N), N) << ";";
        myfile << clock() - start_time << ";";
        myfile << N << ";";
        myfile << shell_sort(best_sort(N), N) << ";";
        myfile << clock() - start_time << ";";
        myfile << N << ";";
        myfile << shell_sort(worst_sort(N), N) << ";";
        myfile << clock() - start_time << ";" <<"\n";
        N += 1000;
    }

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


int* best_sort(int N)
{
    int* R = new int[N]; // Выделение памяти под массив
    for (int i = 0; i < N; i++)
    {
        R[i] = 1;
    }
    
    return R; // Возвращаем указатель на массив
}


int* worst_sort(int N)
{
    int* R = new int[N]; // Выделение памяти под массив
    for (int i = 0; i < N; i++)
    {
        R[i] = N - i;
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
    /*/
    for (int i = 0; i < size; i++)
    {
        std::cout << R[i] << "  ";
    }
    /*/
    return countn;
}