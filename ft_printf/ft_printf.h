/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:00:06 by hyejeong          #+#    #+#             */
/*   Updated: 2022/12/09 16:00:11 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_base_fd(int n, int fd, char base);
int	ft_printf(const char *format, ...);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_putp(void *ptr);
int	ft_puthexnbr_fd(long long num, int fd, char base);

#endif