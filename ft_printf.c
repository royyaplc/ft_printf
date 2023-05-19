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

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		++i;
	}
}

void	ft_write_num(int n, int fd)
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
		ft_putchar_fd((n / tens) + '0', fd);
		n = n - n / tens * tens;
		tens /= 10;
	}
	return ;
}

void	ft_put_unsigned(unsigned int n, int digits)
{
	int	tens;
	
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
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
		ft_putchar_fd((n / tens) + '0', 1);
		n %= tens;
		tens /= 10;
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ft_write_num(n, fd);
	return ;
}

void	ft_put_hex(unsigned int num, int digits, int x)
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

void	ft_put_hex_p(unsigned long long int num, int digits)
{
	char					*set_uppercase;
	unsigned long long int	base16;

	set_uppercase = "0123456789ABCDEF";
	base16 = 1;
	while (digits != 1)
	{
		base16 *= 16;
		--digits;
	}
	while (base16 != 0)
	{
		ft_putchar_fd(set_uppercase[(num / base16)], 1);
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
	return (digits);
}

int	ft_format_c(int ch)
{
	int	ret;
				
	ret = write (1, &ch, 1);
	return (ret);
}

int	ft_format_s(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (str[++i])
		ret += write(1, &str[i], 1);
	return (ret);
}

int	ft_format_u(unsigned int num)
{
	int				digits;
	unsigned int	n;
	
	digits = 0;
	n = num;
	while (n != 0)
	{
		n /= 10;
		++digits;
	}
	ft_put_unsigned(num, digits);
	return (digits);
}

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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ret;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	ret = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				ret += ft_format_c(va_arg(args, int));
			if (format[i + 1] == 's')
				ret += ft_format_s(va_arg(args, char*));
			if (format[i + 1] == 'p')
				ret += ft_format_p((unsigned long long int)va_arg(args, void *));	
			if (format[i + 1] == 'i' || format[i + 1] == 'd')
				ret += ft_format_d(va_arg(args, int));
			if (format[i + 1] == 'u')
				ret += ft_format_u(va_arg(args, unsigned int));
			if (format[i + 1] == 'x')
				ret += ft_format_x(va_arg(args, unsigned int), 0);
			if (format[i + 1] == 'X')
				ret += ft_format_x(va_arg(args, unsigned int), 1);
			if (format[i + 1] == '%')
				ret += write(1, "%", 1);
			++i;
		}	
		else	
			ret += write (1, &format[i], 1);
	}
	va_end(args);
	return (ret);
}

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
	ft_printf("Pointer ptr = %p\n", &ptr);
	printf("Pointer ptr = %p\n", &ptr);
}