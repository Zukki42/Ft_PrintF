/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:44:37 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/15 19:20:52 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ft_putchar — writes a single character to stdout :D
// Acts as the base output function for ft_printf.
// Returns the number of bytes written, or -1 if write() fails.
int	ft_putchar(char c)
{
	int	temp;

	temp = write(1, &c, 1);
	if (temp == -1)
		return (-1);
	return (temp);
}

// ft_putstr — writes a string to stdout :D
// If the string is NULL, prints "(null)" instead.
// Used by ft_printf for the %s specifier.
// Returns the total number of characters printed, or -1 on error.
int	ft_putstr(const char *s)
{
	int	count;
	int	temp;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	while (*s)
	{
		temp = write(1, s++, 1);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

// print_int — prints a signed integer in decimal format :D
// Handles negative numbers and recursion for multi-digit values.
// Used by ft_printf for %d and %i specifiers.
// Returns total characters printed, or -1 on error.
int	print_int(int n)
{
	int		count;
	int		temp;
	long	num;

	temp = 0;
	num = n;
	count = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		num = -num;
	}
	if (num >= 10)
		temp += print_int((int)(num / 10));
	if (temp == -1)
		return (-1);
	else
		count += temp;
	if (ft_putchar((char)((num % 10) + '0')) == -1)
		return (-1);
	else
		count++;
	return (count);
}

// print_unsigned — prints an unsigned integer in decimal format :D
// Implements the %u specifier for ft_printf.
// Returns total characters printed, or -1 if an error occurs.
int	print_unsigned(unsigned int n)
{
	int	count;
	int	temp;

	temp = 0;
	count = 0;
	if (n >= 10)
		temp += print_int((int)(n / 10));
	if (temp == -1)
		return (-1);
	else
		count += temp;
	if (ft_putchar((char)((n % 10) + '0')) == -1)
		return (-1);
	else
		count++;
	return (count);
}

// print_percent — prints a literal '%' character :D
// Used by ft_printf for the %% specifier.
// Returns 1 on success, or -1 on error.
int	print_percent(void)
{
	return (ft_putchar('%'));
}
