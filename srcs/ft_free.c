/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:51:01 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/21 20:08:06 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

int		free_fun(void)
{
	if (g_obj_num > 0)
		free(g_objs);
	if (g_cam_num > 0)
		free(g_cs);
	if (g_lig_num > 0)
		free(g_ls);
	return (0);
}

void	init_vars(void)
{
	g_obj_num = 0;
	g_cam_num = 0;
	g_lig_num = 0;
	g_error = 0;
	g_pt_cam = 0;
	g_mv_app = 0;
	g_shadow_acne = 0;
	g_edit.mv.id = -1;
	g_edit.rot.id = -1;
	g_edit.mv.id = 0;
	g_edit.rot.id = 0;
	g_edit.size = 0;
	g_edit.lig.id = -1;
}

void	init_img(void)
{
	g_start = 1;
	g_img_v.ptr = mlx_init();
	g_img_v.win = mlx_new_window(g_img_v.ptr, g_res_v.x, g_res_v.y, "miniRT");
	g_img_v.img.img_ptr = mlx_new_image(g_img_v.ptr, g_res_v.x, g_res_v.y);
}
