/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:50 by lyap              #+#    #+#             */
/*   Updated: 2023/05/20 14:55:24 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_d(int num)
{
	int	digits;
	int	n;

	digits = 0;
	n = num;
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
	ft_putnbr_fd(num, 1);
	return (digits);
}
