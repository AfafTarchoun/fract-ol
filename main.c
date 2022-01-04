/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:08:11 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/04 18:43:04 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init_mlx_param(t_params *p)
{
	p->mlxs->mlx = mlx_init();
	p->mlxs->mlx_win = mlx_new_window(p->mlxs->mlx, WIDTH, HEIGHT, "fractal");
	p->img->pic = mlx_new_image(p->mlxs->mlx, WIDTH, HEIGHT);
	p->img->addr = mlx_get_data_addr(p->img->pic, &p->img->bits_per_pixel,
			&p->img->line_length, &p->img->endian);
	p->t->zoom = 1.0;
	p->t->c = 0;
}

int	main(int argc, char **argv)
{
	t_params	*p;

	if (argc == 3 || argc == 2)
	{
		p = malloc(sizeof(t_params) * 1);
		p->mlxs = malloc(sizeof(t_mlx) * 1);
		p->img = malloc(sizeof(t_image) * 1);
		p->t = malloc(sizeof(t_fractal) * 1);
		p->j = malloc(sizeof(t_julia_param) * 1);
		params(argv, argc, p);
		ft_init_mlx_param(p);
		draw(p);
		mlx_put_image_to_window(p->mlxs->mlx, p->mlxs->mlx_win,
			p->img->pic, 0, 0);
		mlx_hook(p->mlxs->mlx_win, 2, 0, key_hook, p);
		mlx_hook(p->mlxs->mlx_win, 4, 0, zoom, p);
		mlx_loop(p->mlxs->mlx);
		free_params(p);
	}
	else
		ft_param_error(argv[1]);
}
