/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:37:05 by lyap              #+#    #+#             */
/*   Updated: 2023/05/20 14:37:36 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
