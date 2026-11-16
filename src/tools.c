/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:57:00 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/23 23:45:15 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extention(t_sl *sl, char *filename)
{
	sl->extension = ".ber";
	sl->extension_length = ft_strlen(sl->extension);
	sl->filename_length = ft_strlen(filename);
	if (sl->filename_length < sl->extension_length
		|| ft_strncmp(filename + sl->filename_length - sl->extension_length,
			sl->extension, sl->extension_length) != 0)
	{
		ft_put_err("Failed to open the map file.\n");
	}
	return (0);
}

void	ft_put_err(char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	exit(1);
}

bool	compare_c_to_str(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

void	get_player_position(t_sl *sl)
{
	sl->py = 0;
	while (sl->map[sl->py])
	{
		sl->px = 0;
		while (sl->map[sl->py][sl->px])
		{
			if (sl->map[sl->py][sl->px] == 'P')
				return ;
			sl->px++;
		}
		sl->py++;
	}
}

void	get_exit_position(t_sl *sl)
{
	sl->ey = 0;
	while (sl->map[sl->ey])
	{
		sl->ex = 0;
		while (sl->map[sl->ey][sl->ex])
		{
			if (sl->map[sl->ey][sl->ex] == 'E')
			{
				return ;
			}
			sl->ex++;
		}
		sl->ey++;
	}
}
