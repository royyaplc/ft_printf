/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:30:55 by lyap              #+#    #+#             */
/*   Updated: 2023/05/20 16:19:31 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_num(int n, int fd)
{
	int	tens;
	int	digits;
	int	num;

	digits = 0;
	num = n;
	while (num != 0)
	{
		num /= 10;
		++digits;
	}
	tens = 1;
	while (digits != 1)
	{
		tens *= 10;
		--digits;
	}
	while (tens != 0)
	{
		ft_putchar_fd_pf((n / tens) + '0', fd);
		n = n - n / tens * tens;
		tens /= 10;
	}
	return ;
}

void	ft_putnbr_fd_pf(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd_pf('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd_pf("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd_pf('-', fd);
		n *= -1;
	}
	ft_write_num(n, fd);
	return ;
}
