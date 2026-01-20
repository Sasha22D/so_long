#include "so_long.h"

void	move_player(t_game *gameStruct, int new_x, int new_y)
{
	char	**map;

	map = gameStruct->map;
	if (new_x >= gameStruct->length || new_x < 0 || new_y >= gameStruct->width || new_y < 0)
		return ;
	if (map[new_x][new_y] == 'E' && gameStruct->count_collectibles == 0)
	{
		mlx_destroy_window(gameStruct->mlx, gameStruct->mlx_win);
		destroy_map(gameStruct->map);
		free(gameStruct);
		exit(EXIT_SUCCESS);
	}
	if (map[new_x][new_y] == '0' || map[new_x][new_y] == 'C')
	{
		if (map[new_x][new_y] == 'C')
			gameStruct->count_collectibles--;
		map[gameStruct->player_x][gameStruct->player_y] = '0';
		gameStruct->player_x = new_x;
		gameStruct->player_y = new_y;
		map[new_x][new_y] = 'P';
		ft_printf("Moves: %s\n", ft_itoa(gameStruct->count_move++));
		render_map(gameStruct);
	}
}
