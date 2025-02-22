CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(MLX_DIR)

MLX_DIR = /usr/include/minilibx-linux
MLX_LIB = /usr/include/minilibx-linux/libmlx_Linux.a

MLX_INCLUDE = -I$(MLX_DIR)
MLX_LINK = $(MLX_LIB) -L/usr/lib -lXext -lX11 -lm

NAME = fractol
SRCS = julia.c main.c utils.c mandelbrot.c hook.c burning_ship.c render.c exit.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LINK) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
