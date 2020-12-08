/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:18:58 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/22 17:01:24 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_minirt.h"

void	ft_create_img1(int i, int cam)
{
	int		j;
	t_vec3	col;

	j = 0;
	while (j < g_res_v.y)
	{
		col = color(camera_f(g_cs[cam], i / g_res_v.x, j / g_res_v.y));
		g_img_v.img.data[(int)j * (int)g_res_v.x + (int)i] =
			ft_num_color((int)(col.x * 255), (int)(col.y * 255),
					(int)(col.z * 255));
		j++;
	}
	return ;
}
int		ft_obj_select(int x, int y)
{
	float	t;
	float	t_o;
	int		i;
	int		index;
	t_ray	r;

	index = -1;
	i = g_obj_num - 1;
	t_o = T_MAX;
	r = camera_f(g_cs[g_pt_cam], x / g_res_v.x, y / g_res_v.y);
	while (i >= 0)
	{
		if (g_objs[i].id == 1 && (t = hit_sphere(g_objs[i].sp, r)) && t < t_o && (t_o = t))
			index = i;
		if (g_objs[i].id == 2 && (t = hit_plane(g_objs[i].pl, r)) && t < t_o && (t_o = t))
			index = i;
		if (g_objs[i].id == 5 && (t = hit_triangle(g_objs[i].tr, r)) && t < t_o && (t_o = t))
			index = i;
		if (g_objs[i].id == 4 && (t = hit_cylinder(g_objs[i].cy, r)) && t < t_o && (t_o = t))
			index = i;
		if (g_objs[i].id == 3 && (t = hit_square(g_objs[i].sq, r)) && t < t_o && (t_o = t))
			index = i;
		i--;
	}	
	return (index);
}

int		mouse_pressed(int mouse, int x, int y, void *param)
{
	param = NULL;
	if (mouse == 2)
	{
		g_edit.lig.x = 0;
		g_edit.obj = ft_obj_select(x, y);
	if (g_edit.obj == -1)
		return (ft_putstr("nothing\n"));
	if (g_objs[g_edit.obj].id == 1)
		return (ft_putstr("sphere selected\n"));
	if (g_objs[g_edit.obj].id == 2)
		return (ft_putstr("plane selected\n"));
	if (g_objs[g_edit.obj].id == 3)
		return (ft_putstr("square selected\n"));
	if (g_objs[g_edit.obj].id == 4)
		return (ft_putstr("cylinder selected\n"));
	if (g_objs[g_edit.obj].id == 5)
		return (ft_putstr("triangle selected\n"));
	}
	return (0);
}
int		ft_create_img(int cam)
{
	float	i;

	(g_start == 0) ? init_img() : 1;
	g_img_v.img.data = (int*)mlx_get_data_addr(g_img_v.img.img_ptr,
	&g_img_v.img.bpp, &g_img_v.img.size_l, &g_img_v.img.endian);
	i = -1;
	while (++i < g_res_v.x)
		ft_create_img1(i, cam);
	mlx_put_image_to_window(g_img_v.ptr,
	g_img_v.win, g_img_v.img.img_ptr, 0, 0);
	mlx_hook(g_img_v.win, 17, 0, ft_close, NULL);
	mlx_key_hook(g_img_v.win, key_pressed, NULL);
	mlx_mouse_hook(g_img_v.win, mouse_pressed, NULL);
	mlx_loop(g_img_v.ptr);
	return (0);
}

int		file_check(char *str)
{
	int i;
	int x;

	x = 1;
	i = ft_strlen(str) - 1;
	(str[i] != 't') ? x = 0 : 1;
	(str[i - 1] != 'r') ? x = 0 : 1;
	(str[i - 2] != '.') ? x = 0 : 1;
	if (x == 0)
		g_error = 16;
	return (x);
}

int		main(int ac, char **av)
{
	if (ac <= 1 || ac > 3)
		return (ft_putstr("Error\nWrong number of argements\n"));
	init_vars();
	(file_check(av[1])) ? file_h(av) : 1;
	if (g_error)
		return (return_fun());
	if (!av[2])
		ft_create_img(g_pt_cam);
	else if (ft_strcmp(av[2], "--save"))
		save_img(g_pt_cam);
	else
		g_error = 14;
	if (g_error)
		return (return_fun());
	free_fun();
	return (0);
}
