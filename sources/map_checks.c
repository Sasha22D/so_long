/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:39:58 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/20 13:40:03 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map[0] == NULL || check_columns(map) == -1)
		return (-1);
	while (map[0][j])
	{
		if (map[0][j] && map[0][j] != '1')
			return (-1);
		j++;
	}
	while (map[i])
		i++;
	j = 0;
	i -= 1;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

int	check_exit_and_player(char **map)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;

	i = 0;
	player_count = 0;
	exit_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player_count++;
			else if (map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1)
		return (-1);
	return (0);
}

void	check_collectibles(char **map, t_game *game)
{
	int	i;
	int	j;

	game->count_collectibles = 0;
	game->count_move = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				game->count_collectibles++;
			if (map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
}

void	fill(char **map, int x, int y, t_game *game)
{
	char	target;

	if (x >= game->length || x < 0 || y >= game->width || y < 0)
		return ;
	target = map[x][y];
	if (target == '+' || target == '1' || target == 'E')
		return ;
	if (target == 'C')
		game->count_collectibles--;
	map[x][y] = '+';
	fill(map, x - 1, y, game);
	fill(map, x + 1, y, game);
	fill(map, x, y + 1, game);
	fill(map, x, y - 1, game);
}

int	check_path(char **map, int x, int y, t_game *game)
{
	int		count_cmp;
	char	**map_copy;
	int		i;

	count_cmp = game->count_collectibles;
	i = 0;
	while (map[i])
		i++;
	map_copy = malloc(sizeof(char *) * (i + 1));
	if (!map_copy)
		return (-1);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	fill(map_copy, x, y, game);
	destroy_map(map_copy);
	if (0 == (game->count_collectibles))
		return (game->count_collectibles = count_cmp, 0);
	return (-1);
}
