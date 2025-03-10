/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:25 by iammar            #+#    #+#             */
/*   Updated: 2025/03/06 02:07:19 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;
	double	new_scale;

	zoom_factor = 1.1;
	y = SIZE - y;
	if (mouse_code == 4)
		new_scale = fractal->scale * zoom_factor;
	else if (mouse_code == 5)
		new_scale = fractal->scale / zoom_factor;
	else
		return (0);
	fractal->offset_x += (x / fractal->scale) - (x / new_scale);
	fractal->offset_y += (y / fractal->scale) - (y / new_scale);
	fractal->scale = new_scale;
	render_fractal(fractal);
	return (0);
}

void	famous_julias(int key_code, t_fractal *fractal)
{
	if (key_code == C)
	{
		fractal->color += 255 * 255 * 255;
	}
	else if (key_code == 65453)
	{
		if (fractal->max_iterations > 10)
			fractal->max_iterations -= 10;
	}
	else if (key_code == 65451)
		fractal->max_iterations += 10;
	else if (key_code == 65433)
	{
		fractal->cx += 0.01;
		fractal->cy += 0.01;
	}
	else if (key_code == 65435)
	{
		fractal->cx -= 0.01;
		fractal->cy -= 0.01;
	}
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal, 0);
	else if (key_code == LEFT)
	{
		fractal->offset_x -= 42 / fractal->scale;
	}
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->scale;
	else if (key_code == DOWN)
	{
		fractal->offset_y -= 42 / fractal->scale;
	}
	else if (key_code == UP)
		fractal->offset_y += 42 / fractal->scale;
	else if (key_code == R)
		init_fractal(fractal);
	famous_julias(key_code, fractal);
	render_fractal(fractal);
	return (0);
}
