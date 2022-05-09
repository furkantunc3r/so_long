/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:18:44 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/25 14:05:56 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw_map2(struct s_elements *g, int a, int b)
{
	while (b < g->x_m && a < g->y_m)
	{
		while (b < g->x_m && a < g->y_m)
		{
			if (g->map[a][b] == '1')
				mlx_put_image_to_window(g->m_p, g->w_p, g->w_i, b * 50, a * 50);
			else if (g->map[a][b] == '0')
				mlx_put_image_to_window(g->m_p, g->w_p, g->b_i, b * 50, a * 50);
			else if (g->map[a][b] == 'P')
				mlx_put_image_to_window(g->m_p, g->w_p, g->p_i, b * 50, a * 50);
			else if (g->map[a][b] == 'C')
				mlx_put_image_to_window(g->m_p, g->w_p, g->c_i, b * 50, a * 50);
			else if (g->map[a][b] == 'N')
				mlx_put_image_to_window(g->m_p, g->w_p, g->n_i, b * 50, a * 50);
			else if (g->map[a][b] == 'E')
				mlx_put_image_to_window(g->m_p, g->w_p, g->e_i, b * 50, a * 50);
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

int	ft_draw_map(struct s_elements *g)
{
	int		a;
	int		b;

	g->w_p = mlx_new_window(g->m_p, (g->x_m * 50), (g->y_m * 50), "so_long");
	a = 0;
	b = g->y_m;
	a = 0;
	b = 0;
	ft_draw_map2(g, a, b);
	return (0);
}
