/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:04:41 by swied             #+#    #+#             */
/*   Updated: 2025/06/10 14:51:34 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	int		i;
	int		digits;
	va_list	args;

	va_start (args, string);
	i = 0;
	digits = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			digits += ft_execute(string[i], args);
		}
		else
			digits += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	if (digits < 0)
		return (-1);
	return (digits);
}

// #include <stdlib.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		i;
// 	int		d;
// 	int		u;
// 	char	c;
// 	char	s[] = "test";
// 	void	*p;
// 	int		x;

// 	x = -014414;
// 	p = &i;
// 	c = 'a';
// 	i = 25525;
// 	d = 012;
// 	u = -11;
// 	printf("Original von c: %c\n", c);
// 	ft_printf("Eigene Funktion von c: %c\n", c);
// 	printf("Original von s: %s\n", s);
// 	ft_printf("Eigene Funktion von s: %s\n", s);
// 	printf("Original von i:	%i\n", i);
// 	ft_printf("Eigene Funktion von i: %i\n", i);
// 	printf("Original von d:	%d\n", d);
// 	ft_printf("Eigene Funktion von d: %d\n", d);
// 	printf("Original von u:	%u\n", u);
// 	ft_printf("Eigene Funktion von u: %u\n", u);
// 	printf("Original von x:	%x\n", x);
// 	ft_printf("Eigene Funktion von x: %x\n", x);
// 	printf("Original von X:	%X\n", x);
// 	ft_printf("Eigene Funktion von X: %X\n", x);
// 	printf("Original von p:	%p\n", p);
// 	ft_printf("Eigene Funktion von p: %p\n", p);
// 	printf("Original von percent : %%\n");
// 	ft_printf("Eigene Funktion von percent : %%\n");
// 	printf("%d\n", printf("%s\n", s));
// 	printf("%d\n", ft_printf("%s\n", s));
// 	printf("%d\n", printf("%c\n", c));
// 	printf("%d\n", ft_printf("%c\n", c));
// 	printf("%d\n", printf("%i\n", i));
// 	printf("%d\n", ft_printf("%i\n", i));
// 	printf("%d\n", printf("%d\n", d));
// 	printf("%d\n", ft_printf("%d\n", d));
// 	printf("%d\n", printf("%u\n", u));
// 	printf("%d\n", ft_printf("%u\n", u));
// 	printf("%d\n", printf("%x\n", x));
// 	printf("%d\n", ft_printf("%x\n", x));
// 	printf("%d\n", printf("%X\n", x));
// 	printf("%d\n", ft_printf("%X\n", x));
// 	printf("%d\n", printf("%p\n", p));
// 	printf("%d\n", ft_printf("%p\n", p));
// 	printf("%d\n", printf("%%\n"));
// 	printf("%d\n", ft_printf("%%\n"));
// 	return (0);
// }