/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:09:47 by iammar            #+#    #+#             */
/*   Updated: 2025/02/10 15:42:59 by iammar           ###   ########.fr       */
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
    if (fractal->image)
        mlx_destroy_image(fractal->mlx, fractal->image);
    if (fractal->window)
        mlx_destroy_window(fractal->mlx, fractal->window);
    if (fractal->mlx)
    {
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
    }
    if (fractal)
        free(fractal);
    exit(0);
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
