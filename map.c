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

void join_and_splitmap(t_data *data)
{
    int i = 2;
    char *joined;
    joined = ft_strjoin(data->map[0], data->map[1]);
    while(data->map[i])
    {
        joined = ft_strjoin(joined, data->map[i]);
        i++;
    }
    data->map = ft_split(joined, '\n');
}

void    load_map(t_data *data, char *filename)
{
    
    data->map_line = NULL;

    data->map_height = 0;
    data->map_file = open(filename, O_RDONLY);
    data->map_line = get_next_line(data->map_file);
    while (data->map_line)
    {
        free(data->map_line);
        data->map_line = get_next_line(data->map_file);
        data->map_height++;
    }
     printf("\n height = %zu\n", data->map_height);
    if(data->map_height == 0)
        ft_put_err("Unable to find map");
    int map_lines = data->map_height;
    data->map = malloc(sizeof(char *) * (data->map_height + 1));
    if (!data->map)
        exit(1);
    close(data->map_file);
    data->map_file = open(filename, O_RDONLY);
    if (data->map_file == -1)
        ft_put_err("Failed to open the map file.\n");
    int i;
    i = 0;
    while (map_lines > 0)
    {
        data->map[i] = get_next_line(data->map_file);
        if (!data->map[i] || data->map[i][0] != '1')
            break ;
        i++;
        map_lines --;
    }
    close(data->map_file);
}

void check_map_size(t_data *data)
{
    int i;

    i = 0;
    data->map_width = ft_strlen(data->map[0]);
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
            {
                data->p++;
            }
            if(data->map[i][j] == 'C')
            {
                data->c++;
            }
            if(data->map[i][j] == 'E')
            {
                data->e++;
            }
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


