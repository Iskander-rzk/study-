#include "rectangle.h"


class MovableRectangle : public Rectangle {
protected:
    double original_X, original_Y;

public:
    // Конструктор с запоминанием первоначального положения
    MovableRectangle(double l, double h, double cX, double cY);

    // Функция перемещения центра в новую точку
    void move(double new_X, double new_Y) ;
    // Функция сброса в первоначальное положение
    void resetPosition() ;
};
