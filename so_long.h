/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:35:15 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/19 21:16:02 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "MLX42.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"


typedef struct map
{
	int	width;
	int	height;
	int	p;
	int	zero;
	int	c;
	int	e;
}	t_map;

typedef struct ninja
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x;
	int			y;
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
	t_ninja	*ninja;
	char	**map;
}	t_param;

void	check_the_walls(char **map);
void	puts_error(char *str);
void	free_map(char **map);
void	free_map(char **map);
void	ckeck_the_other_symbol(char **map);
void	is_there_valid_path(char **map);
char	**map_to_str(char *file);
void	ft_hook(mlx_key_data_t keydata, void *params);
void	set_ninja(mlx_image_t *img, mlx_t *mlx, char **map, t_ninja *ninja);
void	create_and_render(mlx_t *mlx, char *img_file, int symbol, char **map);

#endif