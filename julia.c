/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:47:09 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/04 14:30:18 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	julia_math(t_params *p)
{
	p->t->temp_x = p->t->x * p->t->x - p->t->y * p->t->y + p->j->julia_c_re;
	p->t->y = 2 * p->t->x * p->t->y + p->j->julia_c_im;
	p->t->x = p->t->temp_x;
	p->t->iter++;
}

void	julia(t_params *p)
{
	p->t->color = colortab();
	p->t->row = -1;
	while (++p->t->row < HEIGHT)
	{
		p->t->col = -1;
		while (++p->t->col < WIDTH)
		{
			p->t->x = (((double)p->t->col - WIDTH / 2.0) * 4.0 / WIDTH)
				* p->t->zoom + p->t->horizontal;
			p->t->y = (((double)p->t->row - HEIGHT / 2.0) * 4.0 / WIDTH)
				* p->t->zoom + p->t->vertical;
			p->t->iter = 0;
			while (p->t->x * p->t->x + p->t->y * p->t->y <= 4
				&& p->t->iter < MAX)
				julia_math(p);
			if (p->t->iter < MAX)
				my_mlx_pixel_put(p, p->t->col, p->t->row,
					p->t->color[p->t->c][p->t->iter % 8]);
		}
	}
}
