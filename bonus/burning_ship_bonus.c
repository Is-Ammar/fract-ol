/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:05:25 by iammar            #+#    #+#             */
/*   Updated: 2025/03/02 01:35:02 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->scale) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->scale) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = fabs(x_temp);

	}
	if (i == fractal->max_iterations)
		pixel_color(fractal, fractal->x, SIZE - fractal->y, 0x000000);
	else
		pixel_color(fractal, fractal->x, SIZE - fractal->y, (fractal->color * i));
}
