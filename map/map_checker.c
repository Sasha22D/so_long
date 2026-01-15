#include "so_long.h"

int	map_checker(char **map, int fd, t_game *gameStruct)
{
	map = init_matrix(fd, gameStruct);
	if (map == NULL)
		return (destroy_map(map), error_printer('m'), -1);
	fill_matrix(map);
	if (check_walls(map) == -1)
		return (destroy_map(map), error_printer('w'), -1);
	if (check_exit_and_player(map, gameStruct) == -1)
		return (destroy_map(map), error_printer('e'), -1);
	if (check_collectibles(map) == 0)
		return (destroy_map(map), error_printer('c'), -1);
	if (check_path(map, gameStruct->player_x, gameStruct->player_y, check_collectibles(map), gameStruct) == -1)
		return (destroy_map(map), error_printer('p'), -1);
	destroy_map(map);
	return (0);
}
