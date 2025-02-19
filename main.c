/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/19 11:40:29 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *nin)
{
	t_ninja *ninja = (t_ninja *)nin;
	mlx_t *mlx = ninja->mlx;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		ninja->img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		ninja->img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		ninja->img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		ninja->img->instances[0].x += 5;
}

int	count_line(char *file)
{
	int		fd;
	int		line_count;
	char	*str;

	fd = open(file, O_RDONLY);
	line_count = 0;
	while (1)
	{
		if ((str = get_next_line(fd)) == NULL)
			break ;
		line_count++;
		free(str);
	}
	close(fd);
	return (line_count);
}

char	**map_to_str(char *file)
{
	int		fd;
	char	*line;
	char	**re;
	int		i;

	re = malloc((count_line(file) + 1) * sizeof(char *));
	i = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		if ((line = get_next_line(fd)) == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		re[i] = line;
		i++;
	}
	re[i] = NULL;
	close(fd);
	return (re);
}

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
}

void	is_there_valid_path(char **map)
{
	t_path	path;

	fill_path(&path, map);
	
	ft_printf("px %i \n py %i\n width %i\n height %i\n", path.player_x + 1, path.player_y + 1, path.map_width, path.map_height);
}

void	is_the_map_valid(char *file)
{
	char	**map;

	map = map_to_str(file);
	check_the_walls(map);
	ckeck_the_other_symbol(map);
	is_there_valid_path(map);
}


int main(int argc, char **argv)
{
	mlx_t *mlx;
	t_ninja ninja;

	if (argc != 2)
		puts_error("too many arguments");
	is_the_map_valid(argv[1]);
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "jbelkerf", true)))
		puts_error("mlx_init\n");
	mlx_texture_t *imag_tex = mlx_load_png("img/imag.png");
	mlx_image_t *imag = mlx_texture_to_image(mlx, imag_tex);
	mlx_resize_image(imag, 70, 130);
	mlx_image_to_window(mlx, imag, 1, 1);
	ninja.img = imag;
	ninja.mlx = mlx;
	mlx_loop_hook(mlx, ft_hook, (void *)&ninja);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (0);
}
