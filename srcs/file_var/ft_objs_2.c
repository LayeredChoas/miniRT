/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objs_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:11:48 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/18 16:02:13 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_minirt.h"

void	ft_plane(char *str)
{
	int i;
	int x;

	g_plane_v.id = 1;
	g_plane_v.error = 0;
	i = 2;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_plane_v.cor, &str[i]);
	if (x <= 2)
		g_plane_v.error = 1;
	i += x;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_plane_v.nor, &str[i]);
	if (x <= 2)
		g_plane_v.error = 1;
	i += x;
	i += ft_skip_space(&str[i]);
	x = ft_col_fill(&g_plane_v.col, &str[i]);
	if (x <= 2)
		g_plane_v.error = 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i] || ft_col_check(g_plane_v.col) == 1 ||
			ft_range(g_plane_v.nor, -1, 1) == 1)
		g_plane_v.error = 1;
}

void	ft_square(char *str)
{
	int i;
	int x;

	i = 2;
	g_square_v.id = 1;
	g_square_v.error = 0;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_square_v.cor, &str[i]);
	(x <= 2) ? g_square_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_square_v.nor, &str[i]);
	(x <= 2) ? g_square_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	g_square_v.s = ft_atoi_float(&str[i]);
	i += ft_float_skip(&str[i]);
	i += ft_skip_space(&str[i]);
	x = ft_col_fill(&g_square_v.col, &str[i]);
	(x <= 2) ? g_square_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i] != '\0' || ft_col_check(g_square_v.col) == 1 ||
			ft_range(g_square_v.nor, -1, 1) == 1 || g_square_v.s <= 0)
		g_square_v.error = 1;
}

void	ft_cylinder(char *str)
{
	int i;
	int x;

	g_cylinder_v.id = 1;
	g_cylinder_v.error = 0;
	i = 2;
	x = ft_cor_fill(&g_cylinder_v.cor, &str[i]);
	(x <= 2) ? g_cylinder_v.error = 1 : 1;
	i += x;
	x = ft_cor_fill(&g_cylinder_v.nor, &str[i]);
	(x <= 2) ? g_cylinder_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	g_cylinder_v.d = ft_atoi_float(&str[i]);
	i += ft_float_skip(&str[i]);
	i += ft_skip_space(&str[i]);
	g_cylinder_v.h = ft_atoi_float(&str[i]);
	i += ft_float_skip(&str[i]);
	x = ft_col_fill(&g_cylinder_v.col, &str[i]);
	(x <= 2) ? g_cylinder_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i] || ft_col_check(g_cylinder_v.col) == 1 || g_cylinder_v.d < 0
			|| g_cylinder_v.h < 0 || ft_range(g_cylinder_v.nor, -1, 1))
		g_cylinder_v.error = 1;
}

void	ft_triangle(char *str)
{
	int i;
	int x;

	i = 2;
	g_triangle_v.id = 1;
	g_triangle_v.error = 0;
	x = ft_cor_fill(&g_triangle_v.x, &str[i]);
	(x <= 2) ? g_triangle_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_triangle_v.y, &str[i]);
	(x <= 2) ? g_triangle_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_triangle_v.z, &str[i]);
	(x <= 2) ? g_triangle_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	x = ft_col_fill(&g_triangle_v.col, &str[i]);
	(x <= 2) ? g_triangle_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i] || ft_col_check(g_triangle_v.col))
		g_triangle_v.error = 1;
}
