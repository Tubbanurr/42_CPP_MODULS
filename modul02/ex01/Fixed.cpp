#include "Fixed.hpp"
# include <cmath>

Fixed::Fixed() : _fixPntValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_fixPntValue = intValue << _fractionalBits;
}
Fixed::Fixed(const float &floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_fixPntValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
        this->_fixPntValue = copy.getRawBits();
    return *this;
}

int	Fixed::getRawBits(void) const
{
	return (_fixPntValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixPntValue = raw;
}
float	Fixed::toFloat( void ) const
{
	return static_cast<float>(_fixPntValue) / (1 << _fractionalBits);
}

int	Fixed::toInt( void ) const
{
	return _fixPntValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
