#include "so_long.h"

void	is_map_valid(t_game *gameStruct, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	(*gameStruct).map = map_checker(NULL, fd, gameStruct);
	if ((*gameStruct).map == NULL)
	{
		error_free(fd, gameStruct);
		exit(EXIT_FAILURE);
	}
}

int	close_window(int keycode, t_game *gameStruct)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(gameStruct->mlx, gameStruct->mlx_win);
		free(gameStruct);
		destroy_map(gameStruct->map);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W || keycode == UP)
		move_player(gameStruct, gameStruct->player_x - 1, gameStruct->player_y);
	if (keycode == A || keycode == LEFT)
		move_player(gameStruct, gameStruct->player_x, gameStruct->player_y - 1);
	if (keycode == S || keycode == DOWN)
		move_player(gameStruct, gameStruct->player_x + 1, gameStruct->player_y);
	if (keycode == D || keycode == RIGHT)
		move_player(gameStruct, gameStruct->player_x, gameStruct->player_y + 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*gameStruct;
	(void)ac;

	gameStruct = malloc(sizeof(t_game));
	//ARGS CHECKER
	is_map_valid(gameStruct, av[1]);
	init_mlx(gameStruct);
	init_sprites(gameStruct);
	render_map(gameStruct);
	mlx_hook(gameStruct->mlx_win, 2, 1L<<0, close_window, gameStruct);
	mlx_loop(gameStruct->mlx);
	destroy_map(gameStruct->map);
	free(gameStruct);
}

