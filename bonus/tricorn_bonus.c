/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:05:25 by iammar            #+#    #+#             */
/*   Updated: 2025/03/08 17:25:53 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	tricorn(t_fractal *fractal)
{
	int		iterations;
	double	zx_squared;
	double	zy_squared;

	iterations = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->scale) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->scale) + fractal->offset_y;
	while (++iterations < fractal->max_iterations)
	{
		zx_squared = fractal->zx * fractal->zx;
		zy_squared = fractal->zy * fractal->zy;
		if (zx_squared + zy_squared >= 4.0)
			break ;
		fractal->zy = -2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = zx_squared - zy_squared + fractal->cx;
	}

	int color = smooth_color(fractal, iterations, fractal->zx, fractal->zy);
	pixel_color(fractal, fractal->x, SIZE - fractal->y, color);
}