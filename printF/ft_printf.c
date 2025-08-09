/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:44:58 by bavirgil          #+#    #+#             */
/*   Updated: 2025/08/07 17:45:00 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* 
** Chooses the right print function for each format specifier in ft_printf.
*/
static int	handle_format(char sp, va_list ap)
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