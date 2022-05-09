/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shopa <shopa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:10:50 by shopa             #+#    #+#             */
/*   Updated: 2022/03/22 17:39:18 by shopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (ft_print_str("(null)"));
	else
	{
		while (str[++i] != '\0')
			write(1, &str[i], 1);
		return (i);
	}
}

int	ft_print_nbr(int n)
{
	int	basamak;
	int	sayi;

	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	sayi = n;
	basamak = 0;
	if (!n)
	{
		ft_print_char(48);
		return (1);
	}
	while (sayi != 0 && ++basamak)
		sayi /= 10;
	if (n < 0 && ++basamak)
	{
		ft_print_char('-');
		n *= -1;
	}
	if (n > 9)
		ft_print_nbr(n / 10);
	ft_print_char((n % 10) + 48);
	return (basamak);
}

int	ft_print_char_hex(unsigned int x, char format)
{
	static int	i;
	char		c;

	i = 0;
	c = (x % 16) + 48;
	if (x)
		if ((x / 16) != 0)
			ft_print_char_hex(x / 16, format);
	if ((x % 16) < 10 && ++i)
		write(1, &c, 1);
	else
	{
		c += 39;
		if (format == 'X')
			c -= 32;
		write(1, &c, 1);
		++i;
	}
	return (i);
}

int	ft_print_unsigned_char(unsigned int u)
{
	static int	i;
	char		c;

	c = (u % 10) + 48;
	i = 0;
	if (u)
		if ((u / 10) != 0)
			ft_print_unsigned_char(u / 10);
	write(1, &c, 1);
	return (++i);
}
