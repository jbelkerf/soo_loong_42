/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:16:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/23 15:19:34 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	mlx_image_t	*img;

	find_ninja(param, param->map);
	param->mlx = mlx;
	param->ninja->move_count = 0;
	param->img_left = "textures/P_left.png";
	param->img_right = "textures/P_right.png";
	param->img_down = "textures/P_down.png";
	param->img_up = "textures/P_up.png";
	param->img_file = param->img_down;
	img = create_render(mlx, "textures/0.png", '0', param->map);
	param->imgs->white = img;
	img = create_render(mlx, "textures/E.png", 'E', param->map);
	param->imgs->door = img;
	img = create_render(mlx, "textures/C.png", 'C', param->map);
	param->imgs->col = img;
	img = create_render(mlx, "textures/1.png", '1', param->map);
	param->imgs->wal = img;
	img = create_render(mlx, "textures/P_down.png", 'P', param->map);
	param->imgs->ninja = img;
}
