/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:48:15 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/25 15:58:48 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(void)
{
	exit (0);
}

int	ft_read_map_y(int fd)
{
	char	*buff;
	int		y;
	int		a;

	a = 1;
	y = -1;
	while (a != 0)
	{
		buff = malloc(sizeof(char) + 1);
		a = read(fd, buff, 1);
		buff[1] = '\0';
		if (buff[0] == '\n')
			y++;
		free(buff);
	}
	close (fd);
	return (y);
}

int	ft_read_map_x(int fd)
{
	char	*buff;
	int		x;
	int		a;

	a = 1;
	x = 0;
	while (a != 0)
	{
		buff = malloc(sizeof(char) + 1);
		a = read(fd, buff, 1);
		buff[1] = '\0';
		if (buff[0] == '\n')
			break ;
		x++;
		free(buff);
	}
	close (fd);
	return (x);
}

void	ft_write_map(struct s_elements *g, int fd)
{
	int		a;
	int		i;

	a = 0;
	i = g->y_m;
	g->p_c = 0;
	g->c_c = 0;
	g->e_c = 0;
	g->m_c = 0;
	g->map = malloc(sizeof(char) * (g->y_m * g->x_m));
	while (i > 0)
	{
		g->map[a] = get_next_line(fd);
		i--;
		a++;
	}
}

int	main(int argc, char **argv)
{
	struct s_elements	g;
	int					fd;

	fd = 0;
	if (argc != 2)
		exit (0);
	if (ft_check_arg(argv[1]))
	{
		if (ft_check_map(&g))
		{
			fd = ft_find_map_xy(&g, argv[1]);
			if (ft_check_item(&g))
				ft_play_game(&g, argv[1], fd);
		}
	}
	ft_free_stuff(fd, &g);
}
