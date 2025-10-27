#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) :
    value(value * int(1 << this->fractional) + int(value >= 0 ? 0.5 : -0.5))
{
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : 
    value(value * float(1 << this->fractional) + float(value >= 0 ? 0.5 : -0.5))
{
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor Called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return float(this->value) / float(1 << this->fractional);
}

int Fixed::toInt(void) const
{
    return int(this->value) / int(1 << this->fractional);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const 
{
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const 
{
    return (this->toFloat() <= other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return this->toFloat() + other.toFloat();
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return this->toFloat() - other.toFloat();
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return this->toFloat() * other.toFloat();
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return this->toFloat() / other.toFloat();
}

Fixed &Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed &Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->value--;
    return tmp;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy Assignation operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &right)
{
    out << right.toFloat();
    return out;
}
