#include "so_long.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char	**map = NULL;
	t_game	*gameStruct;

	fd = open("map.ber", O_RDONLY);
	map = init_matrix(fd);
	fill_matrix(map);
	gameStruct = malloc(sizeof(t_game));
	if (check_walls(map) || check_exit_and_player(map, gameStruct)
		|| check_collectibles(map) < 1)
	{
		destroy_map(map);
		close(fd);
		return (0);
	}
	else
	{
		int result = check_path(map, (gameStruct)->player_x, (gameStruct)->player_y, check_collectibles(map));
		printf("%d\n", result);
	}
	destroy_map(map);
	free(gameStruct);
	close(fd);
}