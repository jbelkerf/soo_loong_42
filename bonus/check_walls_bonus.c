/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:11:19 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 19:59:38 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

void	is_rectangular(char **map)
{
	int	width;
	int	i;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (width != ft_strlen(map[i]))
		{
			free_map(&map);
			puts_error("map not rectangular");
		}
		i++;
	}
}

int	is_there_enough_walls(char *line, int check_all)
{
	int	i;

	i = 0;
	if (check_all)
	{
		while (line[i])
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	else if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
	{
		return (0);
	}
	return (1);
}

void	is_surrounded_by_walls(char **map)
{
	int		i;

	if (!is_there_enough_walls(map[0], 1))
		free_map_and_error("map not surrounded", &map);
	i = 1;
	while (map[i] && map[i + 1])
	{
		if (!is_there_enough_walls(map[i], 0))
			free_map_and_error("map not surrounded", &map);
		i++;
	}
	if (!is_there_enough_walls(map[i], 1))
		free_map_and_error("map not surrounded", &map);
}

void	check_the_walls(char **map)
{
	is_rectangular(map);
	is_surrounded_by_walls(map);
}
