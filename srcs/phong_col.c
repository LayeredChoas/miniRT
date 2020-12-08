/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:40:11 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_vec3	amb_fun(t_objs_uv ob)
{
	t_vec3 a;

	a = v_num_mult(g_amb_v.l, v_num_div(255, g_amb_v.col));
	a = v_mult_cof(a, v_num_div(255, obj_col(ob)));
	return (a);
}

t_vec3	diff_col(t_objs_uv ob, t_ray r, float t, int i)
{
	t_vec3	col[2];
	t_vec3	v[4];
	float	nl;
	float	ks;

	if (ft_shadow(t, r, g_ls[i]))
		return (BLACK);
	v[0] = objs_normal(ob, pt_at_parameter(t, r));
	v[1] = v_sub(pt_at_parameter(t, r), g_ls[i].cor);
	v[1] = v_unit(v[1]);
	v[0] = v_unit(v[0]);
	nl = v_mult_max(v[1], v[0]);
	col[0] = v_num_mult(g_ls[i].ratio * nl, v_num_div(255, obj_col(ob)));
	col[0] = v_mult_cof(v_num_div(255, g_ls[i].col), col[0]);
	v[2] = v_sub(r.o, pt_at_parameter(t, r));
	v[2] = v_num_mult(-1, v[2]);
	v[2] = v_unit(v[2]);
	v[3] = v_num_mult(2 * nl, v[0]);
	v[3] = v_sub(v[3], v[1]);
	v[3] = v_unit(v[3]);
	ks = 0.7 * g_ls[i].ratio * power(v_mult_max(v[3], v[2]), 50);
	col[1] = v_num_mult(ks, v_num_div(255, g_ls[i].col));
	return (v_add(col[0], col[1]));
}

t_vec3	diff_fun(t_objs_uv ob, t_ray r, float t, t_vec3 amb_col)
{
	t_vec3	final_col;
	int		i;

	i = 0;
	final_col = BLACK;
	while (i < g_lig_num)
	{
		final_col = v_add(final_col, diff_col(ob, r, t, i));
		i++;
	}
	final_col = v_add(final_col, amb_col);
	final_col = ft_col_prot_1(final_col);
	return (final_col);
}

t_vec3	light_ff(t_ray r, float t, t_objs_uv ob)
{
	t_vec3 amb_col;
	t_vec3 cof;

	amb_col = amb_fun(ob);
	if (g_lig_num == 0)
		return (amb_col);
	if (g_obj_num == 0)
		return (BLACK);
	cof = diff_fun(ob, r, t, amb_col);
	return (cof);
}

t_vec3	col_pix(int i, float t, float *t_old, t_ray r)
{
	t_vec3 col;

	*t_old = t;
	g_shadow_acne = i;
	col = light_ff(r, t, g_objs[i]);
	return (col);
}
