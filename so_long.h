#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "mlx.h"


typedef struct s_img
{
	void *floor_img;
	void *wall_img;
	void *player_img;
	void *exit_img;
	void *coin_img;
} t_img;

typedef struct s_data
{
	// t_img	img;
	void *mlx;
    void *mlx_win;
	void *floor_img;
	void *wall_img;
	void *player_img;
	void *exit_img;
	void *o_exit_img;
	void *coin_img;
	char	*map_line;
	char	**map;
	char **tmp_map;
	char	*extension;
	int		map_file;
	int p;
	int px;
	int py;
	int e;
	int ex;
	int ey;
	int c;
	size_t	map_width;
	size_t	map_height;
	size_t	extension_length;
	size_t	filename_length;
}	t_data;

int check_extention(t_data *data, char *filename);
void    load_map(t_data *data, char *filename);
void check_walls(t_data *data);
void check_map_size(t_data *data);
void ft_put_err(char *err_msg);
void check_map_data(t_data *data);
void get_player_position(t_data *data);
void get_exit_position(t_data *data);
void check_path(char **map, int x, int y);
void scan_map(t_data *data);
void create_new_win(t_data *data);
void rendr_all(t_data *data, int x, int y);
bool compare_c_to_str(char *str, char c);
int move_player(int key_code, t_data *data);
int kill_window(int key, void *param);
void	render_map(t_data *data);


#endif