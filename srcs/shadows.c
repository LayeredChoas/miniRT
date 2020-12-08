/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:42:53 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 20:06:43 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_vec3	obj_col(t_objs_uv ob)
{
	if (ob.id == 1)
		return (ob.sp.col);
	if (ob.id == 2)
		return (ob.pl.col);
	if (ob.id == 3)
		return (ob.sq.col);
	if (ob.id == 4)
		return (ob.cy.col);
	if (ob.id == 5)
		return (ob.tr.col);
	return (BLACK);
}

int		ft_shadow(float t, t_ray r, t_light li)
{
	t_vec3		hit_pt;
	t_ray		r1;
	int			j;

	j = 0;
	hit_pt = v_add(r.o, v_num_mult(t, r.d));
	r1 = ray_create(hit_pt, li.cor);
	while (j < g_obj_num)
	{
		if (g_objs[j].id == 1 && j != g_shadow_acne)
			if (hit_sphere(g_objs[j].sp, r1))
				return (1);
		if (g_objs[j].id == 5 && j != g_shadow_acne)
			if (hit_triangle(g_objs[j].tr, r1))
				return (1);
		if (g_objs[j].id == 3 && j != g_shadow_acne)
			if (hit_square(g_objs[j].sq, r1))
				return (1);
		if (g_objs[j].id == 4 && j != g_shadow_acne)
			if (hit_cylinder(g_objs[j].cy, r1))
				return (1);
		j++;
	}
	return (0);
}
