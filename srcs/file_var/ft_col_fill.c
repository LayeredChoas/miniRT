/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:34:48 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_minirt.h"

int		ft_num_skip(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isanum(s[i]))
		i++;
	return (i);
}

int		ft_col_fill(t_vec3 *v, char *str)
{
	int i;

	i = 0;
	i += ft_skip_space(&str[i]);
	(ft_isanum(str[i])) ? v->x = atoi(&str[i]) : 1;
	if (ft_isanum(str[i]) == 0)
		return (-1);
	i += ft_num_skip(&str[i]);
	if (str[i] && str[i] != ',')
		return (-1);
	i++;
	if (!ft_isanum(str[i]))
		return (-1);
	v->y = atoi(&str[i]);
	i += ft_num_skip(&str[i]);
	if (str[i] && str[i] != ',')
		return (-1);
	i++;
	if (!ft_isanum(str[i]))
		return (-1);
	v->z = atoi(&str[i]);
	i += ft_num_skip(&str[i]);
	return (i);
}

int		ft_col_check(t_vec3 v)
{
	if (v.x < 0 || v.x > 255 || v.y < 0 || v.y > 255 || v.z < 0 || v.z > 255)
		return (1);
	return (0);
}
