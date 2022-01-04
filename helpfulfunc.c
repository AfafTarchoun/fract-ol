/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfulfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:46:43 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/04 17:04:13 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	**allowtable(size_t size)
{
	double	**tab;
	size_t	i;

	tab = (double **)malloc(sizeof(double *) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = (double *)malloc(sizeof(double));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	freetable(double **tab, size_t size)
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

double	**filltable(double **tab)
{
	tab = allowtable(4);
	tab[0][0] = -0.70176;
	tab[0][1] = -0.3842;
	tab[1][0] = -0.835;
	tab[1][1] = -0.2321;
	tab[2][0] = 0;
	tab[2][1] = -0.8;
	tab[3][0] = -0.8000;
	tab[3][1] = 0.1560;
	return (tab);
}

void	juliaparams(double *x, double *y, int index)
{
	double	**tabvalues;

	tabvalues = filltable(tabvalues);
	if (index >= 0 && index <= 3)
	{
		*x = tabvalues[index][0];
		*y = tabvalues[index][1];
		freetable(tabvalues, 4);
	}
	else
	{
		*x = 0;
		*y = 0;
	}
}
