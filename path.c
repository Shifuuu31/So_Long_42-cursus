#include "so_long.h"


void check_path(char **map, int y, int x)
{
    if (map[y][x] == 'X' || map[y][x] == 'E' || map[y][x] == '1')
        return;

    map[y][x] = 'X';
    check_path(map, y + 1, x);  // Right
    check_path(map, y - 1, x);  // Left
    check_path(map, y, x + 1);  // Down
    check_path(map, y, x - 1);  // Up
}

void scan_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    if (data->tmp_map[data->ey][data->ex + 1] != 'X' 
	&& data->tmp_map[data->ey][data->ex - 1] != 'X' 
	&& data->tmp_map[data->ey + 1][data->ex] != 'X' 
	&& data->tmp_map[data->ey - 1][data->ex] != 'X')
	{
		ft_put_err("Cannot find a valid path1\n");
	}
	while (data->tmp_map[i])
	{
        j = 0;
		while (data->tmp_map[i][j])
		{
			if (data->tmp_map[i][j] == 'C')
				ft_put_err("Cannot find a valid path 2\n");
			j++;
		}
		i++;
	}
    puts("Valid");
}



