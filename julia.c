/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:09:47 by iammar            #+#    #+#             */
/*   Updated: 2025/02/09 18:07:32 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
    int *buffer;

    buffer = (int *)fractal->pointer_to_image;
    buffer[(y * fractal->size_line / 4) + x] = color;
}

int exit_fractal(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->image);
    mlx_destroy_window(fractal->mlx, fractal->window);
    free(fractal->mlx);
    free(fractal);
    exit(1);
}

void julia(t_fractal *fractal)
{
    int     i;
    double  tmp;

    fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
    fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
    i = 0;
    while (++i < fractal->max_iterations)
    {
        tmp = fractal->zx;
        fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
        fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
        if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
            break;
    }
    if (i == fractal->max_iterations)
        put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
    else
        put_color_to_pixel(fractal, fractal->x, fractal->y, fractal->color * (i % 255));
}

void zoom(t_fractal *fractal, int x, int y, int zoom)
{
    double zoom_level;

    zoom_level = 1.42;
    if (zoom == 1)
    {
        fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom * zoom_level));
        fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom * zoom_level));
        fractal->zoom *= zoom_level;
    }
    else if (zoom == -1)
    {
        fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom / zoom_level));
        fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom / zoom_level));
        fractal->zoom /= zoom_level;
    }
}

void change_iterations(t_fractal *fractal, int key_code)
{
    if (key_code == 'M')
    {
        if (fractal->max_iterations > 42)
            fractal->max_iterations -= 42;
    }
    else if (key_code == 'P')
    {
        if (fractal->max_iterations < 4200)
            fractal->max_iterations += 42;
    }
}

int key_hook(int key_code, t_fractal *fractal, double real, double imaginary)
{
    if (key_code == 53) 
        exit_fractal(fractal);
    else if (key_code == 123) 
        fractal->offset_x -= 42 / fractal->zoom;
    else if (key_code == 124)
        fractal->offset_x += 42 / fractal->zoom;
    else if (key_code == 125)
        fractal->offset_y += 42 / fractal->zoom;
    else if (key_code == 126)
        fractal->offset_y -= 42 / fractal->zoom;
    else if (key_code == 15)
        init_fractal(fractal, real, imaginary);
    else if (key_code == 8)
        fractal->color += (255 * 255 * 255) / 100;
    draw_fractal(fractal, fractal->name);
    return (0);
}

int mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
    double zoom_level;

    zoom_level = 1.42;
    if (mouse_code == 4)
    {
        fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom * zoom_level));
        fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom * zoom_level));
        fractal->zoom *= zoom_level;
    }
    else if (mouse_code == 5)
    {
        fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom / zoom_level));
        fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom / zoom_level));
        fractal->zoom /= zoom_level;
    }
    draw_fractal(fractal, fractal->name);
    return (0);
}