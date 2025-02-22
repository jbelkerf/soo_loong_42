/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:45:03 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/22 18:20:44 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	puts_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	ckeck_the_other_symbol(char **map)
{
	t_map	symbol;
	int		i;
	int		j;

	i = 0;
	symbol.p = 0;
	symbol.c = 0;
	symbol.e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				symbol.p++;
			else if (map[i][j] == 'E')
				symbol.e++;
			else if (map[i][j] == 'C')
				symbol.c++;
			j++;
		}
		i++;
	}
	if (symbol.p != 1 || symbol.e != 1 || symbol.c < 1)
		free_map_and_error("too many P or E or no C", &map);
}
