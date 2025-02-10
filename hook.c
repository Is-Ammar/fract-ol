/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:25 by iammar            #+#    #+#             */
/*   Updated: 2025/02/10 15:47:35 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
    double zoom_level;

    zoom_level = 1.07;
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


int key_hook(int key_code, t_fractal *fractal, double real, double imaginary)
{
    if (key_code == ESC) 
        exit_fractal(fractal);
    else if (key_code == LEFT) 
        fractal->offset_x -= 42 / fractal->zoom;
    else if (key_code == RIGHT)
        fractal->offset_x += 42 / fractal->zoom;
    else if (key_code == DOWN)
        fractal->offset_y += 42 / fractal->zoom;
    else if (key_code == UP)
        fractal->offset_y -= 42 / fractal->zoom;
    else if (key_code == R)
        init_fractal(fractal, real, imaginary);
    else if (key_code == C)
        fractal->color += (255 * 255 * 255) / 100;
    draw_fractal(fractal, fractal->name);
    return (0);
}
