/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:09:47 by iammar            #+#    #+#             */
/*   Updated: 2025/03/08 17:13:39 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	pixel_color(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = (int *)fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	smooth_color(t_fractal *fractal, int iterations, double zx, double zy)
{
	if (iterations == fractal->max_iterations)
		return 0x000000; 

	double log_zn = log(zx * zx + zy * zy) / 2.0;
	double nu = log(log_zn / log(2.0)) / log(2.0);
	double t = (iterations + 1 - nu) / fractal->max_iterations;

	int r = (int)(9 * (1 - t) * t * t * t * 255);
	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	return (r << 16) | (g << 8) | b;
}

void	julia(t_fractal *fractal)
{
	int		iterations;
	double	zx_squared;
	double	zy_squared;

	fractal->zx = fractal->x / fractal->scale + fractal->offset_x;
	fractal->zy = fractal->y / fractal->scale + fractal->offset_y;
	iterations = 0;
	while (++iterations < fractal->max_iterations)
	{
		zx_squared = fractal->zx * fractal->zx;
		zy_squared = fractal->zy * fractal->zy;
		if (zx_squared + zy_squared >= 4.0)
			break ;
		fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = zx_squared - zy_squared + fractal->cx;
	}

	int color = smooth_color(fractal, iterations, fractal->zx, fractal->zy);
	pixel_color(fractal, fractal->x, SIZE - fractal->y, color);
}