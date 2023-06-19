#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixed_point_num_val = 0;
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
	this->fixed_point_num_val = n << this->num_fractional_bits;
}

Fixed::Fixed(const float f)
{
	this->fixed_point_num_val = roundf(f * (1 << this ->num_fractional_bits));
}

Fixed::~Fixed(void)
{
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

//comparison operators
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

//arithmetic operators
Fixed	Fixed::operator+(const Fixed& obj) const
{
	float	sum = this->toFloat() + obj.toFloat();
	Fixed	result(sum);

	return (result);
}

Fixed	Fixed::operator-(const Fixed& obj) const
{
	float	diff = this->toFloat() - obj.toFloat();
	Fixed	result(diff);

	return (result);
}

Fixed	Fixed::operator*(const Fixed& obj) const
{
	float	multi = this->toFloat() * obj.toFloat();
	Fixed	result(multi);

	return (result);
}

Fixed	Fixed::operator/(const Fixed& obj) const
{
	int		divi = this->toFloat() / obj.toFloat();
	Fixed	result(divi);

	return (result);
}

//increment/decrement operators
Fixed& Fixed::operator++(void)
{
	++fixed_point_num_val;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++fixed_point_num_val;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	--fixed_point_num_val;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--fixed_point_num_val;
	return (temp);
}

//static member function
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}