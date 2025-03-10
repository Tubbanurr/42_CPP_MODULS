#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixPntValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(const int &intValue);
		Fixed(const float &floatValue);
		Fixed(const Fixed &copy);
		Fixed();
		~Fixed();

		Fixed &operator=(const Fixed &copy);

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat( void ) const;
		int toInt( void ) const;

};

	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
