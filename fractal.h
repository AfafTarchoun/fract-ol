/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:48:38 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/04 16:01:57 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define HEIGHT 900
# define WIDTH  1100
# define MAX 100
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_fractal
{
	int		row;
	int		col;
	int		iter;
	int		max;
	int		**color;
	int		c;
	double	x;
	double	y;
	double	zoom;
	double	horizontal;
	double	vertical;
	double	c_re;
	double	c_im;
	double	temp_x;
}				t_fractal;

typedef struct s_image
{
	void	*pic;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_julia_param
{
	double	julia_c_re;
	double	julia_c_im;
}				t_julia_param;

typedef struct s_params
{
	t_fractal		*t;
	t_image			*img;
	t_mlx			*mlxs;
	t_julia_param	*j;
	char			*name;
}				t_params;

void		burningship(t_params *p);
void		mandelbrot(t_params *p);
void		julia(t_params *p);
void		params(char **argv, int argc, t_params *p);
void		ft_param_error(char *str);
void		ft_init_mlx_param( t_params *p);
void		ft_putstr(char *str);
void		draw(t_params *p);
void		free_params(t_params *p);
void		free_color(int **tab, size_t size);
void		free_colors_tab(int **colortab);
void		juliaparams(double *x, double *y, int index);
void		my_mlx_pixel_put(t_params *p, int x, int y, int color);
static void	burn_math(t_params *p);
static void	mandel_math(t_params *p);
static void	julia_math(t_params *p);
int			ft_atoi(const char *str);
int			ft_strcmp(const char *str1, const char *str2);
int			*color_palette_pastel(int *color);
int			*color_neon_palette(int *color);
int			*color_dark(int *color);
int			*color_psychedelic_palette(int *color);
int			**colortab(void);
int			key_hook(int keycode, t_params *p);
int			zoom(int button, int x, int y, t_params *p);
#endif
