

class Fixed
{
private:
    int fpn;

public:
    Fixed();
    Fixed(const Fixed &src);
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed &operator=(const Fixed &other);
};
