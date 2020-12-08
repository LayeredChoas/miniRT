/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objs_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:11:42 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/18 16:13:49 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_minirt.h"

void	ft_res(char *str)
{
	int i;

	i = 1;
	g_res_v.id = 1;
	g_res_v.error = 0;
	i += ft_skip_space(&str[i]);
	g_res_v.x = ft_atoi(&str[i]);
	while (ft_isanum(str[i]))
		i++;
	i += ft_skip_space(&str[i]);
	g_res_v.y = ft_atoi(&str[i]);
	while (ft_isanum(str[i]))
		i++;
	i += ft_skip_space(&str[i]);
	if (str[i] || g_res_v.x <= 0 || g_res_v.y <= 0)
		g_res_v.error = 1;
	if (g_res_v.x > 3190)
		g_res_v.x = 3190;
	if (g_res_v.y > 1700)
		g_res_v.y = 1700;
	if (g_res_v.x <= 0 || g_res_v.y <= 0)
		g_res_v.error = 1;
}

void	ft_amb(char *str)
{
	int i;
	int x;

	g_amb_v.id = 1;
	g_amb_v.error = 0;
	i = 1;
	i += ft_skip_space(&str[i]);
	g_amb_v.l = ft_atoi_float(&str[i]);
	i += ft_float_skip(&str[i]);
	i += ft_skip_space(&str[i]);
	x = ft_col_fill(&g_amb_v.col, &str[i]);
	if (x <= 2)
		g_amb_v.error = 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i] || g_amb_v.l < 0 || g_amb_v.l > 1 || ft_col_check(g_amb_v.col))
		g_amb_v.error = 1;
}

void	ft_camera(char *str)
{
	int i;
	int x;

	i = 1;
	g_camera_v.id = 1;
	g_camera_v.error = 0;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_camera_v.cor, &str[i]);
	if (x <= 2)
		g_camera_v.error = 1;
	i += x;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_camera_v.nor, &str[i]);
	if (x <= 2)
		g_camera_v.error = 1;
	i += x;
	i += ft_skip_space(&str[i]);
	g_camera_v.fov = ft_atoi(&str[i]);
	while (ft_isanum(str[i]))
		i++;
	i += ft_skip_space(&str[i]);
	if (str[i] != '\0' || g_camera_v.fov <= 0 || g_camera_v.fov >= 180 ||
			ft_range(g_camera_v.nor, -1, 1) == 1)
		g_camera_v.error = 1;
}

void	ft_light(char *str)
{
	int i;
	int x;

	i = 1;
	g_light_v.id = 1;
	g_light_v.error = 0;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_light_v.cor, &str[i]);
	if (x <= 2)
		g_light_v.error = 1;
	i += x;
	i += ft_skip_space(&str[i]);
	g_light_v.ratio = ft_atoi_float(&str[i]);
	i += ft_float_skip(&str[i]);
	i += ft_skip_space(&str[i]);
	x = ft_col_fill(&g_light_v.col, &str[i]);
	if (x < 0)
		g_light_v.error = 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i] || g_light_v.ratio < 0 || g_light_v.ratio > 1 ||
			ft_col_check(g_light_v.col) == 1)
		g_light_v.error = 1;
}

void	ft_sphere(char *str)
{
	int i;
	int x;

	g_sphere_v.id = 1;
	g_sphere_v.error = 0;
	i = 2;
	i += ft_skip_space(&str[i]);
	x = ft_cor_fill(&g_sphere_v.cor, &str[i]);
	(x <= 2) ? g_sphere_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	(!ft_isanum(str[i])) ? g_sphere_v.error = 1 : 1;
	g_sphere_v.d = ft_atoi_float(&str[i]);
	x = ft_float_skip(&str[i]);
	(x <= 0) ? g_sphere_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	x = ft_col_fill(&g_sphere_v.col, &str[i]);
	(x <= 2) ? g_sphere_v.error = 1 : 1;
	i += x;
	i += ft_skip_space(&str[i]);
	if (str[i] != '\0' || g_sphere_v.d <= 0 ||
	ft_col_check(g_sphere_v.col) == 1)
		g_sphere_v.error = 1;
}
