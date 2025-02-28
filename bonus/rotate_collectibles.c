/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:40:37 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/28 15:46:39 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_coll_file(t_param *pa)
{
	if (!ft_strcmp(pa->coll_file, "textures/C.png"))
		pa->coll_file = "textures/C_0.png";
	else if (!ft_strcmp(pa->coll_file, "textures/C_0.png"))
		pa->coll_file = "textures/C_1.png";
	else if (!ft_strcmp(pa->coll_file, "textures/C_1.png"))
		pa->coll_file = "textures/C_2.png";
	else if (!ft_strcmp(pa->coll_file, "textures/C_2.png"))
		pa->coll_file = "textures/C.png";
}

void	rotate_the_collectibles(t_param *pa)
{
	static int	i;

	if (i % 2 == 0)
	{
		set_coll_file(pa);
		mlx_delete_image(pa->mlx, pa->imgs->col);
		pa->imgs->col = create_render(pa->mlx, pa->coll_file, 'C', pa->map);
	}
	i++;
}
