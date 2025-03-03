/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:35:15 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/28 15:43:26 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	mlx_image_t	*count;
	mlx_image_t	*enemy;
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
	mlx_t		*mlx;
	t_ninja		*ninja;
	t_images	*imgs;
	int			mlx_width;
	int			mlx_height;
	int			counter;
	char		**map;
	char		*img_file;
	char		*img_right;
	char		*img_up;
	char		*img_down;
	char		*img_left;
	char		*coll_file;
}	t_param;

mlx_image_t	*create_render(mlx_t *mlx, char *img_file, int symbol, char **map);
void		check_the_walls(char **map);
void		puts_error(char *str);
void		free_map(char ***map);
void		ckeck_the_other_symbol(char **map);
void		is_there_valid_path(char **map);
void		ft_hook(mlx_key_data_t keydata, void *params);
void		check_collectible_valid(char **map);
void		check_lose(t_param *pa, int where_to_move, int x, int y);
void		free_map_and_error(char *error, char ***map);
void		do_click(mlx_key_data_t keydata, int *n_x, int *n_y, t_param *pa);
void		check_non_wanted_symbol(char **map);
void		move_the_player(t_param *param, int new_x, int new_y);
void		eat_col(mlx_t *mlx, t_param *param, int new_x, int new_y);
void		get_images(mlx_t *mlx, t_param *param);
void		move_enemy_up(t_param *pa, int x, int y);
void		move_enemy_right(t_param *pa, int x, int y);
void		ft_move_enemy(void *param);
void		move_enemy_down(t_param *pa, int x, int y);
void		move_enemy_left(t_param *pa, int x, int y);
void		rotate_the_collectibles(t_param *pa);
void		lose(mlx_t *mlx, t_param *pa);
void		check_the_file(char *file);
char		*itoa(int nbr);
char		**map_to_str(char *file);
char		**set_the_enemy(t_param *param);
int			set_the_move_derection(int derction);
int			can_go_out(char **map);
int			is_there_enemy(char **map);

#endif