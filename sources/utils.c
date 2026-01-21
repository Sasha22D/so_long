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
	// if (!map || !map[i]) QUAND MAP VIDE MAP[0]==NULL
	// 	return ;
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
		perror("Map size is wrong.\n");
	else if (c == 'w')
		perror("Map is not surrounded by walls.\n");
	else if (c == 'e')
		perror("Number of exit and/or player different than 1 detected.\n");
	else if (c == 'c')
		perror("Map doesn't have collectibles.\n");
	else if (c == 'p')
		perror("At least one collectible or the \
			exit can't be reached by player.\n");
}

void	error_free(int fd, t_game *game)
{
	free(game);
	close(fd);
}
