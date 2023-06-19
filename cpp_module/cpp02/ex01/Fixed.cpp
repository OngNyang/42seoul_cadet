#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixed_point_num_val = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		std::cout << "Copy constructor called" << std::endl;
		this->fixed_point_num_val = obj.getRawBits();
	}
}

Fixed::Fixed(const int n)
{
	// int	sign_bit = n & (1U << 31);

	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_num_val = n << this->num_fractional_bits;
	// this->fixed_point_num_val = (this->fixed_point_num_val & ~(1U << 31)) | sign_bit;
}

Fixed::Fixed(const float f)
{
	// int	sign_bit;
	// if (f >= 0)
	// 	sign_bit = 0 * (1U << 31);
	// else
	// 	sign_bit = 1 * (1U << 31);

	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_num_val = roundf(f * (1 << this ->num_fractional_bits));
	// this->fixed_point_num_val = (this->fixed_point_num_val & ~(1U << 31)) | sign_bit;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
	}
	else
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->fixed_point_num_val = obj.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called." << std::endl;
	return (this->fixed_point_num_val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called." << std::endl;
	this->fixed_point_num_val = raw;
}

float	Fixed::toFloat(void) const
{
	std::cout << "toFloat called." << std::endl;
	return ((static_cast<float>(this->fixed_point_num_val)) / (1 << this->num_fractional_bits));
}

int		Fixed::toInt(void) const
{
	std::cout << "toInt called." << std::endl;
	return (this->fixed_point_num_val >> this->num_fractional_bits);
}