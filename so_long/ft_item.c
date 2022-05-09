/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:21:20 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/25 16:01:21 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_item2(struct s_elements *g, int a, int b)
{
	if (g->map[a][b] == 'C')
		g->c_c++;
	if (g->map[a][b] == 'E')
		g->e_c++;
	return (0);
}

int	ft_check_item(struct s_elements *g)
{
	int	a;
	int	b;

	a = -1;
	b = -1;
	while (++b < g->x_m && ++a < g->y_m)
	{
		while (g->map[a][b++] != '\0')
		{
			if (g->map[a][b] == 'P')
			{
				g->p_c++;
				g->p_x = b;
				g->p_y = a;
			}
			ft_check_item2(g, a, b);
		}
		b = -1;
	}
	if (g->p_c != 1 || g->c_c < 1 || g->e_c < 1)
	{
		ft_printf("Error\nGame elements missing or exceeding the limit!\n");
		return (0);
	}
	return (1);
}

int	ft_draw_item(struct s_elements *g)
{
	int	mul;

	g->m_p = mlx_init();
	g->p_xp = "xpm/player.xpm";
	g->c_xp = "xpm/arrow.xpm";
	g->b_xp = "xpm/background.xpm";
	g->w_xp = "xpm/tree.xpm";
	g->n_xp = "xpm/enemy.xpm";
	g->e_xp = "xpm/door.xpm";
	g->p_i = mlx_xpm_file_to_image(g->m_p, g->p_xp, &mul, &mul);
	g->c_i = mlx_xpm_file_to_image(g->m_p, g->c_xp, &mul, &mul);
	g->b_i = mlx_xpm_file_to_image(g->m_p, g->b_xp, &mul, &mul);
	g->w_i = mlx_xpm_file_to_image(g->m_p, g->w_xp, &mul, &mul);
	g->n_i = mlx_xpm_file_to_image(g->m_p, g->n_xp, &mul, &mul);
	g->e_i = mlx_xpm_file_to_image(g->m_p, g->e_xp, &mul, &mul);
	return (0);
}
