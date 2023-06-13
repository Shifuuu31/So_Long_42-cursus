/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:56:48 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/13 03:56:49 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void check_esc()
{
    write(1, " ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████      ██ ██\n", 187);
    write(1, "██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██     ██ ██\n", 153);
    write(1, "██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████      ██ ██\n", 181);
    write(1, "██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██\n", 135);
    write(1, " ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██     ██ ██\n", 177);
    exit(0);
}

int move_player(t_data *data, int row, int col)
{
    printf("%d, %d\n", col, row);
    printf("%d, %d\n", data->py, data->px);
    printf("Coins: %d\n", data->c);
    if (!col && !row)
        return (0);
    if (data->map[data->py + col][data->px + row] != '1')
    {
        if (data->map[data->py + col][data->px + row] == 'E')
        {
            if (!data->c)
            {
                write(1, "██    ██  ██████  ██    ██     ██     ██ ██ ███    ██     ██ ██\n", 123);
                write(1, " ██  ██  ██    ██ ██    ██     ██     ██ ██ ████   ██     ██ ██\n", 121);
                write(1, "  ████   ██    ██ ██    ██     ██  █  ██ ██ ██ ██  ██     ██ ██\n", 123);
                write(1, "   ██    ██    ██ ██    ██     ██ ███ ██ ██ ██  ██ ██\n", 105);
                write(1, "   ██     ██████   ██████       ███ ███  ██ ██   ████     ██ ██\n", 129);
                exit(0);
            }
            return (0);
        }
        else if (data->map[data->py + col][data->px + row] == 'C')
            data->c--;
        data->map[data->py + col][data->px + row] = 'P';
        data->map[data->py][data->px] = '0';
        data->px += row;
        data->py += col;
        mlx_clear_window(data->mlx, data->mlx_win);
        render_map(data);
    }
    return(0);
}
int key_handle(int key, t_data *data)
{
    int row;
    int col;

    printf("\n%d\n",key);
    if (key == 53)
    {
        check_esc();
    }
    else if(key == 0 || key == 1 || key == 2 || key == 13)
    {
        col = (key == 13) * (-1) + (key == 1);
        row = (key == 0) * (-1) + (key == 2);
        move_player(data, row, col);
        
    }
    else if(key == 123 || key == 124 || key == 125 || key == 126)
    {
        col = (key == 126) * (-1) + (key == 125);
        row = (key == 123) * (-1) + (key == 124);
        move_player(data, row, col);

    }

    return(0);
}

// row (y+1) (y-1)
// col (x+1) (x-1)

int kill_window(int key, void *param)
{
    (void)param;
    printf("\n%d\n",key);
        write(1, " ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████      ██ ██\n", 187);
        write(1, "██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██     ██ ██\n", 153);
        write(1, "██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████      ██ ██\n", 181);
        write(1, "██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██\n", 135);
        write(1, " ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██     ██ ██\n", 177);
        exit(0);
}
