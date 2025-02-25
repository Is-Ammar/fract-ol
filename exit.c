/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:45:11 by iammar            #+#    #+#             */
/*   Updated: 2025/02/25 14:19:02 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int exit_fractal_wrapper(t_fractal *fractal)
{
    return (exit_fractal(fractal, 0));
}

int	exit_fractal(t_fractal *fractal, int toggle)
{
	if (fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	if (fractal)
		free(fractal);
	exit(toggle);
}
