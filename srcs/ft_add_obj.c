/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:17:19 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/19 16:32:05 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

void	add_sp(void)
{
	t_objs_uv *new;
	t_objs_uv *temp;

	if (!(new = copy_objs()))
		return ;
	new[g_obj_num].sp = g_sphere_v;
	new[g_obj_num].id = 1;
	temp = g_objs;
	g_objs = new;
	g_mv_app = 2;
	g_last[0] = 2;
	g_last[1] = g_obj_num;
	free(temp);
}

void	add_pl(void)
{
	t_objs_uv *new;
	t_objs_uv *temp;

	if (!(new = copy_objs()))
		return ;
	g_plane_v.nor = v_unit(g_plane_v.nor);
	new[g_obj_num].pl = g_plane_v;
	new[g_obj_num].id = 2;
	temp = g_objs;
	g_objs = new;
	g_mv_app = 2;
	g_last[0] = 2;
	g_last[1] = g_obj_num;
	free(temp);
}

void	add_sq(void)
{
	t_objs_uv *new;
	t_objs_uv *temp;

	if (!(new = copy_objs()))
		return ;
	g_square_v.nor = v_unit(g_square_v.nor);
	new[g_obj_num].sq = g_square_v;
	new[g_obj_num].id = 3;
	temp = g_objs;
	g_objs = new;
	g_mv_app = 2;
	g_last[0] = 2;
	g_last[1] = g_obj_num;
	free(temp);
}

void	add_cy(void)
{
	t_objs_uv *new;
	t_objs_uv *temp;

	if (!(new = copy_objs()))
		return ;
	g_cylinder_v.nor = v_unit(g_cylinder_v.nor);
	new[g_obj_num].cy = g_cylinder_v;
	new[g_obj_num].id = 4;
	temp = g_objs;
	g_mv_app = 2;
	g_objs = new;
	g_last[0] = 2;
	g_last[1] = g_obj_num;
	free(temp);
}

void	add_tr(void)
{
	t_objs_uv *new;
	t_objs_uv *temp;

	if (!(new = copy_objs()))
		return ;
	new[g_obj_num].tr = g_triangle_v;
	new[g_obj_num].id = 5;
	temp = g_objs;
	g_objs = new;
	g_mv_app = 2;
	g_last[0] = 2;
	g_last[1] = g_obj_num;
	free(temp);
}
