/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:56:48 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/23 23:51:47 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_sl *sl)
{
	ft_putnbr_fd(sl->move_count, 1);
	if (!sl->move_count || sl->move_count == 1)
		write(1, " move\n", 6);
	else
		write(1, " moves\n", 7);
	sl->move_count++;
}

int	move_player(t_sl *sl, int row, int col)
{
	if (!col && !row)
		return (0);
	if (sl->map[sl->py + col][sl->px + row] != '1')
	{
		if (sl->map[sl->py + col][sl->px + row] != 'E')
			display_moves(sl);
		if (sl->map[sl->py + col][sl->px + row] == 'E')
		{
			if (!sl->c)
				you_win();
			return (0);
		}
		else if (sl->map[sl->py + col][sl->px + row] == 'C')
			sl->c--;
		sl->map[sl->py + col][sl->px + row] = 'P';
		sl->map[sl->py][sl->px] = '0';
		sl->px += row;
		sl->py += col;
		mlx_clear_window(sl->mlx, sl->win);
		render_map(sl);
	}
	return (0);
}

int	key_handle(int key, t_sl *sl)
{
	int	row;
	int	col;

	if (key == 53)
	{
		game_over();
	}
	else if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		col = (key == 13) * (-1) + (key == 1);
		row = (key == 0) * (-1) + (key == 2);
		move_player(sl, row, col);
	}
	else if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		col = (key == 126) * (-1) + (key == 125);
		row = (key == 123) * (-1) + (key == 124);
		move_player(sl, row, col);
	}
	return (0);
}

int	kill_window(int key, void *param)
{
	(void)param;
	(void)key;
	game_over();
	return (0);
}
