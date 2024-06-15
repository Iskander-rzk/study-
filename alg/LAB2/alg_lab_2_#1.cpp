#include <iostream>
#include <cstdlib> 
#include <fstream> 
#include <ctime>
#include <vector>
#include <math.h>

// Объявление счетчиков операций для каждого метода поиска
int linearOpCount, endLinearOpCount, sortedLinearOpCount, binaryOpCount, blockOpCount = 0;

// Функция для линейного поиска в массиве
int linearSearch(int* array, int size, int target) // Линейный поиск
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        linearOpCount += 4;

        if (array[i] == target)
        {
            linearOpCount += 1;
            index = i;
            return index; // Индекс искомого элемента
        }

    }
    return -1; // Элемент не найден 
}

// Функция для быстрого линейного поиска с барьером в массиве
int endLinearSearch(int* array, int size, int target) // Быстрый линейный с барьером
{
    int last = array[size - 1];
    array[size - 1] = target;
    endLinearOpCount += 2;

    int i = 0;
    for (int i = 0; array[i] != target; i++)
    {
        endLinearOpCount += 3;
    }
    array[size - 1] = last;
    endLinearOpCount += 4;
    if (i != (size - 1) || target == last)
    {
        return i;
    }    
    return -1;
}

// Функция для быстрого линейного поиска в упорядоченном массиве
int sortedFastLinearSearch(int* array, int size, int target) // Быстрый линейный в упорядоченном массиве
{
    int index = 0;
    
    for (int i = 0; ; i++)
    {
        sortedLinearOpCount += 3;
        if (array[i] == target)
        {
            sortedLinearOpCount += 1;
            index = i;
            return index; // Индекс найденного элемента
        }
        if (array[i] > target)
        {
            sortedLinearOpCount += 1;
            return -1; // Элемент не найден (все остальные элементы больше)  
        }
    }
}


// Функция для бинарного поиска в упорядоченном массиве
int binarySearchSorted(int* array, int first, int last, int target) // Бинарный поиск в упорядоченном массиве
{
    int middle = 0;
    while (1)
    {
        middle = (first + last) / 2;
        binaryOpCount += 2;
        if (target < array[middle])
        {
            binaryOpCount += 2;
            last = middle - 1;
        }

        else if (target > array[middle])
        {
            binaryOpCount += 3;
            first = middle + 1;
        }
        else
            return middle; // Функция возвращает индекс ячейки

        if (first > last)
        { // Если границы сомкнулись 
            return -1;
        }

    }
}


// Функция для блочного поиска в упорядоченном массиве
int blockSearchSorted(int* array, int size, int target) // Блочный поиск в упорядоченном массиве
{

    int blockSize = static_cast<int>(sqrt(size)); // Размер блока
    int blockIndex = 0;

    while (blockIndex * blockSize < size && array[blockIndex * blockSize] < target)
    {
        blockOpCount += 4;
        blockIndex++;
    }

    for (int i = (blockIndex - 1) * blockSize; i < std::min(blockIndex * blockSize, size); i++) // Линейный поиск внутри блока
    {
        blockOpCount += 5;
        if (array[i] == target)
        {
            blockOpCount += 2;
            return i; // Элемент найден
        }
    }

    return -1; // Элемент не найден

}


int main()
{
    srand(time(0));
    // Открытие файла для записи 
    std::ofstream myfile;
    myfile.open("alg02.csv");
    myfile << "linear_random; linear_best; linear_worst; time1; fast_linearB_random; fast_linearB_best; fast_linearB_worst; time2; fast_linear_random; fast_linear_best; fast_linear_worst; time3; binary_random; binary_best; binary_worst; time4; block_random; block_best; block_worst; time5; size;\n"; // Запись заголовка из двух ячеек 

    int targetValue = 0;

    for (int size = 10; size < 10000; size += 100)
    {
        int* randomArray = new int[size];
        int* sortedArray = new int[size];
        int* binnarArray = new int[size];

        for (int i = 0; i < size - 1; i++) // Несортированный массив
        {
            randomArray[i] = rand();
        }

        for (int i = 0; i < size - 1; i++) // Сортированный массив
        {
            sortedArray[i] = i;
        }

        for (int i = 0; i < size - 1; i++) // Сортированный массив
        {
            if (i == (size - 1) / 2)
            {
                binnarArray[i] = targetValue;
            }
            binnarArray[i] = i;
        }

        srand(time(0));
        linearOpCount = 0;
        std::cout << linearSearch(randomArray, size, targetValue) << std::endl;
        myfile << linearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        linearOpCount = 0;
        std::cout << linearSearch(sortedArray, size, targetValue) << std::endl;
        myfile << linearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        linearOpCount = 0;
        std::cout << linearSearch(sortedArray, size, size) << std::endl;
        myfile << linearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        myfile << clock() / 1000.0;
        myfile << ";"; // Запись разделителя ячеек

        srand(time(0));
        endLinearOpCount = 0;
        std::cout << endLinearSearch(randomArray, size, targetValue) << std::endl;
        myfile << endLinearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        endLinearOpCount = 0;
        std::cout << endLinearSearch(sortedArray, size, targetValue) << std::endl;
        myfile << endLinearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        endLinearOpCount = 0;
        std::cout << endLinearSearch(sortedArray, size, size) << std::endl;
        myfile << endLinearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        myfile << clock() / 1000.0;
        myfile << ";"; // Запись разделителя ячеек


        srand(time(0));
        sortedLinearOpCount = 0;
        std::cout << sortedFastLinearSearch(randomArray, size, targetValue) << std::endl;
        myfile << sortedLinearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        sortedLinearOpCount = 0;
        std::cout << sortedFastLinearSearch(sortedArray, size, targetValue) << std::endl;
        myfile << sortedLinearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        sortedLinearOpCount = 0;
        std::cout << sortedFastLinearSearch(sortedArray, size, size) << std::endl;
        myfile << sortedLinearOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        myfile << clock() / 1000.0;
        myfile << ";"; // Запись разделителя ячеек

        srand(time(0));
        binaryOpCount = 0;
        std::cout << binarySearchSorted(randomArray, 0, size - 1, targetValue) << std::endl;
        myfile << binaryOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        binaryOpCount = 0;
        std::cout << binarySearchSorted(binnarArray, 0, size - 1, targetValue) << std::endl;
        myfile << binaryOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        binaryOpCount = 0;
        std::cout << binarySearchSorted(sortedArray, 0, size - 1, size) << std::endl;
        myfile << binaryOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        myfile << clock() / 1000.0;
        myfile << ";"; // Запись разделителя ячеек

        srand(time(0));
        blockOpCount = 0;
        std::cout << blockSearchSorted(randomArray, size, targetValue) << std::endl;
        myfile << blockOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        blockOpCount = 0;
        std::cout << blockSearchSorted(sortedArray, size, targetValue) << std::endl;
        myfile << blockOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        blockOpCount = 0;
        std::cout << blockSearchSorted(sortedArray, size, size) << std::endl;
        myfile << blockOpCount; // Время работы программы
        myfile << ";"; // Запись разделителя ячеек
        myfile << clock() / 1000.0;
        myfile << ";"; // Запись разделителя ячеек

        std::cout << std::endl;

        myfile << size; // Запись в файл столбца с размером
        myfile << "\n"; // Запись в файл перехода на новую строку
        delete[] randomArray;
        delete[] sortedArray;
    }
    system("pause");
    myfile.close();
    return 0;
}

