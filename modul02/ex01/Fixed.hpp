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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat( void ) const;
		int toInt( void ) const;
};

	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
