/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:44:37 by bavirgil          #+#    #+#             */
/*   Updated: 2025/08/08 20:36:53 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
** Write a single character to stdout. 
** Used by ft_printf as the base output unit for all other print functions.
*/
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/* 
** Write a string to stdout; if NULL, print "(null)".
** Needed for ft_printf's %s specifier to handle normal and NULL strings.
*/
int	ft_putstr(const char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

/* 
** Print a signed integer in decimal format.
** Implements %d and %i in ft_printf, handling negative numbers.
*/
int	print_int(int n)
{
	int		count;
	long	num;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		count += print_int((int)(num / 10));
	count += ft_putchar((char)((num % 10) + '0'));
	return (count);
}

/* 
** Print an unsigned integer in decimal format.
** Implements the %u specifier for ft_printf.
*/
int	print_unsigned(unsigned int n)
{
	int		count;
	char	c;

	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	c = (char)('0' + (n % 10));
	count += ft_putchar(c);
	return (count);
}

/* 
** Print a percent sign '%'.
** Handles the %% specifier in ft_printf.
*/
int	print_percent(void)
{
	return (ft_putchar('%'));
}