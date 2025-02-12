/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:25 by iammar            #+#    #+#             */
/*   Updated: 2025/02/12 09:50:28 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
    double zoom_level;

    zoom_level = 1.1;
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


int key_hook(int key_code, t_fractal *fractal)
{
    printf("%d\n",key_code);
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
        init_fractal(fractal);
    else if (key_code == C)
        fractal->color += (255 * 255 * 255) / 100;
    else if(key_code == 65453)
        fractal->max_iterations -= 10;
    else if(key_code == 65451)
        fractal->max_iterations += 10;
    draw_fractal(fractal, fractal->name);
    return (0);
}
