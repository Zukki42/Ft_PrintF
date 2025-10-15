/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:45:33 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/15 19:22:26 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

/* ************************************************************************** */
/*                             PLATFORM SETTINGS                              */
/* ************************************************************************** */

/*
** Different operating systems print NULL pointers differently:
** - macOS  → "0x0"
** - Linux  → "(nil)"
** If unsure, default to the Linux style.
*/
# ifdef __APPLE__
#  define PTRNULL "0x0"
# elif defined(__linux__)
#  define PTRNULL "(nil)"
# else
#  define PTRNULL "(nil)"
# endif

/* ************************************************************************** */
/*                             CORE PRINTF FILES                              */
/* ************************************************************************** */

/*
** Main printf implementation
** - ft_printf: Parses format strings and prints formatted output.
** - handle_format: Routes each specifier (%d, %s,
	etc.) to its matching function.
*/
int	ft_printf(const char *format, ...);
int	handle_format(char sp, va_list ap);

/* ************************************************************************** */
/*                              SIMPLE OUTPUTS                                */
/* ************************************************************************** */

/*
** Basic output and number printing functions:
** - ft_putchar: prints a single character
** - ft_putstr: prints a string (handles NULL)
** - print_int: prints a signed integer (%d / %i)
** - print_unsigned: prints an unsigned integer (%u)
** - print_percent: prints the '%' sign (%%)
*/
int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	print_int(int n);
int	print_unsigned(unsigned int n);
int	print_percent(void);

/* ************************************************************************** */
/*                              COMPLEX OUTPUTS                               */
/* ************************************************************************** */

/*
** Extended specifiers and helpers:
** - print_hex: prints hexadecimal numbers (%x / %X)
** - print_ptr: prints memory addresses (%p)
*/
int	print_hex(unsigned int n, int uppercase);
int	print_ptr(void *ptr);

#endif
