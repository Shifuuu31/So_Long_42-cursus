#include "so_long.h"

void ft_put_err(char *err_msg)
{
    ft_putstr_fd(err_msg, 2);
    exit(1);
}

bool compare_c_to_str(char *str, char c)
{
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
