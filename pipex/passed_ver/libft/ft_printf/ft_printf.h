/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:00:06 by hyejeong          #+#    #+#             */
/*   Updated: 2023/01/04 16:09:48 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c, int fd);
int	ft_putstr(char *s, int fd);
int	ft_putnbr_base_fd(int n, int fd, char base);
int	ft_printf(const char *format, ...);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_putp(void *ptr);
int	ft_put_hex_nbr(unsigned int num, char base);

#endif