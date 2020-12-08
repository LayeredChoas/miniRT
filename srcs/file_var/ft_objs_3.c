/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objs_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:08:29 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_minirt.h"

void	ft_mv(char *str)
{
	int i;
	int x;

	i = 2;
	g_mv.id = 1;
	g_mv.error = 0;
	x = ft_cor_fill(&g_mv.mv, &str[i]);
	(x <= 2) ? g_mv.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i])
		g_mv.error = 1;
}

void	ft_rt(char *str)
{
	int i;
	int x;

	i = 2;
	g_mv.id = 2;
	g_mv.error = 0;
	x = ft_cor_fill(&g_mv.rt, &str[i]);
	(x <= 2) ? g_mv.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i])
		g_mv.error = 1;
}
