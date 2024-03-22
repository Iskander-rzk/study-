#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>

int countn{ 0 };

int partition(int arr[], int start, int end)
{
	int pivot = arr[start];
	int count = 0;
	countn += 3;
	for (int i = start + 1; i <= end; i++) {
		countn += 2;
		if (arr[i] <= pivot)
			count++;
		countn += 2;

	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	std::swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;
	countn += 4;
	while (i < pivotIndex && j > pivotIndex) {
		countn += 3;
		while (arr[i] <= pivot) {
			i++;
			countn += 2;
		}

		while (arr[j] > pivot) {
			j--;
			countn += 2;
		}

		if (i < pivotIndex && j > pivotIndex) {
			std::swap(arr[i++], arr[j--]);
			countn += 2;
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);
	countn++;
	// Sorting the left part
	quickSort(arr, start, p - 1);
	countn += 2;
	// Sorting the right part
	quickSort(arr, p + 1, end);
	countn += 2;
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
	int mid = N / 2;
    for (int i = 0; i < N; ++i) {
        if (i < mid) {
            R[i] = mid - i;
        } else {
            R[i] = i - mid + 1;
        }
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


int main()
{
	std::ofstream myfile;
	myfile.open("alg3_2.csv");
	int N = 1000;
	myfile << "X;Roper;sec;X;Boper;sec;X;Woper;sec\n";
	unsigned int start_time = clock();
	unsigned int end_time = clock();
	for (int i = 0; i < 10; i++)
	{
		myfile << N << ";";
		int* arr = randA(N);
		quickSort(arr, 0, N - 1);
		myfile << countn << ";" << clock() << ";";
		countn = 0;
		myfile << N << ";";
		quickSort(best_sort(N), 0, N - 1);
		myfile << countn << ";" << clock() << ";";
		countn = 0;
		myfile << N << ";";
		quickSort(worst_sort(N), 0, N - 1);
		myfile << countn << ";" << clock() << "\n";
		countn = 0;
        N += 1000;
	}


	return 0;
}
