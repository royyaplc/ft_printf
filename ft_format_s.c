/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:53:17 by lyap              #+#    #+#             */
/*   Updated: 2023/05/20 15:55:16 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_s(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[++i])
		ret += write(1, &str[i], 1);
	return (ret);
}
