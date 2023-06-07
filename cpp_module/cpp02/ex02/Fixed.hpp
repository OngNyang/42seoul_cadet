#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

			Fixed&	operator=(const Fixed& obj);

			bool	operator>(const Fixed& obj) const;
			bool	operator<(const Fixed& obj) const;
			bool	operator>=(const Fixed& obj) const;
			bool	operator<=(const Fixed& obj) const;
			bool	operator==(const Fixed& obj) const;
			bool	operator!=(const Fixed& obj) const;
			Fixed	Fixed::operator+(const Fixed& obj) const;
			
};

#endif