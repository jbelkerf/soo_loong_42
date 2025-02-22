/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 17:02:03 by jbelkerf         ###   ########.fr       */
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

void	find_ninja(t_param *param, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				param->ninja->x = j;
				param->ninja->y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	get_images(mlx_t *mlx, t_param *param)
{
	find_ninja(param, param->map);
	param->mlx = mlx;
	param->ninja->move_count = 0;
	param->imgs->white = create_render(mlx, "img/0.png", '0', param->map);
	param->imgs->door = create_render(mlx, "img/E.png", 'E', param->map);
	param->imgs->col = create_render(mlx, "img/C.png", 'C', param->map);
	param->imgs->wal = create_render(mlx, "img/1.png", '1', param->map);
	param->imgs->ninja = create_render(mlx, "img/P.png", 'P', param->map);
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
	mlx_key_hook(mlx, ft_hook, (void *)&param);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
