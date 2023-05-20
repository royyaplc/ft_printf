/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:43:04 by lyap              #+#    #+#             */
/*   Updated: 2023/05/20 16:20:47 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_unsigned(unsigned int n, int digits)
{
	int	tens;

	if (n == 0)
	{
		ft_putchar_fd_pf('0', 1);
		return ;
	}
	tens = 1;
	while (digits != 1)
	{
		tens *= 10;
		--digits;
	}
	while (tens != 0)
	{
		ft_putchar_fd_pf((n / tens) + '0', 1);
		n %= tens;
		tens /= 10;
	}
	return ;
}

int	ft_format_u(unsigned int num)
{
	int				digits;
	unsigned int	n;

	digits = 0;
	n = num;
	if (n == 0)
		digits = 1;
	while (n != 0)
	{
		n /= 10;
		++digits;
	}
	ft_put_unsigned(num, digits);
	return (digits);
}
