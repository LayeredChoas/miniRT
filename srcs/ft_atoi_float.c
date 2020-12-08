/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:41:11 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

int			ft_point(int x)
{
	int		i;
	long	y;

	y = 1;
	i = 0;
	while (x / y > 0)
	{
		y *= 10;
		i++;
	}
	return (i);
}

float		ft_cal_div(int i)
{
	float x;

	x = 1;
	while (i > 0)
	{
		x *= 0.1;
		i--;
	}
	return (x);
}

float		ft_atoi_float(char *str)
{
	int		i;
	int		x[4];
	float	div;

	x[0] = 1;
	x[2] = 0;
	i = 0;
	x[3] = 0;
	(str[i] == '-') ? x[0] = -1 : 1;
	(str[i] == '-') ? i++ : 1;
	x[2] = ft_atoi(str);
	while (str[i] != '\0' && str[i] != ' ' && str[i] != ',')
	{
		if (str[i] == '.' && (x[3] = ft_atoi(&str[i + 1])) == 0)
			return (x[2]);
		else if (str[i] == '.')
			break ;
		i++;
	}
	i = ft_point(x[3]);
	div = ft_cal_div(i);
	if (x[2] >= 0)
		return (x[0] * (x[2] + div * x[3]));
	return (x[2] - div * x[3]);
}
