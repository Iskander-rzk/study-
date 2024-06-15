#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(double l, double h, double cX, double cY) : length(l), height(h), X(cX), Y(cY) {}

void Rectangle::printParameters() const {
        std::cout << "length: " << length << ", Height: " << height
                  << ", Center: (" << X << ", " << Y << ")\n";
    }

bool Rectangle::isPointOnBoundary(double x, double y) const {
        double half_length = length / 2;
        double half_height = height / 2;
        
        double left = X - half_length;
        double right = X + half_length;
        double top = Y + half_height;
        double bottom = Y - half_height;
        
        bool on_left_or_right = (x == left || x == right) && (bottom <= y && y <= top);
        bool on_top_or_bottom = (y == top || y == bottom) && (left <= x && x <= right);
        
        return on_left_or_right || on_top_or_bottom;
    }

bool Rectangle::intersectsX() const {
        double half_height = height / 2;
        double top = Y + half_height;
        double bottom = Y - half_height;
        return bottom <= 0 && 0 <= top;
    }

bool Rectangle::intersectsY() const {
        double half_length = length / 2;
        double left = X - half_length;
        double right = X + half_length;
        return left <= 0 && 0 <= right;
    }

