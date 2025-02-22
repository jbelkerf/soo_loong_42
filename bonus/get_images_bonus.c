/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:16:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 19:59:29 by jbelkerf         ###   ########.fr       */
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
	find_ninja(param, param->map);
	param->mlx = mlx;
	param->ninja->move_count = 0;
	param->imgs->white = create_render(mlx, "img/0.png", '0', param->map);
	param->imgs->door = create_render(mlx, "img/E.png", 'E', param->map);
	param->imgs->col = create_render(mlx, "img/C.png", 'C', param->map);
	param->imgs->wal = create_render(mlx, "img/1.png", '1', param->map);
	param->imgs->ninja = create_render(mlx, "img/P.png", 'P', param->map);
}
