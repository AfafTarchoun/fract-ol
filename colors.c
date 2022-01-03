/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:07:04 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/03 15:32:42 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int *color_palette_pastel(int   *color)
{
    color = (int *)malloc(sizeof(int) * 8);
    color[0] = 0xF08080;
    color[1] = 0xF0E68C;
    color[2] = 0x98FB98;
    color[3] = 0x40E0D0;
    color[4] = 0x87CEEB;
    color[5] = 0x9370DB;
    color[6] = 0xDDA0DD;
    color[7] = 0xFFB6C1;
    return (color);

}

int *color_psychedelic_palette(int   *color)
{
    color = (int *)malloc(sizeof(int) * 7);
    color[0] = 0xDD00FF;
    color[1] = 0xFF0046;
    color[2] = 0xFF9400;
    color[3] = 0x8FFF00;
    color[4] = 0x00FF4B;
    color[5] = 0x00D8FF;
    color[6] = 0x0200FF;
    return (color);
}

int *color_neon_palette(int   *color)
{
    color = (int *)malloc(sizeof(int) * 6);
    color[0] = 0x4deeea;
    color[1] = 0x74ee15;
    color[2] = 0xFFFFFF;
    color[3] = 0xffe700;
    color[4] = 0xf000ff;
    color[5] = 0x001eff;
    return (color);
}

int *color_dark(int *color)
{
  color = (int *)malloc(sizeof(int) * 4);
  color[0] = 0x000000;
  color[1] = 0x150050;
  color[2] = 0x3F0071;
  color[3] = 0x610094;
  return(color);
}

int			**colortab()
{
  int **tab;
	tab = (int **)malloc(sizeof(int *) * 4);
  tab[0] = color_neon_palette(tab[0]);
	tab[1] = color_palette_pastel(tab[1]);
	tab[2] = color_psychedelic_palette(tab[2]);
	tab[3] = color_dark(tab[3]);
	return (tab);
}

void free_color(int **tab, size_t size)
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

void free_colors_tab(int **colortab)
{
  int i;

  i = 0;
  while (i < 4)
  {
    free_color(&colortab[i], 4);
    i++;
  }
  free(colortab);
}
