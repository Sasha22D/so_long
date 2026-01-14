#include "so_long.h"

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (1);
		j++;
	}
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (1);
		i++;
	}
	j = 0;
	i -= 1;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (1);
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
		return (1);
	return (0);
}

int	check_collectibles(char **map)
{
	int	i;
	int	j;
	int	collectibleCount;

	i = 0;
	collectibleCount = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectibleCount++;
			j++;
		}
		i++;
	}
	return (collectibleCount);
}

void	fill(char **map, int x, int y, int *count_cmp)
{
	char	target;

	if (!map[x] || !map[x][y])
		return ;
	target = map[x][y];
	if (target == '+' || target == '1')
		return ;
	if (target == 'C')
	{
		(*count_cmp)++;
	}
	target = '+';
	fill(map, x - 1, y, count_cmp);
	fill(map, x + 1, y, count_cmp);
	fill(map, x, y + 1, count_cmp);
	fill(map, x, y - 1, count_cmp);
}

int	check_path(char **map, int x, int y, int count)
{
	int		count_cmp;
	char	**map_copy;

	count_cmp = 0;
	map_copy = map;
	fill(map_copy, x, y, &count_cmp);
	if (count_cmp == count)
		return (0);
	return (1);
}