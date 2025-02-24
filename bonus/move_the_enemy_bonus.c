/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:46 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/24 15:08:29 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	set_the_move_derection(int derction)
{
	if (derction == 0)
		return (2);
	if (derction == 2)
		return (0);
	if (derction == 1)
		return (3);
	if (derction == 3)
		return (1);
	return (0);
}

void	find_enemy(char **map, int *x, int *y)
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

void    ft_move_enemy(void *param)
{
	t_param			*pa;
	int				x;
	int				y;
	static int		counter;
	static int		where_to_move;
	static int		random;

	pa = (t_param *)param;
	find_enemy(pa->map, &x, &y);
	if ((counter % 17) == 0)
	{
		if (random == 17)
		{
			random = 0;
			where_to_move = (where_to_move + counter ) % 3;
		}
		ft_printf("%d\n", where_to_move);
		if (where_to_move == 0 && pa->map[y - 1][x] == '0')
		{
			pa->map[y][x] = '0';
			pa->map[y - 1][x] = 'I';
			pa->imgs->enemy->instances[0].y = (y - 1) * 50;
		}
		else if (where_to_move == 2 && pa->map[y + 1][x] == '0')
		{
			pa->map[y][x] = '0';
			pa->map[y + 1][x] = 'I';
			pa->imgs->enemy->instances[0].y = (y + 1) * 50;
		}
		else if (where_to_move == 1 && pa->map[y][x + 1] == '0')
		{
			pa->map[y][x] = '0';
			pa->map[y][x + 1] = 'I';
			pa->imgs->enemy->instances[0].x = (x + 1) * 50;
		}
		else if (where_to_move == 3 && pa->map[y][x - 1] == '0')
		{
			pa->map[y][x] = '0';
			pa->map[y][x - 1] = 'I';
			pa->imgs->enemy->instances[0].x = (x - 1) * 50;
		}
		else
			where_to_move = set_the_move_derection(where_to_move);
		random++;
	}
	counter++;
}