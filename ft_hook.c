/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:24:42 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/19 21:09:05 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *params)
{
	t_param	*param;
	mlx_t	*mlx;

	param = (t_param *)params;
	mlx = param->ninja->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	int new_x = param->ninja->x;
	int new_y = param->ninja->y;

	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		new_y--;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		new_y++;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		new_x--;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		new_x++;
	if (param->map[new_y][new_x] != '1')
	{
		param->ninja->x = new_x;
		param->ninja->y = new_y;
	}
	param->ninja->img->instances[0].x = param->ninja->x * 50;
	param->ninja->img->instances[0].y = param->ninja->y * 50;
}


