/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:22:38 by iammar            #+#    #+#             */
/*   Updated: 2025/02/22 10:15:16 by iammar           ###   ########.fr       */
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

void	render_bsh(t_fractal *fractal)
{
	fractal->x = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			burning_ship(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

int	render_fractal(t_fractal *fractal, char *query)
{
	if (ft_strcmp(query, "julia") == 0)
	{
		render_julia(fractal);
	}
	else if (!ft_strcmp(query, "mandelbrot"))
	{
    if (fractal->first_for_offset == 0) 
    {
        fractal->offset_x = -2.027586;
        fractal->first_for_offset = 1;
    }
    render_mandelbrot(fractal);
	}
	else if (ft_strcmp(query, "burning_ship") == 0)
	{
		render_bsh(fractal);
	}
	else
	{
		write(1, "Available fractals: julia , mandelbrot, burning ship\n", 53);
		exit_fractal(fractal, 1);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}
