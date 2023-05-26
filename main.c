/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:10 by lyap              #+#    #+#             */
/*   Updated: 2023/05/26 21:09:31 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int len;
	int	ptr;
	char *c;

	c = NULL;

	len = ft_printf("String with a %c char in it.\n", 'x');
	ft_printf("Characters printed = (%  d)\n\n", len);
	len = ft_printf("%s", c);
	ft_printf("Characters printed = %d\n\n", len);
	len = printf("String with %s\n", "another string in it.");
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("String with some digits (%+# d) in it.\n", 54321);
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("MAX Unsigned int = %u\n", UINT_MAX);
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("String with a hex number = %##x\n", 45215);
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("100%% - String with percentage symbol\n");
	ft_printf("Characters printed = %i\n\n", len);
	len = ft_printf("Pointer ptr = %p\n", &ptr);
	ft_printf("Pointer characters printed (ft_printf) = %i\n\n", len);
	len = ft_printf("Test sentence with %a");
	ft_printf("len = %d\n", len);
	//printf("Test sentence with %a");
}