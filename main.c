#include "so_long.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char	**map = NULL;

	fd = open("map.ber", O_RDONLY);
	map = init_matrix(fd);
	fill_matrix(map);
	// for (int i = 0; map[i]; i++)
	// 	printf("%s\n", map[i]);
	// if (check_walls(map) == 1)
	// 	printf("Not valid.\n");
	// else
	// 	printf("Valid.\n");
	destroy_map(map);
	close(fd);
}