/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:29:06 by swied             #+#    #+#             */
/*   Updated: 2025/06/10 14:51:49 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_printf(const char *string, ...);
int	ft_execute(const char c, va_list args);
int	ft_c(char c);
int	ft_s(char *str);
int	ft_i(int n);
int	ft_u(unsigned int n);
int	ft_x(int n);
int	ft_capital_x(int n);
int	ft_p(void *ptr);

#endif