
#include "../gnlFolder/get_next_line.h"
#include <fcntl.h>

// =========MAP==========
char	**init_matrix(int fd);
void	fill_matrix(char **map);
// MAP CHECKS
int	check_walls(char **map);
int	check_exit_and_player(char **map);
int	check_collectibles(char **map);
// UTILS FUNCTIONS
int	lenstr(char *str);
void	destroy_map(char **map);