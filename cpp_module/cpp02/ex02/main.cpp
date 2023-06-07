#include "Fixed.hpp"

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

int main( void )
{
	// Fixed	a(10.2f);
	// Fixed	b(3.8f);

	// std::cout << "a+b = " << (a + b) << std::endl;
	// std::cout << "a-b = " << (a - b) << std::endl;
	// std::cout << "a*b = " << (a * b) << std::endl;
	// std::cout << "a/b = " << (a / b) << std::endl;

	// std::cout << (a++) << std::endl;
	// std::cout << (a) << std::endl;
	// std::cout << (b) << std::endl;
	// std::cout << (++b) << std::endl;

	// std::cout << (a--) << std::endl;
	// std::cout << (a) << std::endl;
	// std::cout << (b) << std::endl;
	// std::cout << (--b) << std::endl;

	// std::cout << "min(a,b) = " << Fixed::min(a, b) << std::endl;
	// const Fixed	c(10.2f);
	// const Fixed	d(3.8f);
	// std::cout << "const__min(c,d) = " << Fixed::min(c, d) << std::endl;
	// std::cout << "max(a,b) = " << Fixed::max(a, b) << std::endl;
	// std::cout << "const__max(c,d) = " << Fixed::max(c, d) << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}