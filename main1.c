/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/18 20:40:41 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	puts_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

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

char **map_to_str(char *file)
{
	int fd;
	char *line;
	char **re;
	int i;

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

void free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void is_rectangular(char **map)
{
	int width;
	int i;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (width != ft_strlen(map[i]))
		{
			free_map(map);
			puts_error("map not rectangular");
		}
		i++;
	}
}

int is_there_enough_walls(char *line, int check_all)
{
	if (check_all)
	{
		
	}
}

void	is_surrounded_by_walls(map)
{
	char	*line;
	int		i;

	if is_there_enough_walls(map[0], 1);
}

void	check_the_walls(char **map)
{
	is_rectangular(map);
	is_surrounded_by_walls(map);
}

void	is_the_map_valid(char *file)
{
	char	**map;

	map = map_to_str(file);
	check_the_walls(map);
	//check_the_other_chars(file);
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
