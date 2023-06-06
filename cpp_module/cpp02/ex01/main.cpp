// #include "Fixed.hpp"


#include <iostream>
#include <cmath>

class	Fixed
{
	private:
			int					fixed_point_num_val;
			static const int	num_fractional_bits = 8;
	public:
			Fixed(void);
			Fixed(const Fixed& obj);
			Fixed(const int n);
			Fixed(const float f);
			~Fixed(void);
			Fixed&	operator=(const Fixed& obj);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

};

Fixed::Fixed(void)
{
	this->fixed_point_num_val = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_num_val = obj.getRawBits();
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_num_val = n << this->num_fractional_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_num_val = roundf(f * (1 << this ->num_fractional_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->fixed_point_num_val = obj.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_num_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_num_val = raw;
}

float	Fixed::toFloat(void) const
{
	return ((static_cast<float>(this->fixed_point_num_val)) / (1 << this->num_fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->fixed_point_num_val >> this->num_fractional_bits);
}
std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
    out << obj.toFloat();
    return out;
}


int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}


// Fixed::Fixed(void)
// {
// 	this->fixed_point_num_val = 0;
// 	std::cout << "Default constructor called" << std::endl;
// }

// Fixed::Fixed(const Fixed& obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
// 	this->fixed_point_num_val = obj.getRawBits();
// }

// Fixed::Fixed(const int n)
// {
// 	std::cout << "Int constructor called" << std::endl;
// 	this->fixed_point_num_val = n << this->num_fractional_bits;
// }

// Fixed::Fixed(const float f)
// {
// 	std::cout << "Float constructor called" << std::endl;
// 	this->fixed_point_num_val = roundf(f * (1 << this ->num_fractional_bits));
// }

// Fixed::~Fixed(void)
// {
// 	std::cout << "Destructor called" << std::endl;
// }

// Fixed& Fixed::operator=(const Fixed& obj)
// {
// 	std::cout << "Copy assignment operator called" << std::endl;
// 	if (this != &obj)
// 	{
// 		this->fixed_point_num_val = obj.getRawBits();
// 	}
// 	return (*this);
// }

// int		Fixed::getRawBits(void) const
// {
// 	std::cout << "getRawBits member function called" << std::endl;
// 	return (this->fixed_point_num_val);
// }

// void	Fixed::setRawBits(int const raw)
// {
// 	this->fixed_point_num_val = raw;
// }

// float	Fixed::toFloat(void) const
// {
// 	return ((static_cast<float>(this->fixed_point_num_val)) / (1 << this->num_fractional_bits));
// }

// int		Fixed::toInt(void) const
// {
// 	return (this->fixed_point_num_val >> this->num_fractional_bits);
// }

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );

// 	a = Fixed( 1234.4321f );

// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;

// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	return 0;
// }
