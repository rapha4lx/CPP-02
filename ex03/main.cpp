#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(3.0f, 3.0f);
    Point outside(10.0f, 10.0f);
    Point onEdge(5.0f, 0.0f);

    std::cout << std::boolalpha;
    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "On edge: " << bsp(a, b, c, onEdge) << std::endl;

    return 0;
}

