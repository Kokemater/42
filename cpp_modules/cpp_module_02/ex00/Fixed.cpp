#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
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