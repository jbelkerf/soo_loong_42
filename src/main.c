/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/28 14:06:44 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_the_map_valid(char *file)
{
	char	**map;

	check_the_file(file);
	map = map_to_str(file);
	check_non_wanted_symbol(map);
	check_the_walls(map);
	ckeck_the_other_symbol(map);
	is_there_valid_path(map);
	free_map(&map);
	map = map_to_str(file);
	check_collectible_valid(map);
	free_map(&map);
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
	free_map(&map);
}

void	free_and_exit(void *param)
{
	t_param	*pa;

	pa = (t_param *)param;
	free_map(&(pa->map));
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_param			param;
	t_ninja			ninja;
	t_images		imgs;

	param.ninja = &ninja;
	param.imgs = &imgs;
	if (argc != 2)
		puts_error("too many arguments");
	param.map = map_to_str(argv[1]);
	is_the_map_valid(argv[1]);
	set_window_dimension(argv[1], &(param.mlx_width), &(param.mlx_height));
	mlx = mlx_init(param.mlx_width, param.mlx_height, "jbelkerf game", false);
	if (!mlx)
		puts_error("mlx_init\n");
	get_images(mlx, &param);
	mlx_close_hook(mlx, free_and_exit, (void *)&param);
	mlx_key_hook(mlx, ft_hook, (void *)&param);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
