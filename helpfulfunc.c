/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfulfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:46:43 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/03 18:33:23 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double **allowTable(size_t size)
{
  double **tab;
  size_t i;

  tab = (double**)malloc(sizeof(double*) * size);
  i = 0;
  while(i < size)
  {
    tab[i] = (double*)malloc(sizeof(double));
    i++;
  }
  tab[i] = NULL;
  return (tab);
}

void freeTable(double **tab, size_t size)
{
  size_t i;

  i = 0;
  while(i < size)
  {
    free(tab[i]);
    i++;
  }
  free(tab);
}

double **fillTable(double **tab)
{
  tab = allowTable(4);
  tab[1][0] = -0.54;
  tab[1][1] = 0.54;
  tab[2][0] = -0.4;
  tab[2][1] = -0.59;
  tab[3][0] = 0;
  tab[3][1] = 0.8;
  tab[4][0] = 0.355534;
  tab[4][1] = -0.337292;
  return (tab);
}

void juliaParams(double *x, double *y, int index)
{
  double **tabValues;
  
  tabValues = fillTable(tabValues);
  if (index >= 0 && index <= 3)
  {
    *x = tabValues[index][0];
    *y = tabValues[index][1];
    freeTable(tabValues, 4);
  }
  else
  {
    *x = 0;
    *y = 0;
  }
}