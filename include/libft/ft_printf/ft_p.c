/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:38:55 by swied             #+#    #+#             */
/*   Updated: 2025/06/10 14:51:24 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_p_helper(unsigned long nb, char *decimal)
{
	int	digits;

	digits = 0;
	if (nb >= 16)
		digits += ft_p_helper(nb / 16, decimal);
	digits++;
	ft_putchar(decimal[nb % 16]);
	return (digits);
}

int	ft_p(void *ptr)
{
	int				digits;
	char			*decimal;
	unsigned long	nb;

	decimal = "0123456789abcdef";
	nb = (unsigned long)ptr;
	ft_putchar('0');
	ft_putchar('x');
	digits = 2;
	if (nb == 0)
	{
		ft_putchar('0');
		return (digits + 1);
	}
	if (nb >= 16)
		digits += ft_p_helper(nb / 16, decimal);
	digits++;
	ft_putchar(decimal[nb % 16]);
	return (digits);
}
