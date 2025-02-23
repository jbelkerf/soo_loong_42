/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/23 17:38:34 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
}

void	ft_find_ninja(char **map, int *x, int *y)
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
				*x = j;
				*y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

char	**set_the_enemy(t_param *param)
{
	int	x;
	int	y;
	int	i;

	i = 1;
	ft_find_ninja(param->map, &x, &y);
	while (param->map[y][x - i] == '0')
		i++;
	if (i > 1)
	{
		param->map[y][x - i + 1] = 'I';
		return (param->map);
	}
	while (param->map[y][x + i] == '0')
		i++;
	if (i > 1)
	{
		param->map[y][x + i - 1] = 'I';
		return (param->map);
	}
	while (param->map[y - i][x] == '0')
		i++;
	if (i > 1)
	{
		param->map[y - i + 1][x] = 'I';
		return (param->map);
	}
	while (param->map[y + i][x] == '0')
		i++;
	if (i > 1)
	{
		param->map[y + i - 1][x] = 'I';
		return (param->map);
	}
	return (param->map);
}

void print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
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
	param.map = set_the_enemy(&param);
	print_map(param.map);
	get_images(mlx, &param);
	mlx_key_hook(mlx, ft_hook, (void *)&param);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
