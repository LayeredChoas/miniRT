/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_objs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:03:22 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

void	rest_sp(void)
{
	g_sphere_v.id = 0;
	g_sphere_v.cor = v_create(0, 0, 0);
	g_sphere_v.d = 0;
	g_sphere_v.col = v_create(0, 0, 0);
	g_sphere_v.error = 0;
}

void	rest_pl(void)
{
	g_plane_v.id = 0;
	g_plane_v.cor = v_create(0, 0, 0);
	g_plane_v.nor = v_create(0, 0, 0);
	g_plane_v.col = v_create(0, 0, 0);
	g_plane_v.error = 0;
}

void	rest_sq(void)
{
	g_square_v.id = 0;
	g_square_v.cor = v_create(0, 0, 0);
	g_square_v.nor = v_create(0, 0, 0);
	g_square_v.col = v_create(0, 0, 0);
	g_square_v.s = 0;
	g_square_v.error = 0;
}

void	rest_cy(void)
{
	g_cylinder_v.id = 0;
	g_cylinder_v.nor = v_create(0, 0, 0);
	g_cylinder_v.cor = v_create(0, 0, 0);
	g_cylinder_v.col = v_create(0, 0, 0);
	g_cylinder_v.d = 0;
	g_cylinder_v.h = 0;
	g_cylinder_v.error = 0;
}

void	rest_tr(void)
{
	g_triangle_v.id = 0;
	g_triangle_v.x = v_create(0, 0, 0);
	g_triangle_v.y = v_create(0, 0, 0);
	g_triangle_v.z = v_create(0, 0, 0);
	g_triangle_v.col = v_create(0, 0, 0);
	g_triangle_v.error = 0;
}
