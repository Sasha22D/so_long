/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:39:41 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/20 13:39:47 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	is_map_valid(t_game *game, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	(*game).map = map_checker(NULL, fd, game);
	if ((*game).map == NULL)
	{
		error_free(fd, game);
		exit(EXIT_FAILURE);
	}
}

int	input_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == W || keycode == UP)
		move_player(game, game->player_x - 1, game->player_y);
	if (keycode == A || keycode == LEFT)
		move_player(game, game->player_x, game->player_y - 1);
	if (keycode == S || keycode == DOWN)
		move_player(game, game->player_x + 1, game->player_y);
	if (keycode == D || keycode == RIGHT)
		move_player(game, game->player_x, game->player_y + 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		exit(EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	is_map_valid(game, av[1]);
	init_mlx(game);
	init_sprites(game);
	render_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, input_handler, game);
	mlx_loop(game->mlx);
	ft_destroy_images(game);
	destroy_map(game->map);
	free(game);
}
