/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:24:42 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 11:41:36 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	can_go_out(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_hook(mlx_key_data_t keydata, void *params)
{
	t_param	*param;
	mlx_t	*mlx;
	int		new_x;
	int		new_y;
	int		move_count;

	param = (t_param *)params;
	mlx = param->ninja->mlx;
	move_count = 0;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	new_x = param->ninja->x;
	new_y = param->ninja->y;

	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_UP)
			new_y--;
		if (keydata.key == MLX_KEY_DOWN)
			new_y++;
		if (keydata.key == MLX_KEY_LEFT)
			new_x--;
		if (keydata.key == MLX_KEY_RIGHT)
			new_x++;
		if (param->map[new_y][new_x] == 'E' && can_go_out(param->map))
		{
			mlx_close_window(mlx);
			system("clear");
			ft_printf("congrats\n");
			exit (0);
		}
		if (param->map[new_y][new_x] != '1' && param->map[new_y][new_x] != 'E')
		{
			if (param->map[new_y][new_x] == 'C')
			{
				param->map[new_y][new_x] = '0';
				mlx_delete_image(mlx, param->imgs->collection);
				mlx_delete_image(mlx, param->imgs->white);
				param->imgs->collection = create_and_render(mlx, "img/flame.png", 'C', param->map);
				param->imgs->white = create_and_render(mlx, "img/white.png", '0', param->map);
				param->ninja->img = create_and_render(mlx, "img/imag.png", 'P', param->map);
				if (can_go_out(param->map))
				{
					mlx_delete_image(mlx, param->imgs->door);
					param->imgs->door = create_and_render(mlx, "img/portal.png", 'E', param->map);
				}
			}
			param->map[param->ninja->y][param->ninja->x] = '0';
			param->map[new_y][new_x] = 'P';
			param->ninja->x = new_x;
			param->ninja->y = new_y;
			param->ninja->move_count++;
			system("clear");
		}
		param->ninja->img->instances[0].x = param->ninja->x * 50;
		param->ninja->img->instances[0].y = param->ninja->y * 50;
		print_map(param->map);
		ft_printf("\nmoves are : %i\n",param->ninja->move_count);
		//print_map(param->map);
	}
}
