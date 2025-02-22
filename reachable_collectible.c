/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachable_collectible.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:27:49 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 12:29:39 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectible(char **map)
{
	int	c;
	int	i;
	int	j;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	get_player_cordination(int *x, int *y, char **map)
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

void	reach_collectible(char **map, int *collectible_reached, int x, int y)
{
	if (map[y][x] == 'C')
		*collectible_reached = *collectible_reached + 1;
	if (map[y][x] == '1' || map[y][x] == 't')
		return ;
	map[y][x] = 't';
	reach_collectible(map, collectible_reached, x - 1, y);
	reach_collectible(map, collectible_reached, x + 1, y);
	reach_collectible(map, collectible_reached, x, y + 1);
	reach_collectible(map, collectible_reached, x, y - 1);
}

void	check_collectible_valid(char **map)
{
	int	collectible_number;
	int	collectible_can_be_reach;
	int	player_x;
	int	player_y;

	collectible_can_be_reach = 0;
	collectible_number = count_collectible(map);
	get_player_cordination(&player_x, &player_y, map);
	reach_collectible(map, &collectible_can_be_reach, player_x, player_y);
	if (collectible_can_be_reach != collectible_number)
		puts_error("there is collectible can't be reached");
}
