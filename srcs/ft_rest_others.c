/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_others.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:01:25 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

void	rest_ca(void)
{
	g_camera_v.id = 0;
	g_camera_v.cor = v_create(0, 0, 0);
	g_camera_v.nor = v_create(0, 0, 0);
	g_camera_v.fov = 0;
	g_camera_v.error = 0;
}

void	rest_li(void)
{
	g_light_v.id = 0;
	g_light_v.cor = v_create(0, 0, 0);
	g_light_v.col = v_create(0, 0, 0);
	g_light_v.ratio = 0;
	g_light_v.error = 0;
}

int		exist_ca(void)
{
	if (g_camera_v.id == 1)
		return (1);
	return (0);
}

int		exist_li(void)
{
	if (g_light_v.id == 1)
		return (1);
	return (0);
}

int		exist_objs(void)
{
	if (g_sphere_v.id)
		return (1);
	if (g_plane_v.id)
		return (2);
	if (g_square_v.id)
		return (3);
	if (g_cylinder_v.id)
		return (4);
	if (g_triangle_v.id)
		return (5);
	return (0);
}
