/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:22:58 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/19 15:35:30 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	is_the_map_valid(char *file)
{
	char	**map;

	map = map_to_str(file);
	check_the_walls(map);
	ckeck_the_other_symbol(map);
	is_there_valid_path(map);
	free_map(map);
}

void	set_window_dimension(char *file, int *width, int *height)
{
	char	**map;
	int		i;

	i = 0;
	map = map_to_str(file);
	*width = 50 * ft_strlen(map[0]);
	while (map[i])
		i++;
	*height = 50 * i;
}

void render_wall(char **map, mlx_t *mlx, mlx_image_t *wall_img)
{
    int y = 0;
    while (map[y])
    {
        int x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1') // If it's a wall
                mlx_image_to_window(mlx, wall_img, x * 50, y * 50);
            x++;
        }
        y++;
    }
}
void render_flame(char **map, mlx_t *mlx, mlx_image_t *wall_img)
{
    int y = 0;
    while (map[y])
    {
        int x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'C') // If it's a wall
                mlx_image_to_window(mlx, wall_img, x * 50, y * 50);
            x++;
        }
        y++;
    }
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_ninja			ninja;
	//ninja
	mlx_texture_t	*imag_tex;
	mlx_image_t		*imag;

	//wall
	mlx_texture_t	*wal_tex;
	mlx_image_t		*wal_img;

	//flame 
	mlx_texture_t	*flame_tex;
	mlx_image_t		*flame_img;

	int				width;
	int				height;
	char	**map;


	if (argc != 2)
		puts_error("too many arguments");
	map = map_to_str(argv[1]);
	is_the_map_valid(argv[1]);
	set_window_dimension(argv[1], &width, &height);
	mlx = mlx_init(width, height, "jbelkerf", false);
	if (!mlx)
		puts_error("mlx_init\n");
	//ninja
	imag_tex = mlx_load_png("img/imag.png");
	imag = mlx_texture_to_image(mlx, imag_tex);
	mlx_resize_image(imag, 50, 50);
	//wall
	wal_tex = mlx_load_png("wal.png");
	wal_img = mlx_texture_to_image(mlx, wal_tex);
	mlx_resize_image(wal_img, 50, 50);
	//flame
	flame_tex = mlx_load_png("flame.png");
	flame_img = mlx_texture_to_image(mlx, flame_tex);
	mlx_resize_image(flame_img, 50, 50);
	
	render_wall(map, mlx, wal_img);
	render_flame(map, mlx, flame_img);
	mlx_image_to_window(mlx, imag, 50, 50);
	ninja.img = imag;
	ninja.mlx = mlx;
	mlx_loop_hook(mlx, ft_hook, (void *)&ninja);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
