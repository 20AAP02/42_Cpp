#include <Point.hpp>

Point::Point(): x(0), y(0) {}

Point::Point(const float x1, const float y1): x(x1), y(y1) {}

Point::Point(const Point &P): x(P.getX().toFloat()), y(P.getY().toFloat()) {}

Point Point::operator=(const Point &P) { return P; }

Point::~Point() {}

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }
