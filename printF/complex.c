/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:44:40 by bavirgil          #+#    #+#             */
/*   Updated: 2025/08/08 20:55:43 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	print_hex_ptr(unsigned long long n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
		count += print_hex_ptr(n / 16);
	if ((n % 16) < 10)
		c = '0' + (n % 16);
	else
		c = 'a' + ((n % 16) - 10);
	count += ft_putchar(c);
	return (count);
}
