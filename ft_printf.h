/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:21:49 by lyap              #+#    #+#             */
/*   Updated: 2023/05/20 14:55:40 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_format_c(int ch);
int		ft_format_s(char *str);
int		ft_format_d(int num);
int		ft_format_u(unsigned int num);
int		ft_format_x(unsigned int num, int x);
int		ft_format_p(unsigned long long int num);

#endif
