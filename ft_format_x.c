/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:37:05 by lyap              #+#    #+#             */
/*   Updated: 2023/05/26 21:05:45 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex(unsigned int num, int digits, int x, int *flag);

static void	ft_put_hex(unsigned int num, int digits, int x, int *flag)
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
	if (flag[0] == 1)
	{
		if (x == 0)
			ft_putstr_fd_pf("0x", 1);
		else
			ft_putstr_fd_pf("0X", 1);
	}
	while (base16 != 0)
	{
		if (x == 0)
			ft_putchar_fd_pf(set_lowercase[(num / base16)], 1);
		else
			ft_putchar_fd_pf(set_uppercase[(num / base16)], 1);
		num %= base16;
		base16 /= 16;
	}
	return ;
}

int	ft_format_x(unsigned int num, int x, int *flag)
{
	int				digits;
	unsigned int	n;

	digits = 0;
	n = num;
	if (num == 0)
	{
		ft_putchar_fd_pf('0', 1);
		return (1);
	}
	while (n != 0)
	{
		n /= 16;
		++digits;
	}
	ft_put_hex(num, digits, x, flag);
	if (flag[0] == 1)
		digits = digits + 2;
	return (digits);
}
