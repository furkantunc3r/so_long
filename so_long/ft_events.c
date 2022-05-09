/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:19:52 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/25 11:23:37 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_move(struct s_elements *g)
{
	g->m_c += 1;
	ft_printf("Move count: %d\n", g->m_c);
}

void	ft_close(struct s_elements *g)
{
	if (g->c_c == 0)
		ft_printf("You win!\n");
	mlx_destroy_window(g->m_p, g->w_p);
	exit (0);
}

void	ft_move(struct s_elements *g, int y, int x)
{
	mlx_put_image_to_window
	(g->m_p, g->w_p, g->b_i, (g->p_x * 50), (g->p_y * 50));
	mlx_put_image_to_window
	(g->m_p, g->w_p, g->p_i, ((g->p_x + x) * 50), ((g->p_y + y) * 50));
	g->map[g->p_y][g->p_x] = '0';
	g->p_y += y;
	g->p_x += x;
}

void	ft_check_move(struct s_elements *g, int y, int x)
{
	if (g->map[g->p_y + y][g->p_x + x] == '0')
	{
		ft_move(g, y, x);
		ft_print_move(g);
	}
	else if (g->map[g->p_y + y][g->p_x + x] == 'C')
	{
		ft_print_move(g);
		ft_move(g, y, x);
		g->c_c--;
	}
	else if (g->map[g->p_y + y][g->p_x + x] == '1')
		ft_printf("Can't you see the tree?\n");
	else if (g->map[g->p_y + y][g->p_x + x] == 'E')
	{
		if (g->c_c == 0)
			ft_close(g);
	}
	else
	{
		mlx_destroy_window(g->m_p, g->w_p);
		ft_printf("You lose!\n");
		exit (0);
	}
}

int	ft_key_event(int keycode, struct s_elements *g)
{
	if (keycode == EVENT_W)
		ft_check_move(g, -1, 0);
	else if (keycode == EVENT_A)
		ft_check_move(g, 0, -1);
	else if (keycode == EVENT_S)
		ft_check_move (g, 1, 0);
	else if (keycode == EVENT_D)
		ft_check_move (g, 0, 1);
	else if (keycode == EVENT_ESC)
		ft_close(g);
	return (0);
}
