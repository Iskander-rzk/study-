#include <iostream>
#include <string>


//По значению:
/**
 * @brief convertToBase конвертирует число в указаную систему счисления
 * 
 * @param num число которое нужно преоброзовать 
 * @param base система счисления в которую преобразуют
 * @param res представление числа в n-ичной системе счисления
 * @return std::string 
 */
std::string convertToBase(int num, int base) {
    std::string res = "";
    while (num > 0) {
        int rem = num % base;
        res = std::to_string(rem) + res;
        num /= base;
    }
    return res;
}

int main() {
    int num, base;
    std::cout << "Enter the decimal number: ";
    std::cin >> num;
    std::cout << "Enter the base of the new number system: ";
    std::cin >> base;
    std::cout << "The number " << num << " in base " << base << " is " << convertToBase(num, base) << std::endl;
    return 0;
}


//По ссылке:
/*//
void convertToBase(int num, int base, std::string& res) {
    while (num > 0) {
        int rem = num % base;
        res = std::to_string(rem) + res;
        num /= base;
    }
}

int main() {
    int num, base;
    std::string result = "";
    std::cout << "Enter the decimal number: ";
    std::cin >> num;
    std::cout << "Enter the base of the new number system: ";
    std::cin >> base;
    convertToBase(num, base, result);
    std::cout << "The number " << num << " in base " << base << " is " << result << std::endl;
    return 0;
}


//Через указатель:

void convertToBase(int num, int base, std::string* res) {
    while (num > 0) {
        int rem = num % base;
        *res = std::to_string(rem) + *res;
        num /= base;
    }
}

int main() {
    int num, base;
    std::string result = "";
    std::cout << "Enter the decimal number: ";
    std::cin >> num;
    std::cout << "Enter the base of the new number system: ";
    std::cin >> base;
    convertToBase(num, base, &result);
    std::cout << "The number " << num << " in base " << base << " is " << result << std::endl;
    return 0;
}
//*/ 