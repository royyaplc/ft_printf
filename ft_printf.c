/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:58:47 by lyap              #+#    #+#             */
/*   Updated: 2023/05/18 15:58:47 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write a library that contains ft_printf(), a
function that will mimic the original printf()
*/

#include "ft_printf.h"
#include <stdio.h>

static void	ft_flag(const char *format, int *i, int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	while (format[*i + 1])
	{
		if (format[*i + 1] == '#')
		{	
			flag[0] = 1;
			++*i;
		}
		else if (format[*i + 1] == ' ')
		{
			flag[1] = 1;
			++*i;
		}
		else if (format[*i + 1] == '+')
		{
			flag[2] = 1;
			++*i;
		}
		else
			return ;
	}
}

static int	ft_check(va_list args, const char *format, int *i, int ret)
{
	int	flag[3];

	ft_flag(format, i, flag);
	if (format[*i + 1] == 'c')
		ret = ft_format_c(va_arg(args, int));
	else if (format[*i + 1] == 's')
		ret = ft_format_s(va_arg(args, char *));
	else if (format[*i + 1] == 'p')
		ret = ft_format_p((unsigned long long int)va_arg(args, void *));
	else if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
		ret = ft_format_d(va_arg(args, int), flag);
	else if (format[*i + 1] == 'u')
		ret = ft_format_u(va_arg(args, unsigned int));
	else if (format[*i + 1] == 'x')
		ret = ft_format_x(va_arg(args, unsigned int), 0, flag);
	else if (format[*i + 1] == 'X')
		ret = ft_format_x(va_arg(args, unsigned int), 1, flag);
	else if (format[*i + 1] == '%')
		ret = write(1, "%", 1);
	else
		return (-1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ret;
	int		check;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	ret = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			check = ft_check(args, format, &i, ret);
			if (check == -1)
				return (-1);
			ret += check;
			++i;
		}	
		else
			ret += write (1, &format[i], 1);
	}
	va_end(args);
	return (ret);
}

/*
int	main(void)
{
	int len;
	int	ptr;

	len = ft_printf("String with a %c char in it.\n", 'x');
	ft_printf("Characters printed = %d\n\n", len);
	len = ft_printf("String with %s\n", "another string in it.");
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("String with some digits (%d) in it.\n", INT_MAX);
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("MAX Unsigned int = %u\n", UINT_MAX);
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("String with a hex number = %X\n", 45215);
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("100%% - String with percentage symbol\n");
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("Pointer ptr = %p\n", &ptr);
	ft_printf("Pointer characters printed (ft_printf) = %i\n\n", len);
	len = ft_printf("Test sentence with %a");
	ft_printf("len = %d\n", len);
	//printf("Test sentence with %a");
}
*/