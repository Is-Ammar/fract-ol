/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:22:38 by iammar            #+#    #+#             */
/*   Updated: 2025/03/03 21:08:43 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	render(t_fractal *fractal, void (*fractal_func)(t_fractal *))
{
	int	size;

	size = SIZE;
	fractal->x = 0;
	while (fractal->x < size)
	{
		fractal->y = 0;
		while (fractal->y < size)
		{
			fractal_func(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
}

void	render_fractal(t_fractal *fractal)
{
	void	(*fractal_func)(t_fractal *);

	fractal_func = NULL;
	if (!ft_strcmp(fractal->name, "julia"))
		fractal_func = julia;
	else if (!ft_strcmp(fractal->name, "mandelbrot"))
		fractal_func = mandelbrot;
	else if (!ft_strcmp(fractal->name, "tricorn"))
		fractal_func = tricorn;
	else
	{
		write(1, "Error: Unknown fractal type\n", 27);
		exit_fractal(fractal, 1);
	}
	render(fractal, fractal_func);
}
