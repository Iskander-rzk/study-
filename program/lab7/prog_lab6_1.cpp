#include <iostream>
#include "rectangle.h"



// Пример использования
int main1() {
    int length, high, X, Y, flag = 1;
    std::cout << "Enter Length and high: " << std::endl;
    std::cin >> length >> high;
    std::cout << "Enter X and Y: " << std::endl;
    std::cin >> X >> Y;
    std::cout << std::endl;
    Rectangle rect(length, high, X, Y);
    rect.printParameters();
    std::cout << "On boundary: " << (rect.isPointOnBoundary(2, 0) ? "Yes" : "No") << std::endl;
    std::cout << "Intersects X: " << (rect.intersectsX() ? "Yes" : "No") << std::endl;
    std::cout << "Intersects Y: " << (rect.intersectsY() ? "Yes" : "No") << std::endl;

    return 0;
}
