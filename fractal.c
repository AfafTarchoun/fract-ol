/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:47:09 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/03 18:26:20 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot(t_params *p)
{
  p->t->color = colortab();
	p->t->row = 0;
	while(p->t->row < HEIGHT)
	{
		p->t->col = 0;
		while(p->t->col < WIDTH)
		{
			p->t->c_re = (((double)p->t->col - WIDTH / 2.0) * 4.0 / WIDTH ) * p->t->zoom+ p->t->horizontal;
			p->t->c_im = (((double)p->t->row - HEIGHT / 2.0) * 4.0/ WIDTH ) * p->t->zoom+ p->t->vertical;		
			p->t->x = 0;
			p->t->y = 0;
			p->t->iter = 0;
			while(p->t->x * p->t->x + p->t->y * p->t->y <= 4 && p->t->iter < MAX)
			{
				p->t->temp_x = p->t->x * p->t->x - p->t->y * p->t->y + p->t->c_re;
				p->t->y = 2 * p->t->x * p->t->y + p->t->c_im;
				p->t->x = p->t ->temp_x;
				p->t->iter++;
			}
			if (p->t->iter < MAX)
				my_mlx_pixel_put(p, p->t->col, p->t->row, p->t->color[p->t->c][p->t->iter % 8]);
			p->t->col++;
		}
		p->t->row++;
	}
}

void	julia(t_params *p)
{
	p->t->color = colortab();
	p->t->row = 0;
	while(p->t->row < HEIGHT)
	{
		p->t->col = 0;
		while(p->t->col < WIDTH)
		{
			p->t->x = (((double)p->t->col - WIDTH / 2.0) * 4.0 / WIDTH) * p->t->zoom + p->t->horizontal;
			p->t->y = (((double)p->t->row - HEIGHT / 2.0) * 4.0/ WIDTH) * p->t->zoom + p->t->vertical;
			p->t->iter = 0;
			while(p->t->x * p->t->x + p->t->y * p->t->y <= 4 && p->t->iter < MAX)
			{
				p->t->temp_x = p->t->x * p->t->x - p->t->y * p->t->y + p->j->julia_c_re;
				p->t->y = 2 * p->t->x * p->t->y + p->j->julia_c_im;
				p->t->x = p->t->temp_x;
				p->t->iter++;
			}
			if (p->t->iter  < MAX)
				my_mlx_pixel_put(p, p->t->col, p->t->row, p->t->color[p->t->c][p->t->iter % 8]);
			p->t->col++;
		}
		p->t->row++;
	}
}


 void	burningship(t_params *p)
 {
  p->t->color = colortab();
 	p->t->row = 0;
 	while(p->t->row < HEIGHT)
 	{
 		p->t->col = 0;
 		while(p->t->col < WIDTH)
 		{
 			p->t->c_re = (((double)p->t->col - WIDTH / 2.0) * 4.0 / WIDTH ) * p->t->zoom+ p->t->horizontal;
 			p->t->c_im = (((double)p->t->row - HEIGHT / 2.0) * 4.0/ WIDTH) * p->t->zoom + p->t->vertical;
 			p->t->x = 0;
 			p->t->y = 0;
 			p->t->iter = 0;
 			while(p->t->x * p->t->x + p->t->y * p->t->y <= 4 && p->t->iter < MAX)
 			{
 				p->t->temp_x = p->t->x * p->t->x - p->t->y * p->t->y + p->t->c_re;
 				p->t->y = 2 * fabs(p->t->x * p->t->y) + p->t->c_im;
 				p->t->x = p->t->temp_x;
 				p->t->iter++;
 			}
 			if (p->t->iter  < MAX)
 				my_mlx_pixel_put(p, p->t->col, p->t->row, p->t->color[p->t->c][p->t->iter % 8]);
			p->t->col++;
 		}
	p->t->row++;	 
 	}
}