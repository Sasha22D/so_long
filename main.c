#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;
	t_game	*gameStruct;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		// if (fd < 0)
			// PRINT ERROR FD
		gameStruct = malloc(sizeof(t_game));
		if (!gameStruct)
			exit(EXIT_FAILURE);
		gameStruct->map = map_checker(NULL, fd, gameStruct);
		if (gameStruct->map == NULL)
			error_free(fd, gameStruct);
		free(gameStruct);
	}
}

