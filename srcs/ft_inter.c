/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:02:17 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/20 13:46:34 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

float	hit_sphere(t_sphere sp, t_ray r)
{
	float	x[4];
	float	t[2];
	t_vec3	oc;

	oc = v_sub(r.o, sp.cor);
	x[0] = v_mult(r.d, r.d);
	x[1] = 2.0 * v_mult(oc, r.d);
	x[2] = v_mult(oc, oc) - (sp.d / 2) * (sp.d / 2);
	x[3] = x[1] * x[1] - 4 * x[0] * x[2];
	if (x[3] < 0)
		return (0);
	t[0] = (-x[1] - sqrt(x[3])) / (2 * x[0]);
	if (x[3] == 0)
		return (t[0] > 0);
	t[1] = (-x[1] + sqrt(x[3])) / (2 * x[0]);
	if (t[0] < t[1] && t[0] > 0)
		return (t[0]);
	if (t[1] > 0)
		return (t[1]);
	return (0);
}

float	hit_plane(t_plane p, t_ray r)
{
	float t;
	float a;
	float b;

	a = v_mult(v_sub(r.o, p.cor), p.nor);
	b = v_mult(r.d, p.nor);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t = -a / b;
	return (t > 0 ? t : 1);
}

void	init_cy(t_cylinder cl, t_ray r)
{
	g_pcy[0] = v_sub(r.o, cl.cor);
	g_pcy[1] = v_sub(r.d, v_num_mult(v_mult(r.d, cl.nor), cl.nor));
	g_pcy[2] = v_sub(g_pcy[0], v_num_mult(v_mult(g_pcy[0], cl.nor), cl.nor));
}

float	hit_cylinder(t_cylinder cl, t_ray r)
{
	float	x[4];
	float	t[2];

	init_cy(cl, r);
	cl.nor = v_unit(cl.nor);
	x[0] = vec_length(g_pcy[1]) * vec_length(g_pcy[1]);
	x[1] = 2.0 * v_mult(g_pcy[1], g_pcy[2]);
	x[2] = vec_length(g_pcy[2]) * vec_length(g_pcy[2]) -
	(cl.d / 2) * (cl.d / 2);
	g_pcy[3] = v_sub(cl.cor, v_num_mult(cl.h / 2.0, cl.nor));
	g_pcy[4] = v_add(cl.cor, v_num_mult(cl.h / 2.0, cl.nor));
	x[3] = x[1] * x[1] - 4 * x[0] * x[2];
	if (x[3] < 0)
		return (0);
	t[0] = (-x[1] + sqrt(x[3])) / (2.0 * x[0]);
	t[1] = (-x[1] - sqrt(x[3])) / (2.0 * x[0]);
	g_pcy[5] = v_add(r.o, v_num_mult(t[0], r.d));
	if (t[0] > 0.0 && v_mult(cl.nor, v_sub(g_pcy[5], g_pcy[3])) > 0.0
	&& v_mult(cl.nor, v_sub(g_pcy[5], g_pcy[4])) < 0.0)
		return (t[0]);
	g_pcy[5] = v_add(r.o, v_num_mult(t[1], r.d));
	if (t[1] > 0.0 && v_mult(cl.nor, v_sub(g_pcy[5], g_pcy[3])) > 0.0
	&& v_mult(cl.nor, v_sub(g_pcy[5], g_pcy[4])) < 0.0)
		return ((t[0] > t[1]) ? t[0] : t[1]);
	return (0);
}

float	hit_square(t_square s, t_ray r)
{
	float	t;
	float	dd;
	t_vec3	p;
	t_vec3	p0;
	t_plane pl;

	pl.cor = s.cor;
	pl.nor = s.nor;
	if (hit_plane(pl, r) > 0.00001)
	{
		dd = v_mult(s.nor, r.d);
		p0 = v_sub(s.cor, r.o);
		t = v_mult(p0, s.nor) / dd;
		p = v_add(r.o, v_num_mult(t, r.d));
		if (t > 0)
		{
			if (fabs(p.x - s.cor.x) <= (s.s / 2) && fabs(p.y - s.cor.y)
			<= (s.s / 2) && fabs(p.z - s.cor.z) <= (s.s / 2))
				return (t);
		}
	}
	return (0);
}
