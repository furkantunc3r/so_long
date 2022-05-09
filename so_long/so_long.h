/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:45:34 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/25 15:59:21 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define EVENT_W 13
# define EVENT_A 0
# define EVENT_S 1
# define EVENT_D 2
# define EVENT_ESC 53
# define EVENT_X 17

struct s_elements
{
	char	**map;
	int		x_m;
	int		y_m;
	int		c_c;
	int		e_c;
	int		p_c;
	int		p_x;
	int		p_y;
	int		m_c;
	char	*p_xp;
	char	*c_xp;
	char	*e_xp;
	char	*w_xp;
	char	*b_xp;
	char	*n_xp;
	void	*p_i;
	void	*c_i;
	void	*e_i;
	void	*w_i;
	void	*b_i;
	void	*n_i;
	void	*m_p;
	void	*w_p;
};

int		ft_check_arg(char *argv);
int		ft_draw_map(struct s_elements *g);
int		ft_draw_map2(struct s_elements *g, int a, int b);
int		ft_key_event(int keycode, struct s_elements *g);
int		ft_find_map_xy(struct s_elements *g, char *argv);
void	ft_play_game(struct s_elements *g, char *argv, int fd);
void	ft_check_move(struct s_elements *g, int y, int x);
void	ft_move(struct s_elements *g, int y, int x);
int		ft_draw_item(struct s_elements *g);
int		ft_check_item(struct s_elements *g);
int		ft_check_item2(struct s_elements *g, int a, int b);
int		ft_check_map(struct s_elements *g);
int		ft_check_map2(struct s_elements *g, int a, int b);
void	ft_write_map(struct s_elements *g, int fd);
int		ft_read_map_x(int fd);
int		ft_read_map_y(int fd);
int		ft_key(void);
void	ft_free_stuff(int fd, struct s_elements *g);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
