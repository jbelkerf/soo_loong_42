/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_non_wanted_symbols.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:46:42 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 17:13:38 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_and_error(char *error, char **map)
{
	free_map(map);
	puts_error(error);
}

void	check_non_wanted_symbol(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
			&& map[i][j] != 'P' && map[i][j] != 'C')
				free_map_and_error("non valid symbol", map);
			j++;
		}
		i++;
	}
}
