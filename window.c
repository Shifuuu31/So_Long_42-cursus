#include "so_long.h"

void rendr_all(t_data *data, int x, int y)
{
	// int w, h;
	// printf("\nx = %d | y = %d\n", x, y);
	if(data->map[y][x] == '0')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_img, x * 40, y * 40);
		// printf("\nx = %d | y = %d\n", x, y);
	}
	else if(data->map[y][x] == '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_img, x * 40, y * 40);
		// printf("\nx = %d | y = %d\n", x, y);
	}
	else if(data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, x * 40, y * 40);
		// printf("\nx = %d | y = %d\n", x, y);
	}
	else if(data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_img, x * 40, y * 40);
		// printf("\nx = %d | y = %d\n", x, y);
	}
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin_img, x * 40, y * 40);
	// printf("\nx = %d | y = %d\n", x, y);
	// puts("here");
}

void	init_images(t_data *data)
{
	int h;
	int w;


	data->floor_img = mlx_xpm_file_to_image(data->mlx, "images/floor.xpm", &w, &h);
	if (!data->floor_img)
		ft_put_err("Error\n");
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", &w, &h);
	if (!data->wall_img)
		ft_put_err("Error\n");
	data->player_img = mlx_xpm_file_to_image(data->mlx, "images/player.xpm", &w, &h);
	if (!data->player_img)
		ft_put_err("Error\n");
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "images/door.xpm", &w, &h);
	if (!data->exit_img)
		ft_put_err("Error\n");
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "images/key.xpm", &w, &h);
	if (!data->coin_img)
		ft_put_err("Error\n");
}

void	render_map(t_data *data)
{
	int x, y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			rendr_all(data, x, y);
			x++;
		}
		y++;
	}
}
void create_new_win(t_data *data)
{
	// int w;
	// int h;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_width * 40, data->map_height * 40, "SO_LONG");
	// data->img = mlx_xpm_file_to_image(data->mlx, "images/Path.xpm", &w, &h);
	// int y, x;
	// y = 0;
	puts("------------------");
	puts("Original Map:");
	puts("------------------");
	for(int i = 0; data->map[i]; i++)
	{
		printf("%s\n", data->map[i]);
	}
	init_images(data);
	render_map(data);
	get_player_position(data);
	mlx_hook(data->mlx_win, 2, 0, move_player, data);
	mlx_loop(data->mlx);

}


// void create_new_data(t_data *data, t_data *data)
// {
	// int w;
	// int h;


	// data->mlx = mlx_init();
	// data->mlx_data = mlx_new_datadow(data->mlx, data->map_width * 50, data->map_height * 50, "SO_LONG");
	// data->img = mlx_xpm_file_to_image(data->mlx_data, "images/Path.xpm", &w, &h);

	// int i = 0;
	// int j = 0;

	// while(data->map[i])
	// {
	// 	j = 0;
	// 	while (data->map[i][j])
	// 	{
	// 		mlx_put_image_to_datadow(data->mlx, data->mlx_data, data->img, j * 50, i * 50);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// mlx_loop(data->mlx);
// }
