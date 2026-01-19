#include "so_long.h"

void	render_floor(t_game *gameStruct)
{
	int	i;
	int	j;

	i = 0;
	while (gameStruct->map[i])
	{
		j = 0;
		while (gameStruct->map[i][j])
		{
			mlx_put_image_to_window(gameStruct->mlx, gameStruct->mlx_win, gameStruct->spaces.sprite, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	render_walls(t_game *gameStruct)
{
	int	i;
	int	j;

	i = 0;
	while (gameStruct->map[i])
	{
		j = 0;
		while (gameStruct->map[i][j])
		{
			if (gameStruct->map[i][j] == '1')
				mlx_put_image_to_window(gameStruct->mlx, gameStruct->mlx_win, gameStruct->walls.sprite, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	render_player_collectibles_exit(t_game *gameStruct)
{
	int	i;
	int	j;

	i = 0;
	while (gameStruct->map[i])
	{
		j = 0;
		while (gameStruct->map[i][j])
		{
			if (gameStruct->map[i][j] == 'P')
				mlx_put_image_to_window(gameStruct->mlx, gameStruct->mlx_win, gameStruct->player.sprite, j * 32, i * 32);
			if (gameStruct->map[i][j] == 'E')
				mlx_put_image_to_window(gameStruct->mlx, gameStruct->mlx_win, gameStruct->exit.sprite, j * 32, i * 32);
			if (gameStruct->map[i][j] == 'C')
				mlx_put_image_to_window(gameStruct->mlx, gameStruct->mlx_win, gameStruct->collectibles.sprite, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	render_map(t_game *gameStruct)
{
	render_floor(gameStruct);
	render_walls(gameStruct);
	render_player_collectibles_exit(gameStruct);
}