/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:17:58 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/22 12:37:02 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		atoi(const char *nptr);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		memcmp(const void *s1, const void *s2, size_t n);
int		strncmp(const char *s1, const char *s2, size_t n);
int		toupper(int c);
int		ft_strlen(char *str);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

char	**ft_split(char const *s, char c);
char	*strchr(const char *s, int c);
char	*strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(size_t, char));

size_t	strlcpy(char *dst, const char *str, size_t size);
#endif