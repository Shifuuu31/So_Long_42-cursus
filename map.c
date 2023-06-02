#include "so_long.h"

bool compare_c_to_str(char *str, char c) {
    int i = 0;

    if (str == NULL)
        return 0;

    while (str[i])
    {
        if(str[i] != c)
            return 0;
        i++;
    }
    return 1;
}

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
    int i;
    data->map_line = NULL;
    data->map = NULL;

    i = 1;
    data->map_file = open(filename, O_RDONLY);
    data->map_line = get_next_line(data->map_file);
    while (data->map_line)
    {
        free(data->map_line);
        data->map_line = get_next_line(data->map_file);
        i++;
    }
    int map_lines = i;
    data->map = malloc(sizeof(char *) * (i + 1));
    if (!data->map)
        exit(1);
    close(data->map_file);
    data->map_file = open(filename, O_RDONLY);
    if (data->map_file == -1)
        ft_put_err("Failed to open the map file.\n");
    i = 0;
    while (map_lines > 0)
    {
        data->map[i] = get_next_line(data->map_file);
        if (!data->map[i])
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
    data->map_height = ft_count_tab(data->map);
    while (data->map[i])
    {
        printf("%s\n", data->map[i]);
        if(data->map_width != ft_strlen(data->map[i]))
            ft_put_err("Invalid map1\n");
        i++;
    }

}

void check_walls(t_data *data)
{
    int  i = 0;
   
    if (compare_c_to_str(data->map[0], '1') == 0)
        ft_put_err("Invalid map2\n");

    if (compare_c_to_str(data->map[ft_count_tab(data->map) - 1], '1') == 0)
    {
        // puts("here");
        ft_put_err("Invalid map3\n");
    }
    while(data->map[i])
    {
        if (data->map[i][0] != '1' || data->map[i][ft_strlen(data->map[i]) - 1] != '1')
            ft_put_err("Invalid map4\n");
        i++;
    }
}

void check_map_elements(t_data *data, t_elmt *element)
{
    int i = 0;
    int j;
    element->p = 0;
    element->c = 0;
    element->e = 0;
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == 'P')
            {
                element->p++;
            }
            if(data->map[i][j] == 'C')
            {
                element->c++;
            }
            if(data->map[i][j] == 'E')
            {
                element->e++;
            }
            j++;
        }
        i++;
    }
    if (element->p != 1 || !element->c || element->e != 1)
    {
        ft_put_err("Invalid map5\n");
    }
}

void get_player_position(t_data *data, t_elmt *element)
{
    element->y = 0;
    while(data->map[element->y])
    {
        element->x = 0;
        while(data->map[element->y][element->x])
        {
            if(data->map[element->y][element->x] == 'P')
            {
                return;
            }
            element->x++;
        }
        element->y++;
    }
}

void get_exit_position(t_data *data, t_elmt *element)
{
    element->e_y = 0;
    while(data->map[element->e_y])
    {
        element->e_x = 0;
        while(data->map[element->e_y][element->e_x])
        {
            if(data->map[element->e_y][element->e_x] == 'E')
            {
                return;
            }
            element->e_x++;
        }
        element->e_y++;
    }
}

// void check_collecteble(char **map)
// {
//     int i = 0;
//     int j;
//     while(map[i])
//     {
//     puts("here");
//         j= 0;
//         while (map[i][j])
//         {
//             if (map[i][j] == 'C')
//             {
//                 if (map[i][j + 1] == '1' && map[i][j - 1] == '1' 
//                 && map[i + 1][j] == '1' && map[i - 1][j] == '1')
// 	            	ft_put_err("Invalid map5\n");
//             }
//             j++;  
//         }
//         i++;
//     }
// }