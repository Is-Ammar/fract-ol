/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:09:47 by iammar            #+#    #+#             */
/*   Updated: 2025/03/01 22:45:53 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_color(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = (int *)fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

void	julia(t_fractal *fractal)
{
	int		iterations;
	double	zx_squared;
	double	zy_squared;

	fractal->zx = (SIZE - fractal->x) / fractal->scale - fractal->offset_x;
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
	if (iterations == fractal->max_iterations)
		pixel_color(fractal, fractal->x, fractal->y, 0x000000);
	else
		pixel_color(fractal, fractal->x, fractal->y, (fractal->color
				* iterations));
}
