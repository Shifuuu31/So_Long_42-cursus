/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:57:03 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/13 03:57:04 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void rendr_all(t_data *data, int x, int y)
{

	if(data->map[y][x] == '0')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_img, x * 40, y * 40);
	}
	else if(data->map[y][x] == '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_img, x * 40, y * 40);
	}
	else if(data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, x * 40, y * 40);
	}
	else if(data->map[y][x] == 'E' && !data->c)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->o_exit_img, x * 40, y * 40);
	}
	else if(data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_img, x * 40, y * 40);
	}
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin_img, x * 40, y * 40);
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
	data->o_exit_img = mlx_xpm_file_to_image(data->mlx, "images/open_door.xpm", &w, &h);
	if (!data->o_exit_img)
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

void game_window(t_data *data)
{
	void *param = NULL;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_width * 40, data->map_height * 40, "SO_LONG");
	init_images(data);
	render_map(data);
	get_player_position(data);
	mlx_hook(data->mlx_win, 2, 0, key_handle, data);
	mlx_hook(data->mlx_win, 17, 0, kill_window, param);
	mlx_loop(data->mlx);
}


