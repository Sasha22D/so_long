NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Werror -Wextra -Wall

INCLUDE_DIR = "./includes"

SRC_FILES = main.c \
			map_checks.c \
			map_checker.c \
			init_matrix.c \
			init_mlx.c \
			move_player.c \
			render_map.c \
			utils.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re