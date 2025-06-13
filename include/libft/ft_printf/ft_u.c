/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:39:16 by swied             #+#    #+#             */
/*   Updated: 2025/06/10 14:52:17 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n > 9)
		digits += ft_i(n / 10);
	digits++;
	n = n % 10;
	ft_putchar(n + 48);
	return (digits);
}
