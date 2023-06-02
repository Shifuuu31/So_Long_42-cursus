#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_data
{
	int		map_file;
	char	*map_line;
	char	**map;
	char **tmp_map;
	char	*extension;
	size_t	map_width;
	size_t	map_height;
	size_t	extension_length;
	size_t	filename_length;
}	t_data;

typedef struct s_elmt
{
	int p;
	int x;
	int y;
	int c;
	int e;
	int e_x;
	int e_y;
}	t_elmt;

int check_extention(t_data *data, char *filename);
void    load_map(t_data *data, char *filename);
void check_walls(t_data *data);
void check_map_size(t_data *data);
void ft_put_err(char *err_msg);
void join_and_splitmap(t_data *data);
int ft_count_tab(char **data);
void check_map_elements(t_data *data, t_elmt *element);
void get_player_position(t_data *data, t_elmt *element);
void get_exit_position(t_data *data, t_elmt *element);
void check_path(char **map, int x, int y);
void check_collecteble(char **map);

#endif