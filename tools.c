#include "so_long.h"

void ft_put_err(char *err_msg)
{
    ft_putstr_fd(err_msg, 2);
    exit(1);
}

int ft_count_tab(char **data)
{
    int i = 0;
    while(data[i])
        i++;
    return (i);
}