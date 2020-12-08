/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cor_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:34:44 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_minirt.h"

int		ft_isanum(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int		ft_cor_fill(t_vec3 *v, char *str)
{
	int i;

	i = 0;
	i += ft_skip_space(&str[i]);
	v->x = ft_atoi_float(&str[i]);
	i += ft_float_skip(&str[i]);
	if (str[i] != ',')
		return (-1);
	i++;
	v->y = ft_atoi_float(&str[i]);
	i += ft_float_skip(&str[i]);
	if (str[i] != ',')
		return (-1);
	i++;
	v->z = ft_atoi_float(&str[i]);
	i += ft_float_skip(&str[i]);
	return (i);
}

int		ft_float_skip(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isanum(str[i]))
		i++;
	if (str[i] && str[i] == '.')
		i++;
	while (str[i] && ft_isanum(str[i]))
		i++;
	return (i);
}

int		ft_skip_space(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int		ft_range(t_vec3 v, int a, int b)
{
	if (v.x < a || v.x > b || v.y < a || v.y > b || v.z < a || v.z > b)
		return (1);
	return (0);
}
