#include <iostream>
#include <iomanip>

// Функция для вывода побайтового представления переменной
void printBytes(const uint8_t* ptr, int size) {
    // Вывод в шестнадцатеричном формате
    std::cout << "Hexadecimal representation: ";
    for (int i = size - 1; i >= 0; --i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(ptr[i]) << " ";
    }
    std::cout << std::endl;

    // Вывод в двоичном формате
    std::cout << "Binary representation: ";
    for (int i = size - 1; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            std::cout << ((ptr[i] >> j) & 1);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Пример использования функции
    int intValue = 123456789;
    float floatValue = 3.14f;
    double doubleValue = 3.14159;

    std::cout << "Int value: " << intValue << std::endl;
    printBytes(reinterpret_cast<const uint8_t*>(&intValue), sizeof(int));

    std::cout << "\nFloat value: " << floatValue << std::endl;
    printBytes(reinterpret_cast<const uint8_t*>(&floatValue), sizeof(float));

    std::cout << "\nDouble value: " << doubleValue << std::endl;
    printBytes(reinterpret_cast<const uint8_t*>(&doubleValue), sizeof(double));

    return 0;
}
