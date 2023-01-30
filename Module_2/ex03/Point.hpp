#ifndef POINT_HPP
# define POINT__HPP

# include <Fixed.hpp>

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float x1, const float y1);
	Point(const Point &P);
	Point operator=(const Point &P);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif