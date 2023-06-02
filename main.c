#include "so_long.h"


int main(int ac, char** av)
{
	t_data *data = malloc(sizeof(t_data));
	t_elmt *element = malloc(sizeof(t_elmt));
	int i;
	// int x ,y;

	i = 0;
	if (ac < 2)
		ft_put_err("Usage : ./so_long <map.ber>\n");
	check_extention(data, av[1]);
	load_map(data, av[1]);
	join_and_splitmap(data);
	check_map_size(data);
	check_walls(data);
	// check_collecteble(data->map);
	check_map_elements(data, element);
	get_player_position(data, element);
	data->tmp_map = malloc(sizeof(char *) * ft_count_tab(data->map));
	get_exit_position(data, element);
	data->tmp_map = data->map;
	check_path(data->tmp_map, element->y, element->x);
	int o, j;
	for(o = 0; data->map[o]; o++)
	{
		printf("%s\n", data->tmp_map[o]);
	}
	if (data->tmp_map[element->e_y][element->e_x + 1] != 'X' 
	&& data->tmp_map[element->e_y][element->e_x - 1] != 'X' 
	&& data->tmp_map[element->e_y + 1][element->e_x] != 'X' 
	&& data->tmp_map[element->e_y - 1][element->e_x] != 'X')
	{
		ft_put_err("Cannot find a valid path\n");
	}
	o = 0;
	while (data->tmp_map[o])
	{
		j = 0;
		while (data->tmp_map[o][j])
		{
			if (data->tmp_map[o][j] == 'C')
				ft_put_err("Cannot find a valid path 2\n");
			j++;
		}
		o++;
	}
	puts("ok");
	return(0);
}