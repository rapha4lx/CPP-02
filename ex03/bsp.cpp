#include "Point.hpp"

static Fixed sign(const Point &p1, const Point &p2, const Point &p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
         - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    // Point on an edge or vertex is considered outside
    Fixed zero(0);
    if (d1 == zero || d2 == zero || d3 == zero)
        return false;

    bool hasNeg = (d1 < zero) || (d2 < zero) || (d3 < zero);
    bool hasPos = (d1 > zero) || (d2 > zero) || (d3 > zero);

    return !(hasNeg && hasPos);
}

