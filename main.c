/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:16:21 by iammar            #+#    #+#             */
/*   Updated: 2025/02/12 14:34:48 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


void render_julia(t_fractal *fractal)
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
void render_mandelbrot(t_fractal *fractal)
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

void render_bsh(t_fractal *fractal)
{
    fractal->x = 0;
    while (fractal->x < SIZE)
    {
        fractal->y = 0;
        while (fractal->y < SIZE)
        {
            burning_ship(fractal);
            fractal->y++;
        }
        fractal->x++;
    }
}

int render_fractal(t_fractal *fractal, char *query) 
{
    if (ft_strncmp(query, "julia", 5) == 0)
     {
        render_julia(fractal);
    }
    else if (ft_strncmp(query, "mandelbrot", 10) == 0)
     {
        render_mandelbrot(fractal);
    } 
    else if (ft_strncmp(query, "burning_ship", 11) == 0)
     {
        render_bsh(fractal);
    } 
    else 
    {
        write(1, "Available fractals: julia , mandelbrot, burning ship\n", 53);
        exit_fractal(fractal);
    }
    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
    return 0;
}

void init_fractal(t_fractal *fractal) 
{

    fractal->x = 0;
    fractal->y = 0;
    fractal->color = 0xFC3556;
    fractal->zoom = 300;
    fractal->offset_x = -1.21;
    fractal->offset_y = -1.21;
    fractal->max_iterations = 60;
  
}

void init_mlx(t_fractal *fractal) 
{
    fractal->mlx = mlx_init();
    if(!fractal->mlx)
        exit_fractal(fractal);
    fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
    if(!fractal->window)
        exit_fractal(fractal);
    fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
    if(!fractal->image)
        exit_fractal(fractal);
    fractal->pointer_to_image = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
    if(!fractal->pointer_to_image)
        exit_fractal(fractal);
}

int main(int argc, char **argv)
 {
    if (argc < 2) 
    {
        write(1, "Usage: ./fractol <fractal>\n", 27);
        return 1;
    }
   
    t_fractal *fractal = malloc(sizeof(t_fractal));
    if(!fractal)
    {
        exit(1);
    }
    if(argc == 4)
    {
        fractal->cx = ft_atod(argv[2]);
        fractal->cy = ft_atod(argv[3]);
    }
    init_fractal(fractal);
    init_mlx(fractal);
    mlx_key_hook(fractal->window, key_hook, fractal);
    mlx_mouse_hook(fractal->window, mouse_hook, fractal);
    mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
    fractal->name = argv[1];
    render_fractal(fractal, argv[1]);
    mlx_loop(fractal->mlx);
    return 0;
}
