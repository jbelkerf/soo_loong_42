#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42.h"

#define WIDTH 512
#define HEIGHT 512


typedef struct ninja
{
    mlx_t *mlx;
    mlx_image_t *img;
}   t_ninja;

#endif