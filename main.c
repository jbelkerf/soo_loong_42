/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/19 21:03:34 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	is_the_map_valid(char *file)
{
	char	**map;

	map = map_to_str(file);
	check_the_walls(map);
	ckeck_the_other_symbol(map);
	is_there_valid_path(map);
	free_map(map);
}

void	set_window_dimension(char *file, int *width, int *height)
{
	char	**map;
	int		i;

	i = 0;
	map = map_to_str(file);
	*width = 50 * ft_strlen(map[0]);
	while (map[i])
		i++;
	*height = 50 * i;
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_ninja			ninja;
	mlx_texture_t	*imag_tex;
	mlx_image_t		*imag;
	int				width;
	int				height;
	char			**map;
	t_param			param;


	if (argc != 2)
		puts_error("too many arguments");
	map = map_to_str(argv[1]);
	is_the_map_valid(argv[1]);
	set_window_dimension(argv[1], &width, &height);
	mlx = mlx_init(width, height, "jbelkerf", false);
	if (!mlx)
		puts_error("mlx_init\n");
	create_and_render(mlx, "wal.png", '1', map);
	create_and_render(mlx, "flame.png", 'C', map);
	imag_tex = mlx_load_png("img/imag.png");
	imag = mlx_texture_to_image(mlx, imag_tex);
	mlx_resize_image(imag, 50, 50);
	mlx_image_to_window(mlx, imag, 50, 50);
	set_ninja(imag, mlx, map, &ninja);
	param.map = map;
	param.ninja = &ninja;
	mlx_loop_hook(mlx, ft_hook, (void *)&param);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
