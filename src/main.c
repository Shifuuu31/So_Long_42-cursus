/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:56:39 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/23 23:38:38 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_tmp_map(t_sl *sl)
{
	int	i;

	i = 0;
	sl->tmp_map = malloc(sizeof(char *) * (sl->m_h + 1));
	while (sl->map[i])
	{
		sl->tmp_map[i] = ft_strdup(sl->map[i]);
		i++;
	}
	sl->tmp_map[i] = NULL;
}

int	main(int ac, char **av)
{
	t_sl	sl;

	if (ac < 2)
		ft_put_err("Usage : ./so_long <map.ber>\n");
	ft_memset(&sl, 0, sizeof(t_sl));
	check_extention(&sl, av[1]);
	load_map(&sl, av[1]);
	check_map_size(&sl);
	check_walls(&sl);
	check_map_elements(&sl);
	create_tmp_map(&sl);
	get_player_position(&sl);
	get_exit_position(&sl);
	check_path(sl.tmp_map, sl.py, sl.px);
	scan_map(&sl);
	game_window(&sl);
	free(sl.tmp_map);
	free(sl.map);
	return (0);
}
