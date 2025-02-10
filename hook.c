/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:25 by iammar            #+#    #+#             */
/*   Updated: 2025/02/10 15:43:04 by iammar           ###   ########.fr       */
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
