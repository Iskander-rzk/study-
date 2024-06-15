#include <iostream>

class Rectangle {
protected:
    double length, height;
    double X, Y;

public:
    // Конструктор с полным набором параметров
    Rectangle(double l, double h, double cX, double cY)
        : length(l), height(h), X(cX), Y(cY) {}

    // Функция вывода значений параметров, задающих фигуру
    void printParameters() const ;

    // Функция, возвращающая 1 (истина), если указанная точка принадлежит границе фигуры
    bool isPointOnBoundary(double x, double y) const; 

    // Функция, возвращающая 1, если объект пересекает ось абсцисс
    bool intersectsX() const ;

   
    bool intersectsY() const ;
};
