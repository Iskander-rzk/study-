#include <iostream>
#include <vector>

/**
 * @brief 
 * @param N, M колличество строк и столбцов матрицы
 * @param max1, max2 максимальный элемент в строке матрицы
 * @param
 * @return int 
 */


int main() {
    int N, M;
    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> N >> M;

    // Ввод матрицы
    std::vector<std::vector<int>> matrix(N, std::vector<int>(M));
    std::cout << "Enter matrix elements:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << "Line " << i + 1 << ": ";
        for (int j = 0; j < M; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Сортировка строк матрицы по наибольшим элементам с использованием "пузырьковой" сортировки
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            // Находим максимальные элементы в сравниваемых строках
            int max1 = matrix[j][0];
            for (int k = 1; k < M; k++) {
                if (matrix[j][k] > max1) {
                    max1 = matrix[j][k];
                }
            }

            int max2 = matrix[j + 1][0];
            for (int k = 1; k < M; k++) {
                if (matrix[j + 1][k] > max2) {
                    max2 = matrix[j + 1][k];
                }
            }

            // Если максимальный элемент в первой строке больше, чем во второй, меняем строки местами
            if (max1 > max2) {
                std::swap(matrix[j], matrix[j + 1]);
            }
        }
    }

    // Вывод отсортированной матрицы
    std::cout << "Sorted matrix:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
