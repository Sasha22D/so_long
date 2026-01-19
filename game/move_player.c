#include "so_long.h"

void	move_up(t_game *gameStruct)
{
	int		x;
	int		y;
	char	**map;

	x = gameStruct->player_x;
	y = gameStruct->player_y;
	map = gameStruct->map;
	if (x >= gameStruct->width || y >= gameStruct->length ||
		x < 0 || y < 0 || map[x - 1][y] == '1' )
		return ;
	if (map[x - 1][y] == 'C' || map[x - 1][y] == '0')
	{
		if (map[x - 1][y] == 'C')
			gameStruct->count_collectibles--;
		map[x][y] = '0';
		gameStruct->player_x = x--;
		map[gameStruct->player_x][y] = 'P';
		render_player_collectibles_exit(gameStruct);
	}
	// if (map[x][y + 1] == 'E')
	// {
	// 	if (gameStruct->count_collectibles == 0)
	// 	{
	// 		//WIN
	// 	}
	// }
}
