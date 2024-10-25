#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int* shannonFanoCoding(double chance);

void shannonFanoCoding(double chance[])
{
     double totalSum = 0;
    for (int i = 0; i <= 8; i++) {
        totalSum += chance[i];
    }

    // Поиск индекса для разделения символов
    double halfSum = 0;
    int splitIndex = 0;
    for (int i = 0; i <= 8; i++) {
        halfSum += chance[i];
        if (halfSum >= totalSum / 2) {
            splitIndex = i;
            break;
        }
    }

    // Присваиваем коды символам
    for (int i = 0; i <= splitIndex; i++) {
        chance[i] += "0";
    }
    for (int i = splitIndex + 1; i <= 8; i++) {
        symbols[i] += "1";
    }

    // Рекурсивно обрабатываем две части
    shannonFano(symbols, 0, splitIndex);
    shannonFano(symbols, splitIndex + 1, 8);
}

// Структура для хранения символа и его вероятности
struct Symbol {
    char character;
    double probability;
    string code;
};

// Функция для сортировки символов по вероятности (в порядке убывания)
bool compare(Symbol a, Symbol b) {
    return a.probability > b.probability;
}

// Функция для кодирования Шеннона-Фано
void shannonFano(vector<Symbol>& symbols, int start, int end) {
    if (start >= end) return;

    // Вычисляем суммарные вероятности
    double totalSum = 0;
    for (int i = start; i <= end; i++) {
        totalSum += symbols[i].probability;
    }

    // Поиск индекса для разделения символов
    double halfSum = 0;
    int splitIndex = start;
    for (int i = start; i <= end; i++) {
        halfSum += symbols[i].probability;
        if (halfSum >= totalSum / 2) {
            splitIndex = i;
            break;
        }
    }

    // Присваиваем коды символам
    for (int i = start; i <= splitIndex; i++) {
        symbols[i].code += "0";
    }
    for (int i = splitIndex + 1; i <= end; i++) {
        symbols[i].code += "1";
    }

    // Рекурсивно обрабатываем две части
    shannonFano(symbols, start, splitIndex);
    shannonFano(symbols, splitIndex + 1, end);
}

int main() {
    // Предопределенные символы и их вероятности
    vector<Symbol> symbols = {
        {'A', 0.4, ""},
        {'B', 0.3, ""},
        {'C', 0.15, ""},
        {'D', 0.1, ""},
        {'E', 0.05, ""}
    };

    // Сортируем символы по вероятности
    sort(symbols.begin(), symbols.end(), compare);

    // Запускаем алгоритм Шеннона-Фано
    shannonFano(symbols, 0, symbols.size() - 1);

    // Выводим результат
    cout << "\nСимволы и их коды Шеннона-Фано:\n";
    for (const auto& symbol : symbols) {
        cout << symbol.character << ": " << symbol.code << endl;
    }

    return 0;
}
