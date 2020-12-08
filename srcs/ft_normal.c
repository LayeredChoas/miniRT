/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:53:52 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/18 17:28:51 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_vec3	normal_plane(t_plane pl, t_vec3 p)
{
	t_vec3	normal;
	float	x;

	normal = pl.nor;
	x = v_mult(normal, p);
	if (x < 0)
		normal = v_num_mult(-1, normal);
	return (normal);
}

t_vec3	normal_sphere(t_sphere c, t_vec3 p)
{
	t_vec3 v;

	v = v_sub(c.cor, p);
	return (v_num_div(c.d / 2, v));
}

t_vec3	normal_triangle(t_triangle tr, t_vec3 p)
{
	t_vec3	ret;
	t_vec3	va;
	t_vec3	vb;
	float	x;

	ret = BLACK;
	va = v_sub(tr.y, tr.z);
	vb = v_sub(tr.x, tr.z);
	ret = v_unit(v_cross(vb, va));
	x = v_mult(ret, p);
	return (ret);
}

t_vec3	normal_cy(t_cylinder c, t_vec3 p)
{
	t_vec3	normal;
	t_vec3	new;

	normal = BLACK;
	new = v_sub(p, c.cor);
	normal = v_sub(new, v_num_mult(v_mult(c.nor, new), c.nor));
	normal = v_mult_cof(v_create(-1, -1, 1), normal);
	normal = v_unit(normal);
	return (normal);
}

t_vec3	normal_sq(t_square sq, t_vec3 p)
{
	t_vec3	normal;
	float	x;

	normal = sq.nor;
	x = v_mult(normal, p);
	if (x < 0)
		normal = v_num_mult(-1, normal);
	return (normal);
}
