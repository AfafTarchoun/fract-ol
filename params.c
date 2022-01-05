/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:42:36 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/05 22:21:46 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_param_error(char *str)
{
	ft_putstr("fractol: invalid option -- ");
	if (str != 0)
	{
		ft_putstr(str);
		ft_putstr("\n try :\n./fractol mandelbrot\n");
		ft_putstr("./fractol julia [0-3]\n");
	}
	else
	{
		ft_putstr("\n try :\n./fractol mandelbrot\n");
		ft_putstr("./fractol julia [0-3]\n");
	}
}

int	check_fractal(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		return (1);
	return (0);
}

void	params(char **argv, int argc, t_params *p)
{
	if (argc == 3)
	{
		if (ft_strcmp(argv[1], "julia") == 0 && ft_number(argv[2]) == 1)
		{
			juliaparams(&p->j->julia_c_im, &p->j->julia_c_re, ft_atoi(argv[2]));
			p->name = argv[1];
		}
		else
		{
			ft_param_error(argv[1]);
			free_params(p);
			exit(0);
		}
	}
	else
	{
		if (check_fractal(argv[1]) == 1)
			p->name = argv[1];
		else
		{
			ft_param_error(argv[1]);
			free_params(p);
			exit(0);
		}
	}
}

void	free_params(t_params *p)
{
	free(p->mlxs);
	free(p->img);
	free(p->j);
	free(p->t);
	free(p);
}
