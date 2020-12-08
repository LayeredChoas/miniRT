/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:16:59 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/19 14:09:07 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

void	init_cam(t_camera cam)
{
	g_res_v.asp = g_res_v.x / g_res_v.y;
	g_res_v.hi = tan(cam.fov * M_PI / 180 / 2);
	g_res_v.w = g_res_v.asp * g_res_v.hi;
}

t_ray	camera_f(t_camera cam, float x, float y)
{
	t_vec3 v1[3];
	t_vec3 v2[3];
	t_vec3 up;

	init_cam(cam);
	up = v_create(0, 1, 0);
	if (cam.nor.x == 0 && cam.nor.y == 1 && cam.nor.z == 0)
		up = v_create(0, 0, -1);
	if (cam.nor.x == 0 && cam.nor.y == -1 && cam.nor.z == 0)
		up = v_create(0, 0, 1);
	cam.right = v_unit(v_cross(cam.nor, up));
	cam.up = v_cross(cam.right, cam.nor);
	v1[0] = v_num_mult(-1, cam.nor);
	v1[2] = cam.right;
	v1[1] = cam.up;
	cam.lower_left = v_sub(cam.cor, v_num_mult(g_res_v.w, v1[2]));
	cam.lower_left = v_sub(cam.lower_left, v_num_mult(g_res_v.hi, v1[1]));
	cam.lower_left = v_sub(cam.lower_left, v1[0]);
	v2[0] = v_num_mult(2 * g_res_v.w, v1[2]);
	v2[1] = v_num_mult(2 * g_res_v.hi, v1[1]);
	v2[2] = v_add(cam.lower_left, v_num_mult(x, v2[0]));
	v2[2] = v_add(v2[2], v_num_mult(y, v2[1]));
	v2[2] = v_sub(v2[2], cam.cor);
	return (ray_create(cam.cor, v2[2]));
}
