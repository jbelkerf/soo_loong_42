#include "so_long.h"


void puts_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void ft_hook(void *nin)
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

void check_the_other_chars(char *file)
{
	int i;
	int fd;
	char *line;
	t_map map;

	if ((fd = open(file, O_RDONLY)) == -1)
		puts_error("open error");
	map.p = 0;
	map.e = 0;
	map.c = 0;
	while (1)
	{
		if ((line = get_next_line(fd)) == NULL)
			break ;
		i = 0;
		while (line[i])
		{
			if (line[i] == 'P')
				map.p++;
			if (line[i] == 'E')
				map.e++;
			if (line[i] == 'C')
				map.c++;
			i++;
		}
	}
	if (map.p != 1 || map.e != 1 || map.c < 1)
		puts_error("too many P or E or no C");
}

int count_line(char *file)
{
	int fd;
	int line_count;
	char *str;

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
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = 0;
		re[i] = line;
		i++;
	}
	re[i] = NULL;
	return (re);
}

void is_the_map_valid(char *file)
{
	char **map;

	map = map_to_str(file);
	if (check_the_walls(file) == 1)
		puts_error("invalid map");
	check_the_other_chars(file);
}

int check_the_walls(char *file)
{
	t_map map;
	int fd;
	char *line;
	char *prev;
	int i;

	if ((fd = open(file, O_RDONLY)) == -1)
		puts_error("no file found");
	map.width = -1;
	while (1)
	{
		i = 0;
		if ((line = get_next_line(fd)) == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		if (map.width == -1)
		{
			map.width = ft_strlen(line);
			while (line[i])
			{
				if (line[i] != '1')
					return 1;
				i++;
			}
			continue;
		}
		else if (map.width != ft_strlen(line))
			return (close(fd), 1);
		while (line[i])
		{
			if ((i == 0 || i == ft_strlen(line) - 1) && line[i] != '1')
				return 1;
			i++;
		}
		prev = line;
	}
	while (prev[i])
	{
		if (prev[i] != '1')
			return 1;
		i++;
	}
	return (close(fd), 0);
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
