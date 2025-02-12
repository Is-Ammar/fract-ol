/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:19:10 by iammar            #+#    #+#             */
/*   Updated: 2025/02/12 13:07:57 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>

# define SIZE 800


# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

void        init_fractal(t_fractal *fractal);
int         render_fractal(t_fractal *fractal, char *query);
void        julia(t_fractal *fractal);
void        mandelbrot(t_fractal *fractal);
void        put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
int         mouse_hook(int button, int x, int y, t_fractal *fractal);
double      ft_atod(const char *str);
void        ft_putstr_fd(char const *s, int fd);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
int         ft_strlen(char *str);
int         key_hook(int key_code, t_fractal *fractal);
int	        exit_fractal(t_fractal *fractal);
void 		render_mandelbrot(t_fractal *fractal);
void 		mandelbrot(t_fractal *fractal);
void		burning_ship(t_fractal *fractal);

#endif