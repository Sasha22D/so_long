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
		return ;
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
		perror("Not all collectibles can be reached by player.\n");
}

void	error_free(char **map, int fd, t_game *gameStruct)
{
	destroy_map(map);
	free(gameStruct);
	close(fd);
}
