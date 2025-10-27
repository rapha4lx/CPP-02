#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fpn = 0;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fpn;
}

void Fixed::setRawBits(int const raw)
{
    this->fpn = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy Assignation operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
        // this->setRawBits((const_cast<Fixed &>(other)).getRawBits());
    return *this;
}