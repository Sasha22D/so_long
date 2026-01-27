NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = ./minilibx-linux

CC = cc
CFLAGS = -g3 -Werror -Wextra -Wall

INCLUDE_DIR = ./includes

SRC_FILES = sources/main.c \
			sources/check_column.c \
            sources/init_matrix.c \
            sources/init_mlx.c \
            sources/map_checks.c \
            sources/map_checker.c \
            sources/move_player.c \
            sources/render_map.c \
            sources/utils.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)

LDFLAGS = -L$(LIBFT_DIR) -lft \
          -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lbsd

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(MAKE) -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
