/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:59:58 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/05 20:36:14 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_param_error(char *str)
{
	ft_putstr("fractol: invalid option -- ");
	if (str != 0)
	{
		ft_putstr(str);
		ft_putstr("\ntry ./fractol burningship\n");
	}
	else
		ft_putstr("\ntry ./fractol burningship\n");
}

int	check_fractal(char *str)
{
	if (ft_strcmp(str, "burningship") == 0)
		return (1);
	return (0);
}

void	params(char **argv, int argc, t_params *p)
{
	if (argc == 2)
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
