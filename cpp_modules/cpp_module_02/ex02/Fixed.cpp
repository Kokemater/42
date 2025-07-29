#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

Fixed::Fixed(const int fixedPointValue)
{
    std::cout << "Int constructor called" << std::endl;
    int scale = 1 << fractionalBits;
    float newVal = fixedPointValue * scale;
    this->fixedPointValue = (int) newVal;
}

Fixed::Fixed(const float fixedPointValue)
{
    std::cout << "Float constructor called" << std::endl;
    int scale = 1 << fractionalBits;
    float newVal = fixedPointValue * scale;
    this->fixedPointValue = (int) newVal;
}

Fixed::Fixed(const Fixed &other)
{
    
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std:: cout << "Copy assignment operator called" << std::endl;
    if (this == &other) 
        return *this;
    this->fixedPointValue = other.fixedPointValue;
    return (*this);  
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return (this->fixedPointValue);
}
void Fixed::setRawBits( int const raw )
{
    this->fixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    float scale = 1 << fractionalBits;
    return ((float) this->fixedPointValue / scale);
}

int Fixed::toInt( void ) const
{
    return ((int) toFloat());
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->fixedPointValue + other.fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->fixedPointValue - other.fixedPointValue);
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->fixedPointValue * other.fixedPointValue);
    return result;
}
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->fixedPointValue / other.fixedPointValue);
    return result;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed& Fixed::operator++()
{
    this->fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return (temp);
}