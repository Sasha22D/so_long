
#include "../gnlFolder/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_game
{
	int	width;
	int	length;
	int	player_x;
	int	player_y;
}				t_game;

// =========MAP==========
char	**init_matrix(int fd, t_game *gameStruct);
void	fill_matrix(char **map);
// MAP CHECKS
int	check_walls(char **map);
int	check_exit_and_player(char **map, t_game *gameStruct);
int	check_collectibles(char **map);
int	check_path(char **map, int x, int y, int count, t_game *gameStruct);
// MAP CHECKER
int	map_checker(char **map, int fd, t_game *gameStruct);
// UTILS FUNCTIONS
int	lenstr(char *str);
void	destroy_map(char **map);