NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror  -I MLX42/include/MLX42 -I libft/include 
LFLAGS = -L MLX42/build -L /Users/jbelkerf/.brew/opt/glfw/lib -L libft -l mlx42 -l glfw -l ft \
		 -framework Cocoa -framework OpenGL -framework IOKit

MLX = MLX42/build/libmlx42.a

LIBFT = libft/libft.a 

SRC = main.c gnl/get_next_line.c gnl/get_next_line_utils.c

SRC_BONUS = 

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LFLAGS) -o $(NAME)

bonus: $(MLX) $(LIBFT) $(SRC_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) $(LFLAGS) -o $(NAME)

$(MLX):
	make -C MLX42/build

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	make -C MLX42/build clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus