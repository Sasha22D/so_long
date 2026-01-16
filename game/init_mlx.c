#include "so_long.h"
#include "../minilibx-linux/mlx.h"

void	init_mlx(t_game *gameStruct)
{
	gameStruct->mlx = mlx_init();
	gameStruct->mlx_win = mlx_new_window(gameStruct->mlx, gameStruct->width * 64, gameStruct->length * 64, "so_long");
	mlx_loop(gameStruct->mlx);
}