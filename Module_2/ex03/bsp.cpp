#include <Point.hpp>

Fixed abs(Fixed x)
{
	if (x < Fixed(0))
		return (x * Fixed(-1));
	return x;
}

Fixed areaTriangle(Point const a, Point const b, Point const c)
{
	// a = 1, b = 2, c = 3
	// Area = 0.5 * | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
	// Area = 0.5 * | a1 + a2 + a3 |
	Fixed a1 = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat());
	Fixed a2 = b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat());
	Fixed a3 = c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());

	return (Fixed(0.5f).toFloat() * abs(a1 + a2 + a3).toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = areaTriangle(a, b, c);
	Fixed area_1 = areaTriangle(a, b, point);
	Fixed area_2 = areaTriangle(a, point, c);
	Fixed area_3 = areaTriangle(point, b, c);

	if (area == (area_1 + area_2 + area_3))
		return true;
	return false;
}
