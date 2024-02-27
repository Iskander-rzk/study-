#include <iostream>
#include <string>
#include <vector>

void calculateExpressions(std::string digits, int target, std::string expr, long currResult, long prevNum, int pos, std::vector<std::string>& result) {
    if (pos == digits.size()) {
        if (currResult == target) {
            result.push_back(expr);
        }
        return;
    }

    for (int i = pos; i < digits.size(); i++) {
        std::string numStr = digits.substr(pos, i - pos + 1);
        long num = std::stol(numStr);

        if (pos == 0) {
            calculateExpressions(digits, target, numStr, num, num, i + 1, result);
        } else {
            calculateExpressions(digits, target, expr + "+" + numStr, currResult + num, num, i + 1, result);
            calculateExpressions(digits, target, expr + "-" + numStr, currResult - num, -num, i + 1, result);
            calculateExpressions(digits, target, expr + "*" + numStr, currResult - prevNum + prevNum * num, prevNum * num, i + 1, result);
        }

        if (num == 0) break;  // Не рассматривать ведущие нули (т.к. операции с ними не имеют смысла)
    }
}

int main() {
    std::string digits;
    int target;

    std::cout << "Введите строку из цифр: ";
    std::cin >> digits;
    std::cout << "Введите целевое значение: ";
    std::cin >> target;

    std::vector<std::string> result;
    calculateExpressions(digits, target, "", 0, 0, 0, result);

    if (result.empty()) {
        std::cout << "Нет возможных выражений для достижения целевого значения." << std::endl;
    } else {
        std::cout << "Возможные выражения для достижения целевого значения:" << std::endl;
        for (const std::string& expr : result) {
            std::cout << expr << std::endl;
        }
    }

    return 0;
}
