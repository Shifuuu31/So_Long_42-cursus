#include "so_long.h"


void check_path(char **map, int y, int x)
{
    // printf("[%d]-[%d]-[%c]\n", y, x, map[y][x]);
    if (map[y][x] == 'X' || map[y][x] == 'E' || map[y][x] == '1')
        return;
    
    map[y][x] = 'X';
    check_path(map, y + 1, x);  // Right
    check_path(map, y - 1, x);  // Left
    check_path(map, y, x + 1);    // Down
    puts("here");
    check_path(map, y, x - 1);  // Up
}



