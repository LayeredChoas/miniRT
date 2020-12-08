/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:31:06 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 20:03:28 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_ray		ray_create(t_vec3 v1, t_vec3 v2)
{
	t_ray new;

	new.o = v1;
	new.d = v2;
	return (new);
}

t_vec3		pt_at_parameter(float t, t_ray r)
{
	return (v_add(r.o, v_num_mult(t, r.d)));
}

t_vec3		ft_col_prot_1(t_vec3 v1)
{
	if (v1.x > 1.0)
		v1.x = 1;
	if (v1.y > 1.0)
		v1.y = 1;
	if (v1.z > 1.0)
		v1.z = 1;
	if (v1.x < 0.0)
		v1.x = 0;
	if (v1.y < 0.0)
		v1.y = 0;
	if (v1.z < 0.0)
		v1.z = 0;
	return (v1);
}

t_vec3		color(t_ray r)
{
	float	t;
	float	t_o;
	int		i;
	t_vec3	col;

	col = BLACK;
	i = g_obj_num - 1;
	t_o = T_MAX;
	while (i >= 0)
	{
		if (g_objs[i].id == 1 && (t = hit_sphere(g_objs[i].sp, r)) && t < t_o)
			col = col_pix(i, t, &t_o, r);
		if (g_objs[i].id == 2 && (t = hit_plane(g_objs[i].pl, r)) && t < t_o)
			col = col_pix(i, t, &t_o, r);
		if (g_objs[i].id == 5 && (t = hit_triangle(g_objs[i].tr, r)) && t < t_o)
			col = col_pix(i, t, &t_o, r);
		if (g_objs[i].id == 4 && (t = hit_cylinder(g_objs[i].cy, r)) && t < t_o)
			col = col_pix(i, t, &t_o, r);
		if (g_objs[i].id == 3 && (t = hit_square(g_objs[i].sq, r)) && t < t_o)
			col = col_pix(i, t, &t_o, r);
		i--;
	}
	return (col);
}
