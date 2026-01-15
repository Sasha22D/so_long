#include "so_long.h"

int	main()
{
	int	fd;
	char	**map = NULL;
	t_game	*gameStruct;

	fd = open("map.ber", O_RDONLY);
	gameStruct = malloc(sizeof(t_game));
	if (map_checker(map, fd, gameStruct) == -1)
	{
		free(gameStruct);
		close(fd);
		exit(EXIT_FAILURE);
	}
	free(gameStruct);
	close(fd);
}
