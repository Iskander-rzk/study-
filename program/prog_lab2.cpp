#include <iostream>
#include <string>

int main() {
	//Объявление двумерного массива
    const int N = 5, M = 4;	
	int massive[N][M];
	//заполняем элементы матрицы с клавиатуры построчно
	int i, j;
	for (i = 0; i < N; i++)
    {
        std::cout << "Enter the line: ";
		for (j = 0; j < M; j++){
            std::cin >> massive[i][j];
        }
    }    
	/*/
    int massive[N][M] = {
        {2, 7, -3, 0},
        {76, 3, -5, -4},
        {-4, -5, 7, 1},
        {31, 53, 6, 2},
        {-2, -65, -6, -4}
    };
    /*/
	//обрабатываем введеные данные 
    int n = 0;
	for (i = 0; i < N; i++) {  //внешний цикл отвечает за перебор строк
        if(i % 2 != 1) continue;
        for (j = 0; j < M; j++)  
        {
            if (massive[i][j] <= 0) n += massive[i][j];
        }
        massive[i][0] = n;
        n = 0;
	}
    
    
    //Вывод всех элементов матрицы на экран построчно
    for (int a = 0; a < N; a++) std::cout << massive[a][0] << "  ";
	return 0;
}