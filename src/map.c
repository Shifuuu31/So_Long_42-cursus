/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:56:27 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/23 23:54:44 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nl(t_sl *sl)
{
	int	i;

	i = 0;
	while (sl->map_line[i])
	{
		if (sl->map_line[i] == '\n' && sl->map_line[i + 1] == '\n')
			ft_put_err("Invalid map: line error");
		i++;
	}
}

void	load_map(t_sl *sl, char *filename)
{
	int		check;
	char	*buffer;

	sl->map_line = ft_strdup("");
	sl->map_file = open(filename, O_RDONLY);
	if (sl->map_file == -1)
		ft_put_err("Mapfile Error: failed to open the map file.\n");
	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		exit(1);
	check = read(sl->map_file, buffer, 1);
	if (check == -1 || !check)
		ft_put_err("Mapfile Error: failed to open the map file.\n");
	buffer[1] = '\0';
	while (check > 0)
	{
		sl->map_line = ft_strjoin(sl->map_line, buffer);
		check = read(sl->map_file, buffer, 1);
		buffer[1] = '\0';
	}
	free(buffer);
	check_nl(sl);
	sl->map = ft_split(sl->map_line, '\n');
	close(sl->map_file);
}

void	check_map_size(t_sl *sl)
{
	int	i;

	i = 0;
	sl->m_w = 0;
	sl->m_h = 0;
	sl->m_w = ft_strlen(sl->map[0]);
	while (sl->map[sl->m_h])
		sl->m_h++;
	while (sl->map[i])
	{
		if (sl->m_w != ft_strlen(sl->map[i]))
			ft_put_err("Invalid map: map size error\n");
		i++;
	}
}

void	check_walls(t_sl *sl)
{
	int	i;

	i = 0;
	if (compare_c_to_str(sl->map[0], '1') == 0)
		ft_put_err("Invalid map: walls error\n");
	if (compare_c_to_str(sl->map[sl->m_h - 1], '1') == 0)
		ft_put_err("Invalid map: walls error\n");
	while (sl->map[i])
	{
		if (sl->map[i][0] != '1'
		|| sl->map[i][ft_strlen(sl->map[i]) - 1] != '1')
			ft_put_err("Invalid map: walls error\n");
		i++;
	}
}

void	check_map_elements(t_sl *sl)
{
	int	i;
	int	j;

	i = -1;
	while (sl->map[++i])
	{
		j = -1;
		while (sl->map[i][++j])
		{
			if (sl->map[i][j] != '0' && sl->map[i][j] != '1'
			&& sl->map[i][j] != 'E' && sl->map[i][j] != 'P'
			&& sl->map[i][j] != 'C')
				ft_put_err("Invalid map: elements error\n");
			if (sl->map[i][j] == 'P')
				sl->p++;
			if (sl->map[i][j] == 'C')
				sl->c++;
			if (sl->map[i][j] == 'E')
				sl->e++;
		}
	}
	if (sl->p != 1 || !sl->c || sl->e != 1)
		ft_put_err("Invalid map: elements error\n");
}
