# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 17:21:12 by jbelkerf          #+#    #+#              #
#    Updated: 2025/02/23 15:33:17 by jbelkerf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror  -I MLX42/include/MLX42 -I libft/include 
LFLAGS = -L MLX42/build -L /Users/jbelkerf/.brew/opt/glfw/lib -L libft -l mlx42 -l glfw -l ft \
		 -framework Cocoa -framework OpenGL -framework IOKit

MLX = MLX42/build/libmlx42.a

LIBFT = libft/libft.a 

SRC = src/main.c src/get_images.c src/hook_utils.c src/check_non_wanted_symbols.c \
src/reachable_collectible.c src/create_and_render_img.c src/ft_hook.c src/map_to_str.c \
src/check_valid_path.c src/check_walls.c src/check_symbols.c gnl/get_next_line.c \
gnl/get_next_line_utils.c src/check_file_format.c

SRC_BONUS = bonus/check_file_format_bonus.c bonus/check_non_wanted_symbols_bonus.c \
bonus/check_symbols_bonus.c bonus/check_valid_path_bonus.c bonus/check_walls_bonus.c \
bonus/create_and_render_img_bonus.c bonus/ft_hook_bonus.c bonus/get_images_bonus.c \
bonus/hook_utils_bonus.c bonus/main_bonus.c bonus/map_to_str_bonus.c \
bonus/reachable_collectible_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c bonus/itoa_bonus.c
 

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