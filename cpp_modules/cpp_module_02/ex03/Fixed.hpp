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
    bool operator<(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed &operator++();    //pre
    Fixed operator++(int); //post
    Fixed &operator--();    //pre
    Fixed operator--(int); //post
    ~Fixed();                               // destructor
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b); // static
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif