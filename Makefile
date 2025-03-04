CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_LINK =  -L/usr/include/minilibx-linux -lmlx -lXext -lX11

NAME = fractol
NAME_B = fractol_bonus
SRCS = julia.c main.c utils.c mandelbrot.c hook.c render.c exit.c
SRCSB = bonus/julia_bonus.c bonus/main_bonus.c bonus/utils_bonus.c bonus/mandelbrot_bonus.c \
		bonus/hook_bonus.c bonus/tricorn.c bonus/render_bonus.c bonus/exit_bonus.c
OBJ = $(SRCS:.c=.o)
OBJB = $(SRCSB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LINK)

bonus: $(NAME) $(NAME_B)

$(NAME_B): $(OBJB)
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJB) $(MLX_LINK)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus

