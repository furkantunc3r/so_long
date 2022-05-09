/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shopa <shopa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:37 by shopa             #+#    #+#             */
/*   Updated: 2022/03/22 17:20:50 by shopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_print_char_hex(unsigned int x, char format);
int		ft_print_unsigned_char(unsigned int u);
int		ft_print_ptr(unsigned long long p);
int		ptr_len(unsigned long long p);
void	write_ptr(unsigned long long p);

#endif
