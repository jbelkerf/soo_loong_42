/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_the_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:56:28 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/24 11:56:47 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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