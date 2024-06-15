#include <iostream>
#include "move.h"

// Пример использования
int main() {
    double length, height, X, Y, flag = 1, X1, Y1;

    std::cout << "Enter Length and Height: ";
    std::cin >> length >> height;
    std::cout << "Enter X and Y: ";
    std::cin >> X >> Y;
    std::cout << std::endl;

    MovableRectangle rect(length, height, X, Y);
    rect.printParameters();

    std::cout << "On boundary: " << (rect.isPointOnBoundary(1, 0) ? "Yes" : "No") << std::endl;
    std::cout << "Intersects X: " << (rect.intersectsX() ? "Yes" : "No") << std::endl;
    std::cout << "Intersects Y: " << (rect.intersectsY() ? "Yes" : "No") << std::endl;


    while (flag != 0)
    {
        std::cout << "1. Show infortion" << std::endl << "2. New place of point" << std::endl << "3. Move point" << std::endl;
        std::cout << "4. Reset position" << std::endl << "0. Exit" << std::endl;
        std::cin >> flag;
        if (flag == 0) break;
        else if (flag == 1)
        {
            
            rect.printParameters();
            std::cout << "On boundary: " << (rect.isPointOnBoundary(1, 0) ? "Yes" : "No") << std::endl;
            std::cout << "Intersects X: " << (rect.intersectsX() ? "Yes" : "No") << std::endl;
            std::cout << "Intersects Y: " << (rect.intersectsY() ? "Yes" : "No") << std::endl;
        } 
        else if (flag == 2)
        {
            // Перемещение в новую точку
            std::cout << "Enter X and Y: " << std::endl;
            std::cin >> X >> Y;
            rect.move(X, Y);
            std::cout << "After moving to (" << X << ", " << Y << ")" << std::endl;
            rect.printParameters();
        }
        else if (flag == 3)
        {
            // Перемещение на заданное смещение
            std::cout << "Enter X and Y: " << std::endl;
            std::cin >> X1 >> Y1;
            rect.move(X + X1, Y + Y1);
            std::cout << "After moving to (" << X1 << ", " << Y1 << ")" << std::endl;
            rect.printParameters();
        }
        else if (flag == 4)
        {
            // Сброс в первоначальное положение
            rect.resetPosition();
            std::cout << "After resetting to original position:\n";
            rect.printParameters();
        }
        
    }
    return 0;
}
