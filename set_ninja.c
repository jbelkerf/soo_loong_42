/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ninja.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:36:06 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/20 18:36:23 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_ninja(t_ninja *ninja, char **map)
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
				ninja->x = j;
				ninja->y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	set_ninja(mlx_image_t *img, mlx_t *mlx, char **map, t_ninja *ninja)
{
	ninja->img = img;
	ninja->mlx = mlx;
	find_ninja(ninja, map);
	ninja->move_count = 0;
}
