#ifndef POINT_HPP
# define POINT__HPP

# include <Fixed.hpp>

class Point
{
private:
	Fixed x;
	Fixed y;

public:
	Point();
	Point(const float x1, const float y1);
	Point(const Point &P);
	void operator=(const Point &P);
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif