/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:44:40 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/15 19:22:00 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print_hex_ptr — prints an unsigned long long in lowercase hexadecimal :D
// Used internally by print_ptr to display memory addresses for the %p specifier.
// Returns the total number of printed characters, or -1 on error.
static int	print_hex_ptr(unsigned long long n)
{
	int		count;
	int		temp;
	char	c;

	temp = 0;
	count = 0;
	if (n >= 16)
		temp += print_hex_ptr(n / 16);
	if (temp == -1)
		return (-1);
	count += temp;
	if ((n % 16) < 10)
		c = (char)('0' + (n % 16));
	else
		c = (char)('a' + ((n % 16) - 10));
	if (ft_putchar(c) == -1)
		return (-1);
	count++;
	return (count);
}

// print_ptr — prints a memory address in hexadecimal with the "0x" prefix :D
// Implements the %p specifier in ft_printf.
// If ptr is NULL, prints the PTRNULL string (e.g. "(nil)").
// Returns the total number of printed characters, or -1 on error.
int	print_ptr(void *ptr)
{
	int					count;
	int					temp;
	unsigned long long	n;

	if (ptr == NULL)
		return (ft_putstr(PTRNULL));
	temp = 0;
	count = 0;
	temp = ft_putstr("0x");
	if (temp == -1)
		return (-1);
	count += temp;
	n = (unsigned long long)ptr;
	temp = print_hex_ptr(n);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

// print_hex — prints an unsigned integer in hexadecimal format :D
// Handles %x for lowercase and %X for uppercase hex output.
// Returns total characters printed, or -1 if write() fails.
int	print_hex(unsigned int n, int uppercase)
{
	int		count;
	int		temp;
	char	c;
	char	base_a;

	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	temp = 0;
	base_a = 'a';
	if (uppercase)
		base_a = 'A';
	if (n >= 16)
		temp = print_hex(n / 16, uppercase);
	if (temp == -1)
		return (-1);
	count += temp;
	if ((n % 16) < 10)
		c = (char)('0' + (n % 16));
	else
		c = (char)(base_a + ((n % 16) - 10));
	if (ft_putchar(c) == -1)
		return (-1);
	count++;
	return (count);
}
