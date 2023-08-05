/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:07:39 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/18 16:11:22 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	get_to_size(unsigned int to_dcmal, unsigned int base_to_len);
int				valid_base(char *str);
int				check_base(char c, char *str);
int				check_spaces(char *str, int *sign);
int				ft_atoi_base(char *str, char *base);
char			*base_trsf(int nb, char *base, char *base_to_num, \
unsigned int to_size);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
char			*base_trsf(int nb, char *base, char *base_to_num, \
unsigned int to_size);

unsigned int	get_to_size(unsigned int to_dcmal, unsigned int base_to_len)
{
	unsigned int	to_size;

	to_size = 0;
	while (to_dcmal / base_to_len != 0)
	{
		to_dcmal /= base_to_len;
		to_size++;
	}
	to_size++;
	return (to_size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				to_dcmal;
	int				base_to_len;
	int				sign;
	unsigned int	to_size;
	char			*base_to_num;

	sign = 1;
	to_dcmal = ft_atoi_base(nbr, base_from);
	if (to_dcmal < 0)
	{
		sign = -1;
		to_dcmal *= -1;
	}
	to_dcmal = (unsigned int)(to_dcmal);
	base_to_len = (unsigned int)valid_base(base_to);
	if (base_to_len == 0)
		return (0);
	to_size = get_to_size(to_dcmal, base_to_len);
	if (sign < 0)
		base_to_num = (char *)malloc(sizeof(char) * (to_size + 2));
	else
		base_to_num = (char *)malloc(sizeof(char) * (to_size + 1));
	to_dcmal = (unsigned int)(ft_atoi_base(nbr, base_from) * sign);
	base_trsf((int)(sign * to_dcmal), base_to, base_to_num, to_size);
	return (base_to_num);
}

char	*base_trsf(int nb, char *base, char *base_to_num, unsigned int to_size)
{
	unsigned int	i;
	unsigned int	j;
	int				base_to_len;

	base_to_len = (unsigned int)valid_base(base);
	i = 0;
	if (nb < 0)
	{
		base_to_num[i] = '-';
		nb *= -1;
		i++;
	}
	nb = (unsigned int)nb;
	j = 0;
	base_to_num[i + to_size - j] = '\0';
	j++;
	while (nb / base_to_len != 0)
	{
		base_to_num[i + to_size - j] = base[nb % base_to_len];
		nb = nb / base_to_len;
		j++;
	}
	base_to_num[i + to_size - j] = base[nb % base_to_len];
	return (base_to_num);
}
// int main(void)
// {

// 	printf("%s", ft_convert_base("  ---1234", "0123456789", "0123456789"));

// }