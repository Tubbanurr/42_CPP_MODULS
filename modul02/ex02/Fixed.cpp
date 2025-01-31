#include "Fixed.hpp"
# include <cmath>

Fixed::Fixed() : _fixPntValue(0){}

Fixed::Fixed(const int &intValue)
{
	_fixPntValue = intValue << _fractionalBits;
}
Fixed::Fixed(const float &floatValue)
{
	_fixPntValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}
Fixed::~Fixed(){}

Fixed &Fixed::operator=(const Fixed &copy)
{
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


bool Fixed::operator>(const Fixed& other) const
{
    return _fixPntValue > other._fixPntValue;
}
bool Fixed::operator<(const Fixed& other) const
{
    return _fixPntValue < other._fixPntValue;
}
bool Fixed::operator>=(const Fixed& other) const
{
    return _fixPntValue >= other._fixPntValue;
}
bool Fixed::operator<=(const Fixed& other) const
{
    return _fixPntValue <= other._fixPntValue;
}
bool Fixed::operator==(const Fixed& other) const
{
    return _fixPntValue == other._fixPntValue;
}
bool Fixed::operator!=(const Fixed& other) const
{
    return _fixPntValue != other._fixPntValue;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    _fixPntValue++;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}
Fixed& Fixed::operator--()
{
    _fixPntValue--;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
