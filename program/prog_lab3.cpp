#include <iostream>
#include <string>

int main() {
    const int N = 10;  
	int massive[N];
	//заполняем элементы матрицы с клавиатуры построчно
	int i, j;
	for (i = 0; i < N; i++)
    {
        std::cin >> massive[i];
    }

    int flag = 0, pause = 0;
    int* new_massive = new int[];
    for (i = 0; i < N; i++)
    {
        if (massive[i] != 0) new_massive[i-pause] = massive[i], flag++;
        else if (flag == 0 or flag == 2 ) new_massive[i-pause] = massive[i];
        else pause++;
    }
	
    
    //Вывод всех элементов матрицы на экран построчно
    for (int a = 0; a < N; a++) std::cout << new_massive[a] << "  ";
	return 0;
}