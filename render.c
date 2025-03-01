/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:22:38 by iammar            #+#    #+#             */
/*   Updated: 2025/03/01 23:05:28 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_julia(t_fractal *fractal)
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

void	render_mandelbrot(t_fractal *fractal)
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

void	render_fractal(t_fractal *fractal, char *query)
{
	if (ft_strcmp(query, "julia") == 0)
		render_julia(fractal);
	else if (!ft_strcmp(query, "mandelbrot"))
    	render_mandelbrot(fractal);
	else
	{
		write(1, "Available fractals: julia , mandelbrot\n", 53);
		exit_fractal(fractal, 1);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
}
