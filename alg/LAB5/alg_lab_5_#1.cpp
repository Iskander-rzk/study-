#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>
#include <math.h>
#include <typeinfo>
int main()
{
    float num;
    long long1, longValue;
    std::cout << "Введите число Float в десятичной системе счисления: ";
    std::cin >> num;
    std::cout << "Введите число Long в десятичной системе счисления: ";
    std::cin >> long1;
    union {         //позволяет хранить разные типы данных в одном и том же месте памяти 
        float d;
        long long u;
    } conversion;

    conversion.d = num;

    std::bitset<sizeof(float) * 8> binary(conversion.u);
    std::string binaryStr = binary.to_string();         //для вывода в 2СС

        // разбиваем число на знак, мантиссу и экспоненту
    std::bitset<64> bits(*reinterpret_cast<unsigned long long*>(&num));

    long sign = bits[63] ? '-' : '+';           // определение знака 

    std::string mantissa_str = bits.to_string().substr(12, 52);         //извлечение мантиссы числа и преобразование в строку
    float mantissa = std::stod(mantissa_str);

    std::string a = "01";
    float nn = 1.0;
    float temp = 0.0;
    int i = 0;
    for (long digit : mantissa_str)         //поочередно берется каждый элемент последовательности символов digits
    {
                // в строке а выбирается элемент digit и сохраняется в value
        temp += a.find(digit) * pow(2, -(i + 1));
        i++;
    }

    nn += temp;
    std::string true_mantissa_str = bits.to_string().substr(8, 23);
    float true_mantissa = std::stod(mantissa_str);
    std::string exponent = binaryStr.substr(11, 52);
    long long int value, power = 0;

    for (long digit : exponent)
    {
        value = a.find(digit);
        power = power * 2 + value;
    }
    power = power - 1023;
    float number_10 = nn * std::pow(2, power);
    long sign1 = bits[63] ? '-' : ' ';
    std::cout << "Binary  = " << binaryStr << std::endl;
    std::cout << "Знак  " << sign << " (" << (sign == '+' ? "положительное число" : "отрицательное число") << ")" << std::endl;
    std::cout << "Мантисса = " << mantissa_str << std::endl;
    std::cout << "Настоящая мантисса = 1. + " << true_mantissa_str << std::endl;
    std::cout << "Степень = " << exponent << std::endl;
    std::cout << "Настоящая степень = " << exponent << " - 11 1111 1111" << std::endl;
    std::cout << std::fixed << std::setprecision(19);
    std::cout << "Число 10СС  = " << sign1 << number_10 << std::endl;    

    std::cout << "float занимает байт: " << sizeof(float) << std::endl;
    std::cout << "long занимает байт: " << sizeof(long) << std::endl;

            //перевод ushort в двоичное представление
    std::bitset<sizeof(long) * 8> bitsic(long1);
    std::cout << "Long в двоичном виде: " << bitsic.to_string() << std::endl;
    return 0;
}
