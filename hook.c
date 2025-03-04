/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:25 by iammar            #+#    #+#             */
/*   Updated: 2025/03/02 21:02:15 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;
	double	new_scale;

	zoom_factor = 1.11;
	if (mouse_code == 4)
		new_scale = fractal->scale * zoom_factor;
	else if (mouse_code == 5)
		new_scale = fractal->scale / zoom_factor;
	else
		return (0);
	fractal->offset_x += (x / fractal->scale) - (x / new_scale);
	fractal->offset_y += ((SIZE - y) / fractal->scale) - ((SIZE - y)
			/ new_scale);
	fractal->scale = new_scale;
	render_fractal(fractal);
	return (0);
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal, 0);
	render_fractal(fractal);
	return (0);
}
