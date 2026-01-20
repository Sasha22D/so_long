#include "so_long.h"

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map[0] == NULL)
		return (-1);
	while (map[0][j])
	{
		if (map[0][j] && map[0][j] != '1')
			return (-1);
		j++;
	}
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (-1);
		i++;
	}
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

int	check_exit_and_player(char **map, t_game *gameStruct)
{
	int	i;
	int	j;
	int	playerCount;
	int	exitCount;

	i = 0;
	playerCount = 0;
	exitCount = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				playerCount++;
				(*gameStruct).player_x = i;
				(*gameStruct).player_y = j;
			}
			else if (map[i][j] == 'E')
				exitCount++;
			j++;
		}
		i++;
	}
	if (playerCount != 1 || exitCount != 1)
		return (-1);
	return (0);
}

void	check_collectibles(char **map, t_game *gameStruct)
{
	int	i;
	int	j;
	gameStruct->count_collectibles = 0;
	gameStruct->count_move = 0;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				gameStruct->count_collectibles++;
			j++;
		}
		i++;
	}
}

void	fill(char **map, int x, int y, int *count_cmp, t_game *gameStruct)
{
	char	target;

	if (x >= gameStruct->length || x < 0 || y >= gameStruct->width || y < 0)
		return ;
	target = map[x][y];
	if (target == '+' || target == '1')
		return ;
	if (target == 'C' || target == 'E')
	{
		(*count_cmp)++;
	}
	map[x][y] = '+';
	fill(map, x - 1, y, count_cmp, gameStruct);
	fill(map, x + 1, y, count_cmp, gameStruct);
	fill(map, x, y + 1, count_cmp, gameStruct);
	fill(map, x, y - 1, count_cmp, gameStruct);
}

int	check_path(char **map, int x, int y, int count, t_game *gameStruct)
{
	int		count_cmp;
	char	**map_copy;
	int		i;

	count_cmp = 0;
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
	fill(map_copy, x, y, &count_cmp, gameStruct);
	if (count_cmp == (count + 1))
	{
		destroy_map(map_copy);
		return (0);
	}
	destroy_map(map_copy);
	return (-1);
}