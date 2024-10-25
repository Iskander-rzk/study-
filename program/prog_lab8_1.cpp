#include <iostream>
#include <vector>

int main() {
    int size;
    std::cout << "Size of order: "; //Вводим размер пследовательности
    std::cin >> size;
    
    // Вводим последовательность
    std::vector<int> sequence(size);
    std::cout << "Enter the sequence: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> sequence[i];
    }
    
    // Вводим числа B1, B2, B3
    int a, b, c;
    std::cout << "Enter 3 numbers: ";
    std::cin >> a >> b >> c;
    int B[3] = {a, b, c};  // Массив с элементами B1, B2, B3
    
    int zero_count = 0;    // Счетчик нулевых элементов
    int second_zero_index = -1;  // Индекс второго нуля
    
    // Находим индекс второго нуля
    for (int i = 0; i < sequence.size(); ++i) {
        if (sequence[i] == 0) {
            zero_count++;
            if (zero_count == 2) {
                second_zero_index = i;
                break;
            }
        }
    }
    
    // Проверяем, что нашли второй ноль
    if (second_zero_index != -1) {
        // Вставляем элементы B1, B2, B3 после второго нуля
        sequence.insert(sequence.begin() + second_zero_index + 1, B, B + 3);
        
        // Выводим результат
        std::cout << "Result: ";
        for (int num : sequence) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "There are no two zero elements in the order." << std::endl;
    }
    
    return 0;
}
