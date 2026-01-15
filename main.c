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
		destroy_map(map);
		free(gameStruct);
		close(fd);
		exit(EXIT_FAILURE);
	}
	destroy_map(map);
	free(gameStruct);
	close(fd);
}
