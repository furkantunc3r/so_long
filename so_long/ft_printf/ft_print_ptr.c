/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shopa <shopa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:09:07 by shopa             #+#    #+#             */
/*   Updated: 2022/03/22 17:14:17 by shopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long p)
{
	int	i;

	i = 0;
	while (p)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

void	write_ptr(unsigned long long p)
{
	if (p)
		if ((p / 16) != 0)
			write_ptr(p / 16);
	if ((p % 16) < 10)
		ft_print_char((p % 16) + 48);
	else
		ft_print_char((p % 16) + 87);
}

int	ft_print_ptr(unsigned long long p)
{
	write(1, "0x", 2);
	if (!p)
	{
		ft_print_char ('0');
		return (3);
	}
	else
		write_ptr (p);
	return (ptr_len(p) + 2);
}
