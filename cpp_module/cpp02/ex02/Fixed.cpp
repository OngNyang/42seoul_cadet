#include "Fixed.hpp"

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

int		Fixed::getRawBits(void) const
{
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

Fixed&	Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->fixed_point_num_val = obj.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(const Fixed& obj) const
{
	return (this->fixed_point_num_val > obj.fixed_point_num_val);
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return (this->fixed_point_num_val < obj.fixed_point_num_val);
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return (this->fixed_point_num_val >= obj.fixed_point_num_val);
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return (this->fixed_point_num_val <= obj.fixed_point_num_val);
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return (this->fixed_point_num_val == obj.fixed_point_num_val);
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return (this->fixed_point_num_val != obj.fixed_point_num_val);
}

Fixed	Fixed::operator+(const Fixed& obj) const
{
	int		sum = this->getRawBits() + obj.getRawBits();
	Fixed	result;

	result.setRawBits(sum);
	return (result);
}