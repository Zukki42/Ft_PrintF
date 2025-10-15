/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:44:58 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/15 19:21:49 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// handle_format — picks the right function based on the format specifier :D
// Called by ft_printf when a '%' is found in the format string.
// Each specifier calls its matching print function.
// Returns the number of printed characters, or -1 if an error occurs.
int	handle_format(char sp, va_list ap)
{
	if (sp == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	if (sp == 's')
		return (ft_putstr(va_arg(ap, const char *)));
	if (sp == 'd' || sp == 'i')
		return (print_int(va_arg(ap, int)));
	if (sp == 'u')
		return (print_unsigned(va_arg(ap, unsigned int)));
	if (sp == 'x')
		return (print_hex(va_arg(ap, unsigned int), 0));
	if (sp == 'X')
		return (print_hex(va_arg(ap, unsigned int), 1));
	if (sp == 'p')
		return (print_ptr(va_arg(ap, void *)));
	if (sp == '%')
		return (print_percent());
	return (ft_putchar('%') + ft_putchar(sp));
}

// ft_printf — a simplified recreation of the standard printf :D
// Parses a format string and replaces format specifiers with values.
// Supports: %c, %s, %d, %i, %u, %x, %X, %p, and %%
// Returns the total number of characters printed, or -1 on error.
int	ft_printf(const char *string, ...)
{
	va_list	list;
	int		count;
	int		temp;
	int		i;

	va_start(list, string);
	count = 0;
	i = 0;
	while (string[i])
	{
		temp = 0;
		if (string[i] == '%' && string[i + 1] != '\0')
			temp += handle_format(string[++i], list);
		else
			temp = ft_putchar(string[i]);
		if (temp == -1)
			return (-1);
		count += temp;
		i++;
	}
	va_end(list);
	return (count);
}

// Example usage
// Compile with: cc ft_printf.c [other printf files] -o test && ./test
// Compares the original printf and ft_printf outputs :D
// #include "stdio.h"
// #include "unistd.h"
//
// int	main(void)
// {
// 	printf(":%d \n", printf("%p", NULL));
// 	printf(":%d \n", ft_printf("%p", NULL));
// }
