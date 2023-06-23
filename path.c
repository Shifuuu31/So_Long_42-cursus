/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:56:51 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/23 23:48:42 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char **map, int y, int x)
{
	if (map[y][x] == 'X' || map[y][x] == 'E' || map[y][x] == '1')
		return ;
	map[y][x] = 'X';
	check_path(map, y + 1, x);
	check_path(map, y - 1, x);
	check_path(map, y, x + 1);
	check_path(map, y, x - 1);
}

void	scan_map(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	if (sl->tmp_map[sl->ey][sl->ex + 1] != 'X'
	&& sl->tmp_map[sl->ey][sl->ex - 1] != 'X'
	&& sl->tmp_map[sl->ey + 1][sl->ex] != 'X'
	&& sl->tmp_map[sl->ey - 1][sl->ex] != 'X')
	{
		ft_put_err("Cannot find a valid path\n");
	}
	while (sl->tmp_map[i])
	{
		j = 0;
		while (sl->tmp_map[i][j])
		{
			if (sl->tmp_map[i][j] == 'C')
				ft_put_err("Cannot find a valid path\n");
			j++;
		}
		i++;
	}
}
