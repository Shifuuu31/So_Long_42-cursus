#include "so_long.h"
int move_player(int key, t_data *data)
{
    int row;
    int col;

    printf("\n%d\n",key);
    if (key == 53)
    {
        write(1, " ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████      ██ ██\n", 187);
        write(1, "██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██     ██ ██\n", 153);
        write(1, "██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████      ██ ██\n", 181);
        write(1, "██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██\n", 135);
        write(1, " ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██     ██ ██\n", 177);
        exit(0);
    }
    col = (key == 126) * (-1) + (key == 125);
    row = (key == 123) * (-1) + (key == 124);

    if (!col && !row)
        return (0);
    printf("%d, %d\n", col, row);
    printf("%d, %d\n", data->py, data->px);
    printf("Coins: %d\n", data->c);

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
