/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:20:49 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 18:21:03 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_path *path, char **map)
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
				path->player_x = j;
				path->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	fill_path(t_path *path, char **map)
{
	int	i;

	find_player(path, map);
	path->map_width = ft_strlen(map[0]);
	i = 0;
	while (map[i])
		i++;
	path->map_height = i;
	path->exit_reachable = 0;
}

void	take_the_path(t_path *path, char **map, int x, int y)
{
	if (map[y][x] == 'E')
	{
		path->exit_reachable = 1;
		map[y][x] = 'd';
		map[path->player_y][path->player_y] = 'P';
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 't' || map[y][x] == 'd')
	{
		map[path->player_y][path->player_y] = 'P';
		return ;
	}
	map[y][x] = 't';
	take_the_path(path, map, x - 1, y);
	take_the_path(path, map, x + 1, y);
	take_the_path(path, map, x, y - 1);
	take_the_path(path, map, x, y + 1);
}

void	is_there_valid_path(char **map)
{
	t_path	path;

	fill_path(&path, map);
	take_the_path(&path, map, path.player_x, path.player_y);
	if (!path.exit_reachable)
	{
		free_map(&map);
		puts_error("the player can't get to the exit");
	}
}
