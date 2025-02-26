/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:46 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/26 17:45:46 by jbelkerf         ###   ########.fr       */
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

void	check_lose(t_param *pa, int where_to_move, int x, int y)
{
	if (where_to_move == 0 && pa->map[y - 1][x] == 'P')
		lose(pa->mlx, pa);
	if (where_to_move == 2 && pa->map[y + 1][x] == 'P')
		lose(pa->mlx, pa);
	if (where_to_move == 1 && pa->map[y][x + 1] == 'P')
		lose(pa->mlx, pa);
	if (where_to_move == 3 && pa->map[y][x - 1] == 'P')
		lose(pa->mlx, pa);
}

int	movee(t_param *pa, int where_to_move, int x, int y)
{
	if (where_to_move == 0 && pa->map[y - 1][x] == '0')
		move_enemy_up(pa, x, y);
	else if (where_to_move == 2 && pa->map[y + 1][x] == '0')
		move_enemy_down(pa, x, y);
	else if (where_to_move == 1 && pa->map[y][x + 1] == '0')
		move_enemy_right(pa, x, y);
	else if (where_to_move == 3 && pa->map[y][x - 1] == '0')
		move_enemy_left(pa, x, y);
	else
		return (set_the_move_derection(where_to_move));
	return (where_to_move);
}

void	ft_move_enemy(void *param)
{
	t_param			*pa;
	int				x;
	int				y;
	static int		where_to_move;
	static int		random;

	pa = (t_param *)param;
	if (!is_there_enemy(pa->map))
		return ;
	find_enemy(pa->map, &x, &y);
	if ((pa->counter % 17) == 0)
	{
		if (random == pa->mlx_width / 50 - 2)
		{
			random = 0;
			where_to_move = (where_to_move + pa->counter) % 3;
		}
		check_lose(pa, where_to_move, x, y);
		where_to_move = movee(pa, where_to_move, x, y);
		random++;
	}
	pa->counter++;
}
