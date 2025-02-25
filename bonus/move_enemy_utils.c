/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:47 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/25 16:35:28 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_up(t_param *pa, int x, int y)
{
	pa->map[y][x] = '0';
	pa->map[y - 1][x] = 'I';
	pa->imgs->enemy->instances[0].y = (y - 1) * 50;
}

void	move_enemy_down(t_param *pa, int x, int y)
{
	pa->map[y][x] = '0';
	pa->map[y + 1][x] = 'I';
	pa->imgs->enemy->instances[0].y = (y + 1) * 50;
}

void	move_enemy_right(t_param *pa, int x, int y)
{
	pa->map[y][x] = '0';
	pa->map[y][x + 1] = 'I';
	pa->imgs->enemy->instances[0].x = (x + 1) * 50;
}

void	move_enemy_left(t_param *pa, int x, int y)
{
	pa->map[y][x] = '0';
	pa->map[y][x - 1] = 'I';
	pa->imgs->enemy->instances[0].x = (x - 1) * 50;
}

int	is_there_enemy(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'I')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
