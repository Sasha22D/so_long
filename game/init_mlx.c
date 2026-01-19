#include "so_long.h"
#include "../minilibx-linux/mlx.h"

void	init_mlx(t_game *gameStruct)
{
	gameStruct->mlx = mlx_init();
	if (gameStruct->mlx == NULL)
	{
		free(gameStruct);
		destroy_map(gameStruct->map);
		ft_printf("Couldn't initialize mlx.\n");
		exit(EXIT_FAILURE);
	}
	gameStruct->mlx_win = mlx_new_window(gameStruct->mlx, gameStruct->width * 32, gameStruct->length * 32, "so_long");
	if (gameStruct->mlx_win == NULL)
	{
		free(gameStruct);
		destroy_map(gameStruct->map);
		ft_printf("Couldn't initialize window.\n");
		exit(EXIT_FAILURE);
	}
}

t_sprite	new_sprite(void *mlx, t_game *gameStruct, char *path)
{
	t_sprite	sprite;

	sprite.sprite = mlx_xpm_file_to_image(mlx, path, &sprite.width, &sprite.height);
	if (sprite.width == 5)
	{
		free(gameStruct);
		destroy_map(gameStruct->map);
		ft_printf("XPM failed to load.\n");
	}
	return (sprite);
}

void	init_sprites(t_game *gameStruct)
{
	void	*mlx;

	mlx = gameStruct->mlx;
	gameStruct->player = new_sprite(mlx, gameStruct, PLAYER);
	gameStruct->walls = new_sprite(mlx, gameStruct, WALL);
	gameStruct->spaces = new_sprite(mlx, gameStruct, FLOOR);
	gameStruct->collectibles = new_sprite(mlx, gameStruct, COLLECTIBLE);
	gameStruct->exit = new_sprite(mlx, gameStruct, EXIT);
}

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
