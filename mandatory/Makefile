SRCS = cub3d.c \
		./src/draw/utils/utils.c \
		./src/draw/utils/free_utils.c \
		./src/draw/draw_map/game.c \
		./src/draw/draw_map/render.c \
		./src/draw/draw_map/events.c \
		./src/draw/draw_map/images.c \
		./src/draw/draw_map/raycast.c \
		./src/draw/draw_map/walls_draw.c \
		./src/draw/draw_map/player.c \
		./src/init/utils/utils.c \
		./src/init/utils/ft_split_set.c \
		./src/init/infos.c \
		./src/init/init.c \
		./src/init/map.c \

OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
# CFLAGS += -fsanitize=address -g3
LIBS = libft
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = cub3d

all: $(LIBS) $(NAME)

$(NAME): $(OBJ)
	$(CC) -I src/libft $(CFLAGS) $(OBJ) src/libft/libft.a $(MLX) -lm -o $(NAME)

$(LIBS):
	make -C src/libft

clean:
	rm -rf $(OBJ)
	make -C src/libft clean

fclean: clean
	rm -rf $(NAME)
	make -C src/libft fclean

run:
	rm -rf $(OBJ)
	make $(all)
	./cub3d maps/big.cub

re: fclean all

.PHONY: all clean fclean re run