#include "so_long.h"



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

int check_the_map(char *file)
{
	t_map map;
	int fd;
	char *line;
	char *prev;
	int i;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("no file found\n");
		exit(1);
	}
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
	{
		ft_printf("too many arguments\n");
		exit(1);
	}
	if (check_the_map(argv[1]))
	{
		ft_printf("invlid map\n");
		exit(1);
	}
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "jbelkerf", true)))
	{
		ft_printf("mlx_init\n");
		exit(1);
	}
	mlx_texture_t *imag_tex = mlx_load_png("img/imag.png");
	mlx_image_t *imag = mlx_texture_to_image(mlx, imag_tex);
	mlx_resize_image(imag, 70, 100);
	mlx_image_to_window(mlx, imag, 1, 1);
	ninja.img = imag;
	ninja.mlx = mlx;
	
	mlx_loop_hook(mlx, ft_hook, (void *)&ninja);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (0);
}
