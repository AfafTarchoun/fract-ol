/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:55:16 by atarchou          #+#    #+#             */
/*   Updated: 2022/01/05 22:26:42 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c < 58)
		return (1);
	return (0);
}

int	ft_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	v[2];

	a = 0;
	v[0] = 0;
	v[1] = 1;
	while (str[v[0]] <= ' ' && str[v[0]] != 27 && str[v[0]] != '\200')
		v[0]++;
	if (str[v[0]] == '-')
	{
		v[1] = -1;
		v[0]++;
	}
	else if (str[v[0]] == '+')
		v[0]++;
	while (str[v[0]] != '\0')
	{
		if (ft_isdigit(str[v[0]]) == 0)
			break ;
		a = a * 10 + str[v[0]] - '0';
		v[0]++;
	}
	return ((int)v[1] * a);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
