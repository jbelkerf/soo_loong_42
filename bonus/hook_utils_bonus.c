/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:46:23 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 20:16:46 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
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

void	do_the_click(mlx_key_data_t keydata, int *n_x, int *n_y)
{
	if (keydata.key == MLX_KEY_UP)
		*n_y = *n_y - 1;
	if (keydata.key == MLX_KEY_DOWN)
		*n_y = *n_y + 1;
	if (keydata.key == MLX_KEY_LEFT)
		*n_x = *n_x - 1;
	if (keydata.key == MLX_KEY_RIGHT)
		*n_x = *n_x + 1;
}

void	move_the_player(t_param *param, int new_x, int new_y)
{
	param->map[param->ninja->y][param->ninja->x] = '0';
	param->map[new_y][new_x] = 'P';
	param->ninja->x = new_x;
	param->ninja->y = new_y;
	param->ninja->move_count++;
}

void	eat_col(mlx_t *mlx, t_param *param, int new_x, int new_y)
{
	mlx_image_t	*img;

	param->map[new_y][new_x] = '0';
	mlx_delete_image(mlx, param->imgs->col);
	mlx_delete_image(mlx, param->imgs->white);
	param->imgs->col = create_render(mlx, "textures/C.png", 'C', param->map);
	param->imgs->white = create_render(mlx, "textures/0.png", '0', param->map);
	param->imgs->ninja = create_render(mlx, "textures/P.png", 'P', param->map);
	if (can_go_out(param->map))
	{
		mlx_delete_image(mlx, param->imgs->door);
		img = create_render(mlx, "textures/E2.png", 'E', param->map);
		param->imgs->door = img;
	}
}
