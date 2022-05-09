/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:53:51 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/25 15:58:43 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_play_game(struct s_elements *g, char *argv, int fd)
{
	ft_draw_item(g);
	fd = open(argv, O_RDONLY);
	ft_draw_map(g);
	mlx_hook(g->w_p, 17, 0, ft_key, 0);
	mlx_key_hook(g->w_p, ft_key_event, g);
	mlx_loop(g->m_p);
}
