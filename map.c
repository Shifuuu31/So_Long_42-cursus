/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:56:27 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/13 03:56:28 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int check_extention(t_data *data, char *filename)
{
    data->extension = ".ber";
    data->extension_length = ft_strlen(data->extension);
    data->filename_length = ft_strlen(filename);
    if (data->filename_length < data->extension_length
            || ft_strncmp(filename + data->filename_length - data->extension_length, 
            data->extension, data->extension_length) != 0)
            {
                ft_put_err("Failed to open the map file.\n");
            }
    return(0);
}
void check_nl(t_data *data)
{
    int i;

    i = 0;
    while(data->map_line[i])
    {
        if(data->map_line[i] == '\n' && data->map_line[i + 1] == '\n')
            ft_put_err("Invalid map2");
        i++;
    }
}
void    load_map(t_data *data, char *filename)
{
    
	char	*buffer;
    int		check;

	data->map_line = ft_strdup("");
    data->map_file = open(filename, O_RDONLY);
	if (data->map_file == -1)
		ft_put_err("Failed to open the map file.\n");
	buffer = malloc(sizeof(char) * 2);
    if(!buffer)
        exit(1);
	check = read(data->map_file, buffer, 1);
    if(check == -1 || !check)
		ft_put_err("Failed to open the map file.\n");
	buffer[1] = '\0';
	while (check > 0)
	{
		data->map_line = ft_strjoin(data->map_line, buffer);
		check = read(data->map_file, buffer, 1);
		buffer[1] = '\0';
	}
	free(buffer);
    check_nl(data);
    data->map = ft_split(data->map_line, '\n');
    close(data->map_file);
}

void check_map_size(t_data *data)
{
    int i;

    i = 0;
    data->map_width = 0;
    data->map_height = 0;
    data->map_width = ft_strlen(data->map[0]);
    while(data->map[data->map_height])
        data->map_height++;
    while (data->map[i])
    {
        if(data->map_width != ft_strlen(data->map[i]))
            ft_put_err("Invalid map: map size error\n");
        i++;
    }

}

void check_walls(t_data *data)
{
    int  i = 0;
   
    if (compare_c_to_str(data->map[0], '1') == 0)
        ft_put_err("Invalid map: walls error1\n");
    if (compare_c_to_str(data->map[data->map_height - 1], '1') == 0)
        ft_put_err("Invalid map: walls error2\n");

    while(data->map[i])
    {
        if (data->map[i][0] != '1' || data->map[i][ft_strlen(data->map[i]) - 1] != '1')
            ft_put_err("Invalid map: walls error3\n");
        i++;
    }
}

void check_map_data(t_data *data)
{
    int i = 0;
    int j;
    data->p = 0;
    data->c = 0;
    data->e = 0;
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] != '0' && data->map[i][j] != '1' 
            && data->map[i][j] != 'E' && data->map[i][j] != 'P'
            && data->map[i][j] != 'C')
            {
                printf("%c\n-----\ni = [%d] | j =[%d]\n", data->map[i][j], i, j);
                ft_put_err("Invalid map: datas error1\n");
            }
            if(data->map[i][j] == 'P')
                data->p++;
            if(data->map[i][j] == 'C')
                data->c++;
            if(data->map[i][j] == 'E')
                data->e++;
            j++;
        }
        i++;
    }
    if (data->p != 1 || !data->c || data->e != 1)
    {
        ft_put_err("Invalid map: datas error2\n");
    }
}

void get_player_position(t_data *data)
{
    data->py = 0;
    while(data->map[data->py])
    {
        data->px = 0;
        while(data->map[data->py][data->px])
        {
            if(data->map[data->py][data->px] == 'P')
                return;
            data->px++;
        }
        data->py++;
    }
}

void get_exit_position(t_data *data)
{
    data->ey = 0;
    while(data->map[data->ey])
    {
        data->ex = 0;
        while(data->map[data->ey][data->ex])
        {
            if(data->map[data->ey][data->ex] == 'E')
            {
                return;
            }
            data->ex++;
        }
        data->ey++;
    }
}


