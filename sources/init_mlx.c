/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:40:08 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/20 13:40:11 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "../minilibx-linux/mlx.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		destroy_map(game->map);
		free(game);
		ft_printf("Couldn't initialize mlx.\n");
		exit(EXIT_FAILURE);
	}
	game->mlx_win = mlx_new_window(game->mlx, game->width * 32, \
		game->length * 32, "so_long");
	if (game->mlx_win == NULL)
	{
		destroy_map(game->map);
		free(game);
		ft_printf("Couldn't initialize window.\n");
		exit(EXIT_FAILURE);
	}
}

t_sprite	new_sprite(void *mlx, t_game *game, char *path)
{
	t_sprite	sprite;

	sprite.sprite = mlx_xpm_file_to_image(mlx, path, \
		&sprite.width, &sprite.height);
	if (sprite.sprite == NULL)
	{
		destroy_map(game->map);
		free(game);
		ft_printf("XPM failed to load.\n");
	}
	return (sprite);
}

void	init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->player = new_sprite(mlx, game, PLAYER);
	game->walls = new_sprite(mlx, game, WALL);
	game->spaces = new_sprite(mlx, game, FLOOR);
	game->collectibles = new_sprite(mlx, game, COLLECTIBLE);
	game->exit = new_sprite(mlx, game, EXIT);
}

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->collectibles.sprite);
	mlx_destroy_image(game->mlx, game->exit.sprite);
	mlx_destroy_image(game->mlx, game->spaces.sprite);
	mlx_destroy_image(game->mlx, game->player.sprite);
	mlx_destroy_image(game->mlx, game->walls.sprite);
}

void	close_game(t_game *game)
{
	ft_destroy_images(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	destroy_map(game->map);
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
