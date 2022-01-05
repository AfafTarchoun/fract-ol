/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:11:42 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/05 22:29:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_put(t_params *p, int x, int y, int color)
{
	p->img->addr[y * WIDTH + x] = color;
}

void	draw(t_params *p)
{
	mlx_destroy_image(p->mlxs->mlx, p->img->pic);
	p->img->pic = mlx_new_image(p->mlxs->mlx, WIDTH, HEIGHT);
	p->img->addr = (int *)mlx_get_data_addr(p->img->pic,
			&p->img->bits_per_pixel, &p->img->line_length, &p->img->endian);
	if (p->t->c == 3)
		p->t->c = 0;
	else
		p->t->c = p->t->c + 1;
	if (ft_strcmp(p->name, "burningship") == 0)
		burningship(p);
}
