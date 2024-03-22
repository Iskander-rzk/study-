#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <ctime>

int countn{ 0 };
int countn{ 0 };

int randA()
{
    int N = 0;
    int* R = new int[N];
    std::random_device rd; // Используем генератор случайных чисел
    std::mt19937 gen(rd()); // Создаем генератор случайных чисел на основе seed
    std::uniform_int_distribution<int> dist(1, 100000); // Определение диапазона случайных чисел
    N = dist(gen);

    return N;
}

int randNumber()
{
    int N = 10000;
    int* A = new int[N];
    std::random_device rd; // Используем генератор случайных чисел
    std::mt19937 gen(rd()); // Создаем генератор случайных чисел на основе seed
    std::uniform_int_distribution<int> dist(1, 100000); // Определение диапазона случайных чисел
    N = dist(gen);
    return N;
}



void calculateExpressions(std::string digits, int target, std::string expr, long currResult, long prevNum, int pos, std::vector<std::string>& result) {
    if (pos == digits.size()) {
        countn++;
        if (currResult == target) {
            countn += 2;
            result.push_back(expr);
        }
        countn++;
        return;
    }

    for (int i = pos; i < digits.size(); i++) {
        std::string numStr = digits.substr(pos, i - pos + 1);
        long num = std::stol(numStr);
        countn += 6;

        if (pos == 0) {
            calculateExpressions(digits, target, numStr, num, num, i + 1, result);
            countn += 2;
        }
        else {
            calculateExpressions(digits, target, expr + "+" + numStr, currResult + num, num, i + 1, result);
            calculateExpressions(digits, target, expr + "-" + numStr, currResult - num, -num, i + 1, result);
            calculateExpressions(digits, target, expr + "*" + numStr, currResult - prevNum + prevNum * num, prevNum * num, i + 1, result);
            countn += 3;
        }

        if (num == 0) countn += 2; break;  // Не рассматривать ведущие нули (т.к. операции с ними не имеют смысла)
    }
    countn++;
}


int main(int R, int* A)
{
    std::ofstream myfile;
    myfile.open("alg3.csv");
    myfile << "timeRand;operRand;timeBest;operBest;timeWorst;operWorst\n";

    std::string digits;
    int target;
    unsigned int start_time = clock();
    unsigned int end_time = clock();
    for (int i = 0; i <= 100; i++)
    {
        std::vector<std::string> result;
        calculateExpressions(std::to_string(randA()), randNumber(), "", 0, 0, 0, result);
        end_time = clock();
        myfile << end_time - start_time;
        myfile << ";";
        myfile << countn;
        myfile << ";";
        countn = 0;

        calculateExpressions("0", 0, "", 0, 0, 0, result);
        end_time = clock();
        myfile << end_time - start_time;
        myfile << ";";
        myfile << countn;
        myfile << ";";
        countn = 0;

        calculateExpressions("999999", 0, "", 0, 0, 0, result);
        end_time = clock();
        myfile << end_time - start_time;
        myfile << ";";
        myfile << countn;
        myfile << "\n";
        countn = 0;
    }

    return 0;
}
