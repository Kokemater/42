#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    Fixed();                                // constructor
    Fixed(const int fixedPointValue);
    Fixed(const float fixedPointValue);
    Fixed(const Fixed &other);              // copy constructor
    Fixed& operator=(const Fixed &other);    // copy assignment operator
    ~Fixed();                               // destructor
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif