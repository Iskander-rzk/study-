#include <iostream>
#include <string>
#include <vector>

int main() {
    const int N = 10;  
    int massive[N];
    std::cout << "Enter array: ";
	for (int i = 0; i < N; i++)
    {
        std::cin >> massive[i];
    }

    int flag = 0;
    std::vector<int> new_massive;
    for (int i = 0; i < N; i++)
    {
        if (massive[i] == 0)
        {
            new_massive.push_back(massive[i]);
            flag++;
        }
        else if (flag == 0 || flag == 2 ) new_massive.push_back(massive[i]);
    }
	
    
    //Вывод всех элементов матрицы на экран построчно
    std::cout << "New array: ";
    for (int a = 0; a < new_massive.size(); a++) std::cout << new_massive[a] << "  ";
	return 0;
}