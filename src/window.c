/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:57:03 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/23 23:43:34 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendr_all(t_sl *sl, int x, int y)
{
	if (sl->map[y][x] == '0')
	{
		mlx_put_image_to_window(sl->mlx, sl->win, sl->floor, x * 40, y * 40);
	}
	else if (sl->map[y][x] == '1')
	{
		mlx_put_image_to_window(sl->mlx, sl->win, sl->wall, x * 40, y * 40);
	}
	else if (sl->map[y][x] == 'P')
	{
		mlx_put_image_to_window(sl->mlx, sl->win, sl->player, x * 40, y * 40);
	}
	else if (sl->map[y][x] == 'E' && !sl->c)
	{
		mlx_put_image_to_window(sl->mlx, sl->win, sl->o_exit, x * 40, y * 40);
	}
	else if (sl->map[y][x] == 'E')
	{
		mlx_put_image_to_window(sl->mlx, sl->win, sl->exit, x * 40, y * 40);
	}
	else
		mlx_put_image_to_window(sl->mlx, sl->win, sl->coin, x * 40, y * 40);
}

void	init_images(t_sl *sl)
{
	int	h;
	int	w;

	sl->floor = mlx_xpm_file_to_image(sl->mlx, "images/floor.xpm", &w, &h);
	if (!sl->floor)
		ft_put_err("Error\n");
	sl->wall = mlx_xpm_file_to_image(sl->mlx, "images/wall.xpm", &w, &h);
	if (!sl->wall)
		ft_put_err("Error\n");
	sl->player = mlx_xpm_file_to_image(sl->mlx, "images/player.xpm", &w, &h);
	if (!sl->player)
		ft_put_err("Error\n");
	sl->exit = mlx_xpm_file_to_image(sl->mlx, "images/door.xpm", &w, &h);
	if (!sl->exit)
		ft_put_err("Error\n");
	sl->o_exit = mlx_xpm_file_to_image(sl->mlx, "images/open_door.xpm", &w, &h);
	if (!sl->o_exit)
		ft_put_err("Error\n");
	sl->coin = mlx_xpm_file_to_image(sl->mlx, "images/key.xpm", &w, &h);
	if (!sl->coin)
		ft_put_err("Error\n");
}

void	render_map(t_sl *sl)
{
	int	y;
	int	x;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			rendr_all(sl, x, y);
			x++;
		}
		y++;
	}
}

void	game_window(t_sl *sl)
{
	sl->mlx = mlx_init();
	sl->win = mlx_new_window(sl->mlx, sl->m_w * 40, sl->m_h * 40, N);
	init_images(sl);
	render_map(sl);
	get_player_position(sl);
	mlx_hook(sl->win, 2, 1L << 0, key_handle, sl);
	mlx_hook(sl->win, 17, 1L << 17, kill_window, NULL);
	mlx_loop(sl->mlx);
}
