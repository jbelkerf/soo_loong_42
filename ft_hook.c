/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:24:42 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 16:50:24 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(mlx_t *mlx)
{
	mlx_close_window(mlx);
	system("clear");
	ft_printf("congrats!\n");
	exit(0);
}


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

void	ft_hook(mlx_key_data_t keydata, void *params)
{
	t_param	*param;
	mlx_t	*mlx;
	int		new_x;
	int		new_y;
	int		move_count;

	param = (t_param *)params;
	mlx = param->mlx;
	move_count = 0;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	new_x = param->ninja->x;
	new_y = param->ninja->y;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		do_the_click(keydata, &new_x, &new_y);
		if (param->map[new_y][new_x] == 'E' && can_go_out(param->map))
			win(mlx);
		if (param->map[new_y][new_x] != '1' && param->map[new_y][new_x] != 'E')
		{
			if (param->map[new_y][new_x] == 'C')
				eat_the_collectible(mlx, param, new_x, new_y);
			move_the_player(param, new_x, new_y);
		}
		param->imgs->ninja->instances[0].x = param->ninja->x * 50;
		param->imgs->ninja->instances[0].y = param->ninja->y * 50;
		print_map(param->map);
		ft_printf("\nmoves are : %i\n",param->ninja->move_count);
	}
}
