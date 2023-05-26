/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:50 by lyap              #+#    #+#             */
/*   Updated: 2023/05/26 16:39:33 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_d(int num, int *flag)
{
	int	digits;
	int	n;

	digits = 0;
	n = num;
	if (n == 0)
		digits = 1;
	if ((flag[1] == 1 || flag[2] == 1) && n > 0)
	{
		if (flag[2] == 1)
		{
			digits = 1;
			ft_putchar_fd_pf('+', 1);
		}
		else
		{
			digits = 1;
			ft_putchar_fd_pf(' ', 1);
		}
	}
	if (n < 0)
	{
		digits = 1;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		++digits;
	}
	ft_putnbr_fd_pf(num, 1);
	return (digits);
}
