/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:24:42 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/19 21:13:48 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *params)
{
	t_param	*param;
	mlx_t	*mlx;

	param = (t_param *)params;
	mlx = param->ninja->mlx;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);

	// Temporary position
	int new_x = param->ninja->x;
	int new_y = param->ninja->y;

	if (keydata.action == MLX_PRESS) // Move only when key is first pressed
	{
		if (keydata.key == MLX_KEY_UP)
			new_y--;
		if (keydata.key == MLX_KEY_DOWN)
			new_y++;
		if (keydata.key == MLX_KEY_LEFT)
			new_x--;
		if (keydata.key == MLX_KEY_RIGHT)
			new_x++;

		// Check if new position is not a wall
		if (param->map[new_y][new_x] != '1')
		{
			param->ninja->x = new_x;
			param->ninja->y = new_y;
		}

		// Update player position in pixels
		param->ninja->img->instances[0].x = param->ninja->x * 50;
		param->ninja->img->instances[0].y = param->ninja->y * 50;
	}
}



