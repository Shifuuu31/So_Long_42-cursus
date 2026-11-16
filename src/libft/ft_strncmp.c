/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:02:48 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/25 18:46:09 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (str1 == str2)
		return (0);
	while (i < n - 1 && str1 && str2 && str1[i] == str2[i])
	{
		i++;
		if (!str1[i] || !str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
