/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:32:43 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/26 16:40:14 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "/Users/jbelkerf/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct map
{
	int	width;
	int	height;
	int	p;
	int	zero;
	int	c;
	int	e;
}	t_map;

typedef struct images
{
	mlx_image_t	*ninja;
	mlx_image_t	*col;
	mlx_image_t	*door;
	mlx_image_t	*white;
	mlx_image_t	*wal;
}	t_images;

typedef struct ninja
{
	int			x;
	int			y;
	int			move_count;
}	t_ninja;

typedef struct path
{
	int	player_x;
	int	player_y;
	int	exit_reachable;
	int	map_width;
	int	map_height;
}	t_path;

typedef struct hook_param
{
	t_ninja		*ninja;
	char		**map;
	t_images	*imgs;
	mlx_t		*mlx;
	int			mlx_width;
	int			mlx_height;
}	t_param;

void		check_the_walls(char **map);
void		puts_error(char *str);
void		free_map(char ***map);
void		ckeck_the_other_symbol(char **map);
void		is_there_valid_path(char **map);
char		**map_to_str(char *file);
void		ft_hook(mlx_key_data_t keydata, void *params);
void		check_collectible_valid(char **map);
mlx_image_t	*create_render(mlx_t *mlx, char *img_file, int symbol, char **map);
void		free_map_and_error(char *error, char ***map);
void		check_non_wanted_symbol(char **map);
void		do_click(mlx_key_data_t keydata, int *n_x, int *n_y);
void		move_the_player(t_param *param, int new_x, int new_y);
void		eat_col(mlx_t *mlx, t_param *param, int new_x, int new_y);
int			can_go_out(char **map);
void		get_images(mlx_t *mlx, t_param *param);
void		check_the_file(char *file);

#endif