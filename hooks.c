/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:31:28 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/04 18:50:57 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	zoom(int button, int x, int y, t_params *p)
{
	(void)x;
	(void)y;
	if (button == 5)
		p->t->zoom = p->t->zoom * 1 / 2;
	if (button == 4)
		p->t->zoom = p->t->zoom * 2;
	draw(p);
	mlx_put_image_to_window(p->mlxs->mlx, p->mlxs->mlx_win, p->img->pic, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_params *p)
{
	if (keycode == 126)
		p->t->vertical -= 0.05;
	if (keycode == 125)
		p->t->vertical += 0.05;
	if (keycode == 124)
		p->t->horizontal += 0.05;
	if (keycode == 123)
		p->t->horizontal -= 0.05;
	if (keycode == 53)
		exit(0);
	draw(p);
	mlx_put_image_to_window(p->mlxs->mlx, p->mlxs->mlx_win, p->img->pic, 0, 0);
	return (0);
}
