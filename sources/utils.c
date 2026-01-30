/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:40:04 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/20 13:40:07 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	destroy_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[i])
	{
		free(map);
		return ;
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error_printer(char c)
{
	if (c == 'm')
		ft_printf("Error\nMap size is wrong.\n");
	else if (c == 'w')
		ft_printf("Error\nA character is wrong or the map is "
			"not surrounded by walls.\n");
	else if (c == 'e')
		ft_printf("Error\nNumber of exit and/or "
			"player different than 1 detected.\n");
	else if (c == 'c')
		ft_printf("Error\nMap doesn't have collectibles.\n");
	else if (c == 'p')
		ft_printf("Error\nAt least one collectible or the "
			"exit can't be reached by player.\n");
}

void	error_free(int fd, t_game *game)
{
	free(game);
	close(fd);
}

int	check_wrong_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != 'C' && map[i][j] != 'E' &&
				map[i][j] != 'P')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
