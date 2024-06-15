#include "rectangle.h"


class MovableRectangle : public Rectangle {
private:
    double original_X, original_Y;

public:
    // Конструктор с запоминанием первоначального положения
    MovableRectangle(double l, double h, double cX, double cY)
        : Rectangle(l, h, cX, cY), original_X(cX), original_Y(cY) {}

    // Функция перемещения центра в новую точку
    void move(double new_X, double new_Y) {
        X = new_X;
        Y = new_Y;
    }

    // Функция сброса в первоначальное положение
    void resetPosition() {
        X = original_X;
        Y = original_Y;
    }
};
