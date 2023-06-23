/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:49:29 by asaadane          #+#    #+#             */
/*   Updated: 2023/06/24 00:02:02 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	element_init(t_sl *sl)
{
	sl->p = 0;
	sl->c = 0;
	sl->e = 0;
}

void	game_over(void)
{
	write(1, "\033[1m\033[31m", 10);
	write(1, "Game Over !!\n", 13);
	exit(0);
}

void	you_win(void)
{
	write(1, "\033[1m\033[32m", 10);
	write(1, "You Win !!\n", 11);
	exit(0);
}
