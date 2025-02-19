/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_render_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:52:12 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/19 20:02:53 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(char **map, mlx_t *mlx, mlx_image_t *wall_img, char symbol)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == symbol)
				mlx_image_to_window(mlx, wall_img, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	create_and_render(mlx_t *mlx, char *img_file, int symbol, char **map)
{
	mlx_texture_t	*img_tex;
	mlx_image_t		*img;

	img_tex = mlx_load_png(img_file);
	img = mlx_texture_to_image(mlx, img_tex);
	mlx_resize_image(img, 50, 50);
	render_img(map, mlx, img, symbol);
}
