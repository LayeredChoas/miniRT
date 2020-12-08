/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:51:38 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/19 15:31:47 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

int			fail_check(void)
{
	if (g_res_v.error)
		g_error = 2;
	if (g_amb_v.error)
		g_error = 3;
	if (g_camera_v.error)
		g_error = 4;
	if (g_light_v.error)
		g_error = 5;
	if (g_sphere_v.error)
		g_error = 6;
	if (g_plane_v.error)
		g_error = 7;
	if (g_square_v.error)
		g_error = 8;
	if (g_cylinder_v.error)
		g_error = 9;
	if (g_triangle_v.error)
		g_error = 10;
	if (g_mv.error)
		g_error = 11;
	return (0);
}

void		rest_obj(int x)
{
	if (x == 1)
		rest_sp();
	if (x == 2)
		rest_pl();
	if (x == 3)
		rest_sq();
	if (x == 4)
		rest_cy();
	if (x == 5)
		rest_tr();
}

t_objs_uv	*copy_objs(void)
{
	int			i;
	t_objs_uv	*new;

	i = 0;
	if (!(new = malloc(sizeof(t_objs_uv) * (g_obj_num + 1))))
	{
		g_error = 101;
		return (NULL);
	}
	while (i < g_obj_num)
	{
		new[i] = g_objs[i];
		i++;
	}
	return (new);
}

void		add_to_objs(int x)
{
	(x == 1) ? add_sp() : 1;
	(x == 2) ? add_pl() : 1;
	(x == 3) ? add_sq() : 1;
	(x == 4) ? add_cy() : 1;
	(x == 5) ? add_tr() : 1;
	(x != 0) ? g_obj_num = g_obj_num + 1 : 1;
}
