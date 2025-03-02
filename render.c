/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:22:38 by iammar            #+#    #+#             */
/*   Updated: 2025/03/02 02:00:08 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void render_fractal(t_fractal *fractal, char *name)
{
	
    void (*fractal_func)(t_fractal *);

    if (ft_strcmp(name, "julia") == 0)
        fractal_func = julia;
    else if (ft_strcmp(name, "mandelbrot") == 0)
        fractal_func = mandelbrot;
    else
    {
        write(1, "Error: Unknown fractal type\n", 27);
        exit_fractal(fractal, 1);
    }
    fractal->x = 0;
    while (fractal->x < SIZE)
    {
        fractal->y = 0;
        while (fractal->y < SIZE)
        {
            fractal_func(fractal);
            fractal->y++;
        }
        fractal->x++;
    }

    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
}