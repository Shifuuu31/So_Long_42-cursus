/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:56:54 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/24 00:01:46 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define N "SO_LONG"

# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_sl
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*o_exit;
	void	*coin;
	char	*map_line;
	char	**map;
	char	**tmp_map;
	char	*extension;
	int		map_file;
	int		p;
	int		px;
	int		py;
	int		e;
	int		ex;
	int		ey;
	int		c;
	int		move_count;
	size_t	m_w;
	size_t	m_h;
	size_t	extension_length;
	size_t	filename_length;
}	t_sl;

void	load_map(t_sl *sl, char *filename);
void	check_walls(t_sl *sl);
void	check_map_size(t_sl *sl);
void	ft_put_err(char *err_msg);
void	check_map_elements(t_sl *sl);
void	get_player_position(t_sl *sl);
void	get_exit_position(t_sl *sl);
void	check_path(char **map, int y, int x);
void	scan_map(t_sl *sl);
void	game_window(t_sl *sl);
void	rendr_all(t_sl *sl, int x, int y);
void	render_map(t_sl *sl);
void	game_over(void);
void	you_win(void);
void	element_init(t_sl *sl);
int		check_extention(t_sl *sl, char *filename);
int		key_handle(int key, t_sl *sl);
int		kill_window(int key, void *param);
bool	compare_c_to_str(char *str, char c);

#endif