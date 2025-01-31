#include "Fixed.hpp"

int main( void )
{

	//Fixed a;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;


    std::cout << "*********************************************" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    Fixed e;
    e = Fixed(5.05f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "e is " << e << std::endl;


    std::cout << "b as integer is " << b.toInt() << std::endl;
    std::cout << "c as float is " << c.toFloat() << std::endl;


    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "c > b: " << (c > b) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b >= e: " << (b >= e) << std::endl;
    std::cout << "a == a: " << (a == a) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;


    Fixed sum = b + c;
    Fixed diff = c - b;
    Fixed prod = b * c;
    Fixed quot = c / b;

    std::cout << "b + c: " << sum << std::endl;
    std::cout << "c - b: " << diff << std::endl;
    std::cout << "b * c: " << prod << std::endl;
    std::cout << "c / b: " << quot << std::endl;


    std::cout << "e before increment: " << e << std::endl;
    std::cout << "++e: " << ++e << std::endl;
    std::cout << "e++: " << e++ << std::endl;
    std::cout << "e after increment: " << e << std::endl;

    std::cout << "e before decrement: " << e << std::endl;
    std::cout << "--e: " << --e << std::endl;
    std::cout << "e--: " << e-- << std::endl;
    std::cout << "e after decrement: " << e << std::endl;


    std::cout << "min between b and c: " << Fixed::min(b, c) << std::endl;
    std::cout << "max between b and c: " << Fixed::max(b, c) << std::endl;

    std::cout << "*********************************************" << std::endl;
    //Fixed a;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a + b << std::endl;
	//std::cout << a - b << std::endl;
	//std::cout << a * b << std::endl;
	//std::cout << a / b << std::endl;
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << (a > b) << std::endl;
	//std::cout << (a < b) << std::endl;
	//std::cout << (a >= b) << std::endl;
	//std::cout << (a <= b) << std::endl;
	//std::cout << (a == b) << std::endl;
	//std::cout << (a != b) << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;
	//std::cout << Fixed::min( a, b ) << std::endl;
	//Fixed c(42);
	//Fixed& result = Fixed::min(a, c);
	//result.setRawBits(22);



	return 0;
}
