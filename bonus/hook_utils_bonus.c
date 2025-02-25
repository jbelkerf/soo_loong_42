/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:46:23 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/25 13:42:59 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	can_go_out(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	do_click(mlx_key_data_t keydata, int *n_x, int *n_y, t_param *pa)
{
	mlx_delete_image(pa->mlx, pa->imgs->ninja);
	if (keydata.key == MLX_KEY_UP)
	{
		*n_y = *n_y - 1;
		pa->img_file = pa->img_up;
	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		*n_y = *n_y + 1;
		pa->img_file = pa->img_down;
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		*n_x = *n_x - 1;
		pa->img_file = pa->img_left;
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		*n_x = *n_x + 1;
		pa->img_file = pa->img_right;
	}
	pa->imgs->ninja = create_render(pa->mlx, pa->img_file, 'P', pa->map);
}

void	move_the_player(t_param *param, int new_x, int new_y)
{
	char	*number;
	char	*string;

	param->map[param->ninja->y][param->ninja->x] = '0';
	param->map[new_y][new_x] = 'P';
	param->ninja->x = new_x;
	param->ninja->y = new_y;
	param->ninja->move_count++;
	mlx_delete_image(param->mlx, param->imgs->count);
	number = ft_itoa(param->ninja->move_count);
	string = ft_strjoin("moves :", number);
	param->imgs->count = mlx_put_string(param->mlx, string, 50, 0);
	free(number);
	free(string);
}

void	eat_col(mlx_t *mlx, t_param *param, int new_x, int new_y)
{
	mlx_image_t	*img;

	param->map[new_y][new_x] = '0';
	mlx_delete_image(mlx, param->imgs->col);
	mlx_delete_image(mlx, param->imgs->white);
	param->imgs->white = create_render(mlx, "textures/0.png", '0', param->map);
	param->imgs->col = create_render(mlx, "textures/C.png", 'C', param->map);
	param->imgs->ninja = create_render(mlx, param->img_file, 'P', param->map);
	param->imgs->enemy = create_render(mlx, "textures/I.png", 'I', param->map);
	if (can_go_out(param->map))
	{
		mlx_delete_image(mlx, param->imgs->door);
		img = create_render(mlx, "textures/E2.png", 'E', param->map);
		param->imgs->door = img;
	}
}
