/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_the_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:56:28 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/25 15:45:02 by jbelkerf         ###   ########.fr       */
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

int	check_left_and_right(t_param **param, int x, int y)
{
	int	i;

	i = 1;
	while ((*param)->map[y][x - i] == '0')
		i++;
	if (i > 1)
	{
		(*param)->map[y][x - i + 1] = 'I';
		return (1);
	}
	while ((*param)->map[y][x + i] == '0')
		i++;
	if (i > 1)
	{
		(*param)->map[y][x + i - 1] = 'I';
		return (1);
	}
	return (0);
}

int	check_up_and_down(t_param **param, int x, int y)
{
	int	i;

	i = 1;
	while ((*param)->map[y - i][x] == '0')
		i++;
	if (i > 1)
	{
		(*param)->map[y - i + 1][x] = 'I';
		return (1);
	}
	while ((*param)->map[y + i][x] == '0')
		i++;
	if (i > 1)
	{
		(*param)->map[y + i - 1][x] = 'I';
		return (1);
	}
	return (0);
}

char	**set_the_enemy(t_param *param)
{
	int	x;
	int	y;

	param->counter = 0;
	ft_find_ninja(param->map, &x, &y);
	if (check_left_and_right(&param, x, y))
		return (param->map);
	if (check_up_and_down(&param, x, y))
		return (param->map);
	return (param->map);
}
