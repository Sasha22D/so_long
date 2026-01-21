/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:12:02 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/21 11:12:06 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define PLAYER "./assets/player.xpm"
# define WALL "./assets/wall.xpm"
# define FLOOR "./assets/sand.xpm"
# define COLLECTIBLE "./assets/coin.xpm"
# define EXIT "./assets/door.xpm"

# define ESC 65307

# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

typedef struct s_sprite
{
	void	*sprite;
	int		width;
	int		height;
}				t_sprite;

typedef struct s_game
{
	int			width;
	int			length;
	int			player_x;
	int			player_y;
	int			count_collectibles;
	int			count_move;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	t_sprite	walls;
	t_sprite	collectibles;
	t_sprite	player;
	t_sprite	exit;
	t_sprite	spaces;
}				t_game;

// =========MAP==========
char	**init_matrix(int fd, t_game *game);
void	fill_matrix(char **map);
// MAP CHECKS
int		check_walls(char **map);
int		check_exit_and_player(char **map, t_game *game);
void	check_collectibles(char **map, t_game *game);
int		check_path(char **map, int x, int y, t_game *game);
// MAP CHECKER
char	**map_checker(char **map, int fd, t_game *game);
// UTILS FUNCTIONS
int		lenstr(char *str);
void	destroy_map(char **map);
void	error_printer(char c);
void	error_free(int fd, t_game *game);
// MINILIBX
void	init_mlx(t_game *game);
void	init_sprites(t_game *game);
void	render_player_collectibles_exit(t_game *game);
void	render_map(t_game *game);

// MOVE PLAYER
void	move_player(t_game *game, int new_x, int new_y);

#endif
