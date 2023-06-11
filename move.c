#include "so_long.h"
int move_player(int key, t_data *data)
{
    int row;
    int col;

    if (key == 53)
    {
        write(1, "game over !", 12);
        exit(0);
    }
    col = (key == 126) * (-1) + (key == 125);
    row = (key == 123) * (-1) + (key == 124);

    if (!col && !row)
        return (0);
    printf("%d, %d\n", col, row);
    printf("%d, %d\n", data->py, data->px);
    printf("Coins: %d\n", data->c);

    // printf("\n%d\n",key_code);
    if (data->map[data->py + col][data->px + row] != '1')
    {
        if (data->map[data->py + col][data->px + row] == 'E')
        {
            if (!data->c)
                exit(0);
            return (0);
        }
        else if (data->map[data->py + col][data->px + row] == 'C')
            data->c--;
        data->map[data->py + col][data->px + row] = 'P';
        data->map[data->py][data->px] = '0';
        data->px += row;
        data->py += col;
        mlx_clear_window(data->mlx, data->mlx_win);
        // for(int i = 0; data->map[i]; i++)
        // {
        //     printf("%s\n", data->map[i]);
        // }
        render_map(data);
    }
    // if (key_code == 123)
    // {
    //     if(data->map[data->py][data->px - 1] == '0' || data->map[data->py][data->px - 1] == 'C')
    //     {
    //         data->map[data->py][data->px] = data->map[data->py][data->px - 1];
    //         data->map[data->py][data->px - 1] = '0';
    //     }
    //     mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, data->px - 1 * 40, data->py * 40);
    // }
    // // get_player_position;
    // if (key_code == 124)
    // {
    //     if(data->map[data->py][data->px + 1] == '0' || data->map[data->py][data->px + 1] == 'C')
    //     {
    //         data->map[data->py][data->px] = data->map[data->py][data->px + 1];
    //         data->map[data->py][data->px + 1] = '0';
    //     }
    //     mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, data->px - 1 * 40, data->py * 40);
    // }
    // // get_player_position;
    // if (key_code == 126)
    // {
    //     if(data->map[data->py - 1][data->px] == '0' || data->map[data->py - 1][data->px] == 'C')
    //     {
    //         data->map[data->py][data->px] = data->map[data->py - 1][data->px];
    //         data->map[data->py - 1][data->px] = '0';
    //     }
    //     mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, data->px - 1 * 40, data->py * 40);
    // }
    // // get_player_position;
    // if (key_code == 125)
    // {
    //     if(data->map[data->py + 1][data->px] == '0' || data->map[data->py + 1][data->px] == 'C')
    //     {
    //         data->map[data->py][data->px] = data->map[data->py + 1][data->px];
    //         data->map[data->py + 1][data->px] = '0';
    //     }
    //     mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, data->px - 1 * 40, data->py * 40);
    // }
    // puts("------------------");
	// puts("Original Map:");
	// puts("------------------");
	// for(int i = 0; data->map[i]; i++)
	// {
	// 	printf("%s\n", data->map[i]);
	// }
	// puts("------------------");
   
    return(0);
}

// row (y+1) (y-1)
// col (x+1) (x-1)
