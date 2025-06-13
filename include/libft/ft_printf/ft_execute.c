/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:32:03 by swied             #+#    #+#             */
/*   Updated: 2025/06/10 14:51:01 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_execute(const char c, va_list args)
{
	int	digits;

	digits = 0;
	if (c == 'c')
		digits += (char)ft_c(va_arg(args, int));
	else if (c == 's')
		digits += ft_s(va_arg(args, char *));
	else if (c == 'p')
		digits += ft_p(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		digits += ft_i(va_arg(args, unsigned int));
	else if (c == 'u')
		digits += ft_u(va_arg(args, int));
	else if (c == 'x')
		digits += ft_x(va_arg(args, int));
	else if (c == 'X')
		digits += ft_capital_x(va_arg(args, int));
	else if (c == '%')
		digits += ft_putchar('%');
	if (digits < 0)
		return (-1);
	return (digits);
}
