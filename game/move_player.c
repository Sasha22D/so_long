/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:40:12 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/20 13:40:16 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	char	**map;

	map = game->map;
	if (new_x >= game->length || new_x < 0 || new_y >= game->width || new_y < 0)
		return ;
	if (map[new_x][new_y] == 'E' && game->count_collectibles == 0)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		destroy_map(game->map);
		free(game);
		exit(EXIT_SUCCESS);
	}
	if (map[new_x][new_y] == '0' || map[new_x][new_y] == 'C')
	{
		if (map[new_x][new_y] == 'C')
			game->count_collectibles--;
		map[game->player_x][game->player_y] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		map[new_x][new_y] = 'P';
		ft_printf("Moves: %s\n", ft_itoa(game->count_move++));
		render_map(game);
	}
}
