#include <iostream>

class	Fixed
{
	private:
			int					fixed_point_num_val;
			static const int	num_fractional_bits = 8;
	public:
			Fixed(void);
			Fixed(const Fixed& obj);
			~Fixed(void);
			Fixed&	operator=(const Fixed& obj);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);

};

Fixed::Fixed(void)
{
	this->fixed_point_num_val = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
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


int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}