#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "MLX42.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

# define WIDTH 512
# define HEIGHT 512

typedef struct map
{
	int	width;
	int	height;
	int	p;
	int	zero;
	int	c;
	int	e;
}	t_map;


typedef struct ninja
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_ninja;

void	check_the_walls(char **map);
void	puts_error(char *str);

#endif