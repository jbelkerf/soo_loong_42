/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 12:46:40 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_the_map_valid(char *file)
{
	char	**map;

	map = map_to_str(file);
	check_non_wanted_symbol(map);
	check_the_walls(map);
	ckeck_the_other_symbol(map);
	is_there_valid_path(map);
	check_collectible_valid(map);
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
	t_images		imgs;


	if (argc != 2)
		puts_error("too many arguments");
	map = map_to_str(argv[1]);
	is_the_map_valid(argv[1]);
	set_window_dimension(argv[1], &width, &height);
	mlx = mlx_init(width, height, "jbelkerf", false);
	if (!mlx)
		puts_error("mlx_init\n");
	imgs.white = create_and_render(mlx, "img/white.png", '0', map);
	imgs.door = create_and_render(mlx, "img/porte.png", 'E', map);
	create_and_render(mlx, "img/wal.png", '1', map);
	imgs.collection = create_and_render(mlx, "img/flame.png", 'C', map);
	imag_tex = mlx_load_png("img/imag.png");
	imag = mlx_texture_to_image(mlx, imag_tex);
	mlx_resize_image(imag, 50, 50);
	set_ninja(imag, mlx, map, &ninja);
	param.map = map;
	param.ninja = &ninja;
	param.imgs = &imgs;
	mlx_image_to_window(mlx, imag, ninja.x * 50, ninja.y * 50);
	mlx_key_hook(mlx, ft_hook, (void *)&param);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
