#include <iostream>

class Fixed
{
private:
    static const int fractional = 8;
    int value;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);


    float toFloat(void) const;
    int toInt(void) const;

    Fixed &operator=(const Fixed &other);
    friend std::ostream &operator<<(std::ostream &out, const Fixed &right);
};


// Default constructor called
// Int constructor called
// Float constructor called
// Copy constructor called
// Copy assignment operator called
// Float constructor called
// Copy assignment operator called
// Destructor called
// a is 1234.43
// b is 10
// c is 42.4219
// d is 10
// a is 1234 as integer
// b is 10 as integer
// c is 42 as integer
// d is 10 as integer
// Destructor called
// Destructor called
// Destructor called
// Destructor called