/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:58:21 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/25 14:05:08 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_map_xy(struct s_elements *g, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	g->y_m = ft_read_map_y(fd);
	fd = open(argv, O_RDONLY);
	g->x_m = ft_read_map_x(fd);
	fd = open(argv, O_RDONLY);
	ft_write_map(g, fd);
	return (fd);
}

int	ft_check_map_2(struct s_elements *g, int a, int b)
{
	while (b < g->x_m && a < g->y_m)
	{
		if (a == 0 || a == (g->y_m - 1))
		{
			if (g->map[a][b] != '1')
			{
				ft_printf("Error\nMap isn't surrounded by walls!\n");
				return (0);
			}
		}
		if (b == 0 || b == (g->x_m - 1))
		{
			if (g->map[a][b] != '1')
			{
				ft_printf("Error\nMap isn't surrounded by walls!\n");
				return (0);
			}
		}
		b++;
	}
	return (1);
}

int	ft_check_map(struct s_elements *g)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (b < g->x_m && a < g->y_m)
	{
		while (g->map[a][b] != '\0')
			b++;
		if ((b - 1) != g->x_m)
		{
			ft_printf("Error\nMap rows or columns do not match!\n");
			return (0);
		}
		b = 0;
		if (!ft_check_map_2 (g, a, b))
			return (0);
		b = 0;
		a++;
	}
	return (1);
}
