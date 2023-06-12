#include "so_long.h"


int main(int ac, char** av)
{
	t_data data;
	int i;

	if (ac < 2)
		ft_put_err("Usage : ./so_long <map.ber>\n");
	
	memset(&data, 0, sizeof(t_data));
	check_extention(&data, av[1]);
	load_map(&data, av[1]);

	puts("------------------");
	puts("Original Map:");
	puts("------------------");
	for(int i = 0; data.map[i]; i++)
	{
		printf("%s\n", data.map[i]);
	}
	check_map_size(&data);
	check_map_data(&data);
	check_walls(&data);
	get_player_position(&data);
	get_exit_position(&data);
	data.tmp_map = malloc(sizeof(char *) * data.map_height + 1);
	i = 0;
	while (data.map[i])
	{
		data.tmp_map[i] = ft_strdup(data.map[i]);
		i++;
	}
	data.tmp_map[i] = NULL;
	check_path(data.tmp_map, data.px, data.py);
	puts("------------------");
	puts("Fake Map:");
	puts("------------------");
	for(int i = 0; data.tmp_map[i]; i++)
	{
		printf("%s\n", data.tmp_map[i]);
	}
	puts("------------------");
	scan_map(&data);
	create_new_win(&data);
	return(0);
}
