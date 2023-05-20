/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:45:19 by lyap              #+#    #+#             */
/*   Updated: 2023/05/20 14:46:21 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex_p(unsigned long long int num, int digits)
{
	char					*set_lowercase;
	unsigned long long int	base16;

	set_lowercase = "0123456789abcdef";
	base16 = 1;
	while (digits != 1)
	{
		base16 *= 16;
		--digits;
	}
	ft_putstr_fd("0x", 1);
	while (base16 != 0)
	{
		ft_putchar_fd(set_lowercase[(num / base16)], 1);
		num %= base16;
		base16 /= 16;
	}
	return ;
}

int	ft_format_p(unsigned long long int num)
{
	int						digits;
	unsigned long long int	n;

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
	ft_put_hex_p(num, digits);
	return (digits + 2);
}
