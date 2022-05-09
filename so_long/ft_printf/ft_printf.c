/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shopa <shopa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:57:07 by shopa             #+#    #+#             */
/*   Updated: 2022/03/22 17:39:36 by shopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	sum;

	sum = 0;
	if (format == 'c')
		sum += ft_print_char(va_arg(args, int));
	else if (format == 's')
		sum += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		sum += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		sum += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		sum += ft_print_unsigned_char(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		sum += ft_print_char_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		sum += ft_print_char('%');
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_formats(args, str[++i]);
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
