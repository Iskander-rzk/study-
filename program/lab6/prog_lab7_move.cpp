#include <iostream>
#include "move.h"

MovableRectangle::MovableRectangle(double l, double h, double cX, double cY): Rectangle(l, h, cX, cY), original_X(cX), original_Y(cY) {}


void MovableRectangle::move(double new_X, double new_Y) {
        X = new_X;
        Y = new_Y;
    }
void MovableRectangle::resetPosition() {
        X = original_X;
        Y = original_Y;
    }

    

