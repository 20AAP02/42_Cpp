#include <Point.hpp>

Point::Point()
{
	x.setRawBits(0);
	y.setRawBits(0);
}

Point::Point(const float x1, const float y1)
{
	this->x = Fixed(x1);
	this->y = Fixed(y1);
}

Point::Point(const Point &P)
{
	x.setRawBits(P.x.getRawBits());
	y.setRawBits(P.y.getRawBits());
}

void Point::operator=(const Point &P)
{
	x.setRawBits(P.x.getRawBits());
	y.setRawBits(P.y.getRawBits());
}

Point::~Point()
{
}
