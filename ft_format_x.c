/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:37:05 by lyap              #+#    #+#             */
/*   Updated: 2023/05/20 15:22:56 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex(unsigned int num, int digits, int x);

static void	ft_put_hex(unsigned int num, int digits, int x)
{
	char		*set_lowercase;
	char		*set_uppercase;
	long int	base16;

	set_lowercase = "0123456789abcdef";
	set_uppercase = "0123456789ABCDEF";
	base16 = 1;
	while (digits != 1)
	{
		base16 *= 16;
		--digits;
	}
	while (base16 != 0)
	{
		if (x == 0)
			ft_putchar_fd(set_lowercase[(num / base16)], 1);
		else
			ft_putchar_fd(set_uppercase[(num / base16)], 1);
		num %= base16;
		base16 /= 16;
	}
	return ;
}

int	ft_format_x(unsigned int num, int x)
{
	int				digits;
	unsigned int	n;

	digits = 0;
	n = num;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (n != 0)
	{
		n /= 16;
		++digits;
	}
	ft_put_hex(num, digits, x);
	return (digits);
}
