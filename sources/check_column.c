/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:26:18 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/23 13:26:21 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_columns(char **map)
{
	int	i;
	int	j;

	if (map[0] == NULL)
		return (-1);
	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
