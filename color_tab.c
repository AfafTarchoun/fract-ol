/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:07:04 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/04 15:57:47 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	**colortab(void)
{
	int	**tab;

	tab = (int **)malloc(sizeof(int *) * 4);
	tab[0] = color_neon_palette(tab[0]);
	tab[1] = color_palette_pastel(tab[1]);
	tab[2] = color_psychedelic_palette(tab[2]);
	tab[3] = color_dark(tab[3]);
	return (tab);
}

void	free_color(int **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_colors_tab(int **colortab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free_color(&colortab[i], 4);
		i++;
	}
	free(colortab);
}
