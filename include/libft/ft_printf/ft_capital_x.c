/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capital_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:16:29 by swied             #+#    #+#             */
/*   Updated: 2025/06/10 15:14:34 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_capital_x(int n)
{
	int				digits;
	char			*decimal;
	unsigned int	nb;

	decimal = "0123456789ABCDEF";
	digits = 0;
	nb = (unsigned int)n;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb >= 16)
		digits += ft_capital_x(nb / 16);
	digits++;
	ft_putchar(decimal[nb % 16]);
	return (digits);
}
