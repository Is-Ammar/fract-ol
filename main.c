/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:16:21 by iammar            #+#    #+#             */
/*   Updated: 2025/02/14 12:46:13 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xc1e7f7;
	fractal->zoom = 300;
	fractal->offset_x = -1.45;
	fractal->offset_y = -1.25;
	fractal->max_iterations = 50;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit_fractal(fractal, 1);
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	if (!fractal->window)
		exit_fractal(fractal, 1);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->image)
		exit_fractal(fractal, 1);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	if (!fractal->pointer_to_image)
		exit_fractal(fractal, 1);
}

void	check_input(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "Usage: ./fractol <fractal>\n", 27);
		exit(1);
	}
	if ((!ft_strncmp(av[1], "mandelbrot", 10) || !ft_strncmp(av[1],
				"burning_ship", 11)) && ac == 2)
		return ;
	if (!ft_strncmp(av[1], "julia", 5))
	{
		if (ac != 4 || !ft_isdigit(av[2]) || !ft_isdigit(av[3]))
		{
			write(1, "Usage: ./fractol julia <x> <y>\n", 31);
			exit(1);
		}
		return ;
	}
	write(1, "Usage: ./fractol <fractal>\n", 27);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	check_input(argc, argv);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
	{
		write(1, "Allocation error\n", 17);
		exit(1);
	}
	init_fractal(fractal);
	if (argc == 4)
	{
		fractal->cx = ft_atod(argv[2]);
		fractal->cy = ft_atod(argv[3]);
	}
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	fractal->name = argv[1];
	render_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
