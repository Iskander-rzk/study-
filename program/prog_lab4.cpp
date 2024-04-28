#include <iostream>
#include <vector>

/**
 * @brief 
 * 
 * @param N 
 * @param M 
 * @return std::vector<std::vector<int>> 
 */
 

std::vector<std::vector<int>> enter(int N, int M) 
{
    std::vector<std::vector<int>> matrix;
    std::cout << "Enter matrix elements:" << std::endl;
    int a;

    for (int i = 0; i < N; i++) 
    {
        std::vector<int> row;
        for (int j = 0; j < M; j++)
        {
            std::cin >> a;
            row.push_back(a);
        }
        matrix.push_back(row);
    }

    return matrix;
}

std::vector<std::vector<int>> sort_matrix(std::vector<std::vector<int>>& matrix, int N, int M)
{
    
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
    return matrix;
    
}

void print(std::vector<std::vector<int>>& matrix, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    int N, M;
    // Ввод матрицы
    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> N >> M;
    std::vector<std::vector<int>> matr = enter(N, M);

     // Сортировка матрицы
    std::vector<std::vector<int>> matrix = sort_matrix(matr, N, M);

    // Вывод отсортированной матрицы
    std::cout << "Sorted matrix:" << std::endl;
    print(matrix, N, M);

    return 0;
}
