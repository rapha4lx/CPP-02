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

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;

    Fixed operator-(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++();    //Pre increment
    Fixed operator++(int);  //Increment before
    Fixed &operator--();    //Pre increment
    Fixed operator--(int);  //Increment before

    Fixed &operator=(const Fixed &other);
    
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);

    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    
    
    friend std::ostream &operator<<(std::ostream &out, const Fixed &right);
};

// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016