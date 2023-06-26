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
			Fixed&	operator=(const Fixed& obj);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

};

std::ostream&	operator<<(std::ostream& out, const Fixed& obj);

#endif