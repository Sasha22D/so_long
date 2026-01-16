#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;
	char	**map = NULL;
	t_game	*gameStruct;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			// PRINT ERROR FD
		gameStruct = malloc(sizeof(t_game));
		if (!gameStruct)
			exit(EXIT_FAILURE);
		map = map_checker(map, fd, gameStruct);
		if (map == NULL)
			error_free(map, fd, gameStruct);
		free(gameStruct);
		destroy_map(map);
	}
}

