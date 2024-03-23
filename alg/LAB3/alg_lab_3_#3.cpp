#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <fstream>
#include <ctime>


int* randA(int N); // Предварительное объявление функции
int bubble_sort(int *R, int size);
int* best_sort(int N); 
int* worst_sort(int N); 

int main()
{
    std::ofstream myfile;
    myfile.open("alg3_3.csv");
    myfile << "X;Roper;sec;X;Boper;sec;X;Woper;sec\n";
    int N = 1000; // Размер массива
    int* R = randA(N); // Генерация случайного массива
    unsigned int start_time = clock();
    unsigned int end_time = clock();
    for (int i = 0; i < 10; i++ )
    {
        myfile << N << ";";
        myfile << bubble_sort(randA(N), N) << ";";
        myfile << clock() - start_time << ";";
        myfile << N << ";";
        myfile << bubble_sort(best_sort(N), N) << ";";
        myfile << clock() - start_time << ";";
        myfile << N << ";";
        myfile << bubble_sort(worst_sort(N), N) << ";";
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
        R[i] = N + 1;
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



int bubble_sort(int arr[], int n)
{
    int i, j, countn = 1;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        countn += 3;
        for (j = 0; j < n - i - 1; j++) {
            countn += 2;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                countn += 4;
            }
            
        }
        
        if (swapped == false)
            break;
            countn++;
        countn += 2;
    }
    return countn;
}