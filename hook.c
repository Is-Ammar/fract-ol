/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:25 by iammar            #+#    #+#             */
/*   Updated: 2025/02/22 21:07:24 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	double zoom_level = 1.11;
	double new_zoom;

	if (mouse_code == 4)
	{
		new_zoom = fractal->zoom * zoom_level;
		fractal->offset_x += (SIZE - x) / fractal->zoom - (SIZE - x) / new_zoom;
		fractal->offset_y += y / fractal->zoom - y / new_zoom;
		fractal->zoom = new_zoom;
	}
	else if (mouse_code == 5)
	{
		new_zoom = fractal->zoom / zoom_level;
		fractal->offset_x += (SIZE - x) / fractal->zoom - (SIZE - x) / new_zoom;
		fractal->offset_y += y / fractal->zoom - y / new_zoom;
		fractal->zoom = new_zoom;
	}

	render_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook2(int mouse_code, int x, int y, t_fractal *fractal)
{
	double	zoom_level;

	zoom_level = 1.11;
	if (mouse_code == 4)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (mouse_code == 5)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	render_fractal(fractal, fractal->name);
	return (0);
}

void	famous_julias(int key_code, t_fractal *fractal)
{
	if (key_code == C)
	{
		fractal->color += (255 * 255 * 255) / 100;
	}
	else if (key_code == 65453)
		fractal->max_iterations -= 10;
	else if (key_code == 65451)
		fractal->max_iterations += 10;
	else if (key_code == 65433)
	{
		fractal->cx = 0.403333;
		fractal->cy = 0.273333;
	}
	else if (key_code == 65435)
	{
		fractal->cx = 0.18;
		fractal->cy = -0.566667;
	}
	else if (key_code == 65430)
	{
		fractal->cx = -0.8;
		fractal->cy = 0.150;
	}
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal, 0);
	else if (key_code == LEFT)
	{
		fractal->offset_x -= 42 / fractal->zoom;
		printf("offset_x---->: %lf\n", fractal->offset_x);
	}
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == DOWN)
	{
		fractal->offset_y += 42 / fractal->zoom;
		printf("offset_y---->: %lf\n", fractal->offset_y);
	}
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == R)
	{
		fractal->first_for_offset = 0;
		init_fractal(fractal);
	}
	famous_julias(key_code, fractal);
	render_fractal(fractal, fractal->name);
	return (0);
}
