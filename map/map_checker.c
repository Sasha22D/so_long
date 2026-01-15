#include "so_long.h"

int	map_checker(char **map, int fd, t_game *gameStruct)
{
	map = init_matrix(fd, gameStruct);
	if (map == NULL)
	{
		// ERROR HANDLER FUNCTION
		return (-1);
	}
	fill_matrix(map);
	if (check_walls(map) == -1)
	{
		// ERROR HANDLER FUNCTION
		return (-1);
	}
	if (check_exit_and_player(map, gameStruct) == -1)
	{
		// ERROR HANDLER FUNCTION
		return (-1);
	}
	if (check_collectibles(map) == 0)
	{
		// ERROR HANDLER FUNCTION
		return (-1);
	}
	if (check_path(map, gameStruct->player_x, gameStruct->player_y, check_collectibles(map), gameStruct) == -1)
	{
		// ERROR HANDLER FUNCTION
		return (-1);
	}
	return (0);
}