#include "so_long.h"

char	**map_checker(char **map, int fd, t_game *gameStruct)
{
	map = init_matrix(fd, gameStruct);
	if (map == NULL)
		return (destroy_map(map), error_printer('m'), NULL);
	fill_matrix(map);
	if (check_walls(map) == -1)
		return (destroy_map(map), error_printer('w'), NULL);
	if (check_exit_and_player(map, gameStruct) == -1)
		return (destroy_map(map), error_printer('e'), NULL);
	if (check_collectibles(map) == 0)
		return (destroy_map(map), error_printer('c'), NULL);
	if (check_path(map, gameStruct->player_x, gameStruct->player_y, check_collectibles(map), gameStruct) == -1)
		return (destroy_map(map), error_printer('p'), NULL);
	return (map);
}
