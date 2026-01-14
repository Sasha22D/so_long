#include "so_long.h"
#include <stdio.h>

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

int	check_exit_and_player(char **map)
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
				playerCount++;
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

int	main()
{
	int	fd;
	char	**map = NULL;

	fd = open("map.ber", O_RDONLY);
	map = init_matrix(fd);
	fill_matrix(map);
	// for (int i = 0; map[i]; i++)
	// 	printf("%s\n", map[i]);
	// if (check_walls(map) == 1)
	// 	printf("Not valid.\n");
	// else
	// 	printf("Valid.\n");
	destroy_map(map);
	close(fd);
}