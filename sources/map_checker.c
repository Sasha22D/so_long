/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:39:54 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/20 13:39:57 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**map_checker(char **map, int fd, t_game *game, char *path)
{
	map = init_matrix(fd, game);
	if (map == NULL)
		return (destroy_map(map), error_printer('m'), NULL);
	fill_matrix(map, path);
	if (check_wrong_characters(map) == -1 || check_walls(map) == -1)
		return (destroy_map(map), error_printer('w'), NULL);
	if (check_exit_and_player(map) == -1)
		return (destroy_map(map), error_printer('e'), NULL);
	check_collectibles(map, game);
	if (game->count_collectibles == 0)
		return (destroy_map(map), error_printer('c'), NULL);
	if (check_path(map, game->player_x, game->player_y, game) == -1)
		return (destroy_map(map), error_printer('p'), NULL);
	return (map);
}
