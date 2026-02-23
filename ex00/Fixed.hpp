#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    static const int fractionalBits;
    int fpn;

public:
    Fixed();
    Fixed(const Fixed &src);
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed &operator=(const Fixed &other);
};

#endif
