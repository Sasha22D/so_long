/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:40:18 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/20 13:40:20 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	render_floor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->spaces.sprite, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	render_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->walls.sprite, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	render_player_collectibles_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->player.sprite, j * 32, i * 32);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->exit.sprite, j * 32, i * 32);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->collectibles.sprite, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	render_map(t_game *game)
{
	render_floor(game);
	render_walls(game);
	render_player_collectibles_exit(game);
}
