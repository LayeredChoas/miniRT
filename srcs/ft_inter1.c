/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:49:50 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 20:36:35 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_triangle	init_tr(t_triangle tr)
{
	t_triangle temp;

	temp = tr;
	tr.x = v_sub(temp.x, temp.z);
	tr.y = v_sub(temp.y, temp.z);
	return (tr);
}

float		hit_triangle(t_triangle tr, t_ray r)
{
	float		x[2];
	float		ang[2];

	r.o = v_sub(r.o, tr.z);
	tr = init_tr(tr);
	x[1] = v_mult(v_cross(r.o, tr.x), tr.y);
	x[0] = v_mult(v_cross(r.d, tr.y), tr.x);
	if (x[0] == 0)
		return (0);
	x[0] = x[1] / x[0];
	x[1] = v_mult(v_cross(r.d, tr.y), r.o);
	ang[0] = v_mult(v_cross(r.d, tr.y), tr.x);
	if (ang[0] == 0)
		return (0);
	ang[0] = x[1] / ang[0];
	x[1] = v_mult(v_cross(r.o, tr.x), r.d);
	ang[1] = v_mult(v_cross(r.d, tr.y), tr.x);
	if (ang[1] == 0)
		return (0);
	ang[1] = x[1] / ang[1];
	if (x[0] > 0 && ang[1] >= 0 && ang[0] >= 0 && ang[0] + ang[1] <= 1)
		return (x[0]);
	return (0);
}
