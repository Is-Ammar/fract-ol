/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:16:21 by iammar            #+#    #+#             */
/*   Updated: 2025/02/09 18:06:06 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


void draw_julia(t_fractal *fractal)
{
    fractal->x = 0;
    while (fractal->x < SIZE)
    {
        fractal->y = 0;
        while (fractal->y < SIZE)
        {
            julia(fractal);
            fractal->y++;
        }
        fractal->x++;
    }
}
void draw_mandelbrot(t_fractal *fractal)
{
    fractal->x = 0;
    while (fractal->x < SIZE)
    {
        fractal->y = 0;
        while (fractal->y < SIZE)
        {
            mandelbrot(fractal);
            fractal->y++;
        }
        fractal->x++;
    }
}

int draw_fractal(t_fractal *fractal, char *query) 
{
    if (ft_strncmp(query, "julia", 5) == 0)
     {
        draw_julia(fractal);
    }
    if (ft_strncmp(query, "mandelbrot", 10) == 0)
     {
        draw_mandelbrot(fractal);
    } 
    // else 
    // {
    //     write(1, "Available fractals: julia\n", 26);
    //     return -1;
    // }
    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
    return 0;
}

void init_fractal(t_fractal *fractal, double real, double imaginary) 
{
    fractal->x = 0;
    fractal->y = 0;
    fractal->color = 0xFCBE11;
    fractal->zoom = 300;
    fractal->offset_x = -1.21;
    fractal->offset_y = -1.21;
    fractal->max_iterations = 42;
    fractal->cx = real;
    fractal->cy = imaginary;
}

void init_mlx(t_fractal *fractal) 
{
    fractal->mlx = mlx_init();
    fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
    fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
    fractal->pointer_to_image = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
}



int main(int argc, char **argv)
 {
    double real = 0;
    double imaginary = 0;
    if (argc < 2) 
    {
        write(1, "Usage: ./fractol <fractal>\n", 27);
        return 1;
    }
    if(argc == 4)
    {
        real = ft_atod(argv[2]);
        imaginary = ft_atod(argv[3]);
    }
    t_fractal *fractal = malloc(sizeof(t_fractal));
    init_fractal(fractal, real, imaginary);
    init_mlx(fractal);
    mlx_key_hook(fractal->window, key_hook, fractal);
    mlx_mouse_hook(fractal->window, mouse_hook, fractal);
    mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
    fractal->name = argv[1];
    draw_fractal(fractal, argv[1]);
    mlx_loop(fractal->mlx);
    return 0;
}
