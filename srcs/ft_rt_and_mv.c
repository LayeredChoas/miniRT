/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_and_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:36:26 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/20 13:46:04 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

void	rest_mv(void)
{
	g_mv.id = 0;
	g_mv.mv = v_create(0, 0, 0);
	g_mv.rt = v_create(0, 0, 0);
	g_mv.error = 0;
}

t_vec3	rt_fun(t_vec3 v)
{
	t_vec3 temp;

	temp = v_unit(v);
	v.y = temp.y * cos(rad(g_mv.rt.x)) + temp.z * (-sin(rad(g_mv.rt.x)));
	v.z = temp.y * sin(rad(g_mv.rt.x)) + temp.z * cos(rad(g_mv.rt.x));
	temp = v;
	v.x = temp.x * cos(rad(g_mv.rt.y)) + temp.z * sin(rad(g_mv.rt.y));
	v.z = temp.x * (-sin(rad(g_mv.rt.y))) + temp.z * cos(rad(g_mv.rt.y));
	temp = v;
	v.x = temp.x * cos(rad(g_mv.rt.z)) + temp.y * (-sin(rad(g_mv.rt.z)));
	v.y = temp.x * sin(rad(g_mv.rt.z)) + temp.y * (cos(rad(g_mv.rt.z)));
	return (v);
}

void	mv_obj(void)
{
	if (g_objs[g_last[1]].id == 1)
		g_objs[g_last[1]].sp.cor = v_add(g_objs[g_last[1]].sp.cor, g_mv.mv);
	if (g_objs[g_last[1]].id == 2)
		g_objs[g_last[1]].pl.cor = v_add(g_objs[g_last[1]].pl.cor, g_mv.mv);
	if (g_objs[g_last[1]].id == 3)
		g_objs[g_last[1]].sq.cor = v_add(g_objs[g_last[1]].sq.cor, g_mv.mv);
	if (g_objs[g_last[1]].id == 4)
		g_objs[g_last[1]].cy.cor = v_add(g_objs[g_last[1]].cy.cor, g_mv.mv);
	if (g_objs[g_last[1]].id == 5)
	{
		g_objs[g_last[1]].tr.x = v_add(g_objs[g_last[1]].tr.x, g_mv.mv);
		g_objs[g_last[1]].tr.y = v_add(g_objs[g_last[1]].tr.y, g_mv.mv);
		g_objs[g_last[1]].tr.z = v_add(g_objs[g_last[1]].tr.z, g_mv.mv);
	}
}

void	rt_obj(void)
{
	if (g_objs[g_last[1]].id == 1 || g_objs[g_last[1]].id == 5)
		g_error = 12;
	if (g_objs[g_last[1]].id == 2)
		g_objs[g_last[1]].pl.nor = rt_fun(g_objs[g_last[1]].pl.nor);
	if (g_objs[g_last[1]].id == 3)
		g_objs[g_last[1]].sq.nor = rt_fun(g_objs[g_last[1]].sq.nor);
	if (g_objs[g_last[1]].id == 4)
		g_objs[g_last[1]].cy.nor = rt_fun(g_objs[g_last[1]].cy.nor);
}

void	ft_mv_app(void)
{
	if (g_lig_num == 0 && g_obj_num == 0 && g_cam_num == 0)
		g_error = 20;
	if (g_last[0] == 1 && g_mv.id == 1)
		g_cs[g_last[1]].cor = v_add(g_cs[g_last[1]].cor, g_mv.mv);
	if (g_last[0] == 2 && g_mv.id == 1)
		mv_obj();
	if (g_last[0] == 3 && g_mv.id == 1)
		g_ls[g_last[1]].cor = v_add(g_ls[g_last[1]].cor, g_mv.mv);
	if (g_last[0] == 1 && g_mv.id == 2)
		g_cs[g_last[1]].nor = rt_fun(g_cs[g_last[1]].nor);
	if (g_last[0] == 2 && g_mv.id == 2)
		rt_obj();
	if (g_last[0] == 3 && g_mv.id == 2)
		g_error = 13;
	rest_mv();
}
