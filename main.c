/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/19 13:34:58 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *nin)
{
	t_ninja	*ninja;
	mlx_t	*mlx;

	ninja = (t_ninja *)nin;
	mlx = ninja->mlx;
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
		str = get_next_line(fd);
		if (str == NULL)
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
		line = get_next_line(fd);
		if (line == NULL)
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

void	is_the_map_valid(char *file)
{
	char	**map;

	map = map_to_str(file);
	check_the_walls(map);
	ckeck_the_other_symbol(map);
	is_there_valid_path(map);
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_ninja			ninja;
	mlx_texture_t	*imag_tex;
	mlx_image_t		*imag;

	if (argc != 2)
		puts_error("too many arguments");
	is_the_map_valid(argv[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "jbelkerf", true);
	if (!mlx)
		puts_error("mlx_init\n");
	imag_tex = mlx_load_png("img/imag.png");
	imag = mlx_texture_to_image(mlx, imag_tex);
	mlx_resize_image(imag, 70, 130);
	mlx_image_to_window(mlx, imag, 1, 1);
	ninja.img = imag;
	ninja.mlx = mlx;
	mlx_loop_hook(mlx, ft_hook, (void *)&ninja);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
