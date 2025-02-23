/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:24:42 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/23 17:46:07 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	win(mlx_t *mlx)
{
	mlx_close_window(mlx);
	ft_printf("congrats!\n");
	exit(0);
}

void lose(mlx_t *mlx)
{
	mlx_close_window(mlx);
	ft_printf("you lose!\n");
	exit(1);
}

void	ft_hook(mlx_key_data_t keydata, void *params)
{
	t_param	*param;
	int		new_x;
	int		new_y;

	param = (t_param *)params;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(param->mlx);
	new_x = param->ninja->x;
	new_y = param->ninja->y;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		do_the_click(keydata, &new_x, &new_y, param);
		if (param->map[new_y][new_x] == 'E' && can_go_out(param->map))
			win(param->mlx);
		if (param->map[new_y][new_x] == 'I')
			lose(param->mlx);
		if (param->map[new_y][new_x] != '1' && param->map[new_y][new_x] != 'E')
		{
			if (param->map[new_y][new_x] == 'C')
				eat_col(param->mlx, param, new_x, new_y);
			move_the_player(param, new_x, new_y);
		}
		param->imgs->ninja->instances[0].x = param->ninja->x * 50;
		param->imgs->ninja->instances[0].y = param->ninja->y * 50;
		ft_printf("\033[2J\033[Hmoves are : %i\n", param->ninja->move_count);
	}
}
