#include "so_long.h"

void	is_map_valid(t_game *gameStruct, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	(*gameStruct).map = map_checker(NULL, fd, gameStruct);
	if ((*gameStruct).map == NULL)
	{
		error_free(fd, gameStruct);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_game	*gameStruct;
	(void)ac;

	gameStruct = malloc(sizeof(t_game));
	//ARGS CHECKER
	is_map_valid(gameStruct, av[1]);
	init_mlx(gameStruct);
	init_sprites(gameStruct);
	//RENDER MAP
	//HOOKS
	mlx_loop(gameStruct->mlx);
	destroy_map(gameStruct->map);
	free(gameStruct);
}

