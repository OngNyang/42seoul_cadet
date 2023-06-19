#include "Fixed.hpp"

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	// int	n = -2147483648;
	int	n = 2147483647;
	a = Fixed(n);
	std::cout << a << std::endl;

	// a = Fixed( 1234.4321f );

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// return 0;
}
