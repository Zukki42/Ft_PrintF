/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:45:33 by bavirgil          #+#    #+#             */
/*   Updated: 2025/08/07 22:27:53 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

# if defined(__LINUX__)
#  define PTRNULL "(nil)"
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
# endif

// MAIN FILE
int	ft_printf(const char *format, ...);
int	handle_format(char specifier, va_list args);

// SIMPLE.C
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	print_char(char c);
int	print_str(char *s);
int	print_int(int n);

// COMPLEX.C
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int n, int uppercase);
int	print_ptr(void *ptr);
int	print_percent(void);

#endif