/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:30:00 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/22 20:30:22 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_minirt.h"

int		ft_close(void)
{
	mlx_clear_window(g_img_v.ptr, g_img_v.win);
	mlx_destroy_image(g_img_v.ptr, g_img_v.win);
	exit(0);
}

int ft_axes(int x)
{
	ft_putstr("\033[0;33m");
	(x == 0) ? ft_putstr("x axes\n") : 1;
	(x == 1) ? ft_putstr("y axes\n") : 1;
	(x == 2) ? ft_putstr("z axes\n") : 1;
	if (g_edit.mv.x)
	{
		(x == 0) ? g_edit.mv.axe = 1 : 1;
		(x == 1) ? g_edit.mv.axe = 2 : 1;
		(x == 2) ? g_edit.mv.axe = 3 : 1;
		ft_putstr("\033[0m");
		return (0);
	}
	if (g_edit.rot.x)
	{
		(x == 0) ? g_edit.rot.axe = 1 : 1;
		(x == 1) ? g_edit.rot.axe = 2 : 1;
		(x == 2) ? g_edit.rot.axe = 3 : 1;
		ft_putstr("\033[0m");
		return (0);
	}
	if (g_edit.lig.x)
	{
		(x == 0) ? g_edit.lig.axe = 1 : 1;
		(x == 1) ? g_edit.lig.axe = 2 : 1;
		(x == 2) ? g_edit.lig.axe = 3 : 1;
		ft_putstr("\033[0m");
		return (0);
	}
	return (0);
}

void	ft_update_lig()
{
	t_vec3 cor;
	t_vec3 mov;
	
	if (g_edit.lig.x)
	{
		cor = g_ls[g_edit.lig.id].cor;
		(g_edit.lig.axe == 1) ?  mov = v_create(1, 0, 0) : BLACK;
		(g_edit.lig.axe == 2) ?  mov = v_create(0, 1, 0) : BLACK;
		(g_edit.lig.axe == 3) ?  mov = v_create(0, 0, 1) : BLACK;
		(g_edit.dir == 1) ? g_ls[g_edit.lig.id].cor = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_ls[g_edit.lig.id].cor = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
		return ;
	}
}

t_vec3 ft_fix_nor(t_vec3 nor)
{
	(nor.x > 1.1) ? nor.x = -1 : 1;
	(nor.y > 1.1) ? nor.y = -1 : 1;
	(nor.z > 1.1) ? nor.z = -1 : 1;
	(nor.x < -1.1) ? nor.x = 1 : 1;
	(nor.y < -1.1) ? nor.y = 1 : 1;
	(nor.z < -1.1) ? nor.z = 1 : 1;
	return (nor);
}

void	ft_update_rot(void)
{
	t_vec3 mov;
	t_vec3 cor;
	if (g_objs[g_edit.obj].id == 2)
	{
		(g_edit.rot.axe == 1) ?  mov = v_create(0.1, 0, 0) : BLACK;
		(g_edit.rot.axe == 2) ?  mov = v_create(0, 0.1, 0) : BLACK;
		(g_edit.rot.axe == 3) ?  mov = v_create(0, 0, 0.1) : BLACK;
		cor = g_objs[g_edit.obj].pl.nor;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].pl.nor = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].pl.nor = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
		g_objs[g_edit.obj].pl.nor = ft_fix_nor(g_objs[g_edit.obj].pl.nor);
		g_objs[g_edit.obj].pl.nor = v_unit(g_objs[g_edit.obj].pl.nor);
	}
	if (g_objs[g_edit.obj].id == 3)
	{
		(g_edit.rot.axe == 1) ?  mov = v_create(0.1, 0, 0) : BLACK;
		(g_edit.rot.axe == 2) ?  mov = v_create(0, 0.1, 0) : BLACK;
		(g_edit.rot.axe == 3) ?  mov = v_create(0, 0, 0.1) : BLACK;
		cor = g_objs[g_edit.obj].sq.nor;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].sq.nor = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].sq.nor = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
		g_objs[g_edit.obj].sq.nor = ft_fix_nor(g_objs[g_edit.obj].sq.nor);
		g_objs[g_edit.obj].sq.nor  = v_unit(g_objs[g_edit.obj].sq.nor);
	}
	if (g_objs[g_edit.obj].id == 4)
	{
		(g_edit.rot.axe == 1) ?  mov = v_create(0.1, 0, 0) : BLACK;
		(g_edit.rot.axe == 2) ?  mov = v_create(0, 0.1, 0) : BLACK;
		(g_edit.rot.axe == 3) ?  mov = v_create(0, 0, 0.1) : BLACK;
		cor = g_objs[g_edit.obj].sq.nor;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].cy.nor = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].cy.nor = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
		g_objs[g_edit.obj].cy.nor = ft_fix_nor(g_objs[g_edit.obj].cy.nor);
		g_objs[g_edit.obj].cy.nor = v_unit(g_objs[g_edit.obj].cy.nor);
	}
}

void	ft_update_var(void)
{
	t_vec3 cor;
	t_vec3 mov;
	if (g_edit.mv.x == 0 && g_edit.rot.x == 0)
		return ;
	if (g_objs[g_edit.obj].id == 1)
	{
		(g_edit.mv.axe == 1) ?  mov = v_create(1, 0, 0) : BLACK;
		(g_edit.mv.axe == 2) ?  mov = v_create(0, 1, 0) : BLACK;
		(g_edit.mv.axe == 3) ?  mov = v_create(0, 0, 1) : BLACK;
		cor = g_objs[g_edit.obj].sp.cor;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].sp.cor = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].sp.cor = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
	}
	if (g_objs[g_edit.obj].id == 2)
	{
		(g_edit.mv.axe == 1) ?  mov = v_create(1, 0, 0) : BLACK;
		(g_edit.mv.axe == 2) ?  mov = v_create(0, 1, 0) : BLACK;
		(g_edit.mv.axe == 3) ?  mov = v_create(0, 0, 1) : BLACK;
		cor = g_objs[g_edit.obj].pl.cor;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].pl.cor = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].pl.cor = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
	}
	if (g_objs[g_edit.obj].id == 3)
	{
		(g_edit.mv.axe == 1) ?  mov = v_create(1, 0, 0) : BLACK;
		(g_edit.mv.axe == 2) ?  mov = v_create(0, 1, 0) : BLACK;
		(g_edit.mv.axe == 3) ?  mov = v_create(0, 0, 1) : BLACK;
		cor = g_objs[g_edit.obj].sq.cor;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].sq.cor = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].sq.cor = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
	}
	if (g_objs[g_edit.obj].id == 4)
	{
		(g_edit.mv.axe == 1) ?  mov = v_create(1, 0, 0) : BLACK;
		(g_edit.mv.axe == 2) ?  mov = v_create(0, 1, 0) : BLACK;
		(g_edit.mv.axe == 3) ?  mov = v_create(0, 0, 1) : BLACK;
		cor = g_objs[g_edit.obj].sq.cor;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].cy.cor = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].cy.cor = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
	}
	if (g_objs[g_edit.obj].id == 5)
	{
		(g_edit.mv.axe == 1) ?  mov = v_create(1, 0, 0) : BLACK;
		(g_edit.mv.axe == 2) ?  mov = v_create(0, 1, 0) : BLACK;
		(g_edit.mv.axe == 3) ?  mov = v_create(0, 0, 1) : BLACK;
		cor = g_objs[g_edit.obj].tr.x;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].tr.x = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].tr.x = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
		cor = g_objs[g_edit.obj].tr.y;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].tr.y = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].tr.y = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
		cor = g_objs[g_edit.obj].tr.z;
		(g_edit.dir == 1) ? g_objs[g_edit.obj].tr.z = v_add(cor, mov) : BLACK;
		(g_edit.dir == -1) ? g_objs[g_edit.obj].tr.z = v_add(cor, v_num_mult(-1 , mov)) : BLACK;
	}
}

void	ft_update_size(void)
{
	float size;
	float h;
	
	if (g_objs[g_edit.obj].id == 1)
	{
		size = g_objs[g_edit.obj].sp.d;
		(g_edit.dir == 1 && size >= 1) ? g_objs[g_edit.obj].sp.d = size + 1 : 1;
		(g_edit.dir == -1 && size > 1) ? g_objs[g_edit.obj].sp.d = size - 1 : 1;
	}
	if (g_objs[g_edit.obj].id == 3)
	{
		size = g_objs[g_edit.obj].sq.s;
		(g_edit.dir == 1 && size > 1) ? g_objs[g_edit.obj].sq.s = size + 1 : 1;
		(g_edit.dir == -1 && size > 1) ? g_objs[g_edit.obj].sq.s = size - 1 : 1;
	}
	if (g_objs[g_edit.obj].id == 4)
	{
		size = g_objs[g_edit.obj].cy.d;
		h = g_objs[g_edit.obj].cy.h;
		(g_edit.dir == 1 && size > 1) ? g_objs[g_edit.obj].cy.d = size + 1 : 1;
		(g_edit.dir == 1 && size > 1) ? g_objs[g_edit.obj].cy.h = size + 1 : 1;
		(g_edit.dir == -1 && h > 1) ? g_objs[g_edit.obj].cy.d = size - 1 : 1;
		(g_edit.dir == -1 && h > 1) ? g_objs[g_edit.obj].cy.h = size - 1 : 1;
	}
}

int init_move(void)
{
	ft_putstr("\033[0;33m");
	if (g_edit.lig.x && g_edit.mv.x == 0)
	{
		g_edit.mv.x = 0;
		g_edit.rot.x = 0;
		g_edit.size = 0;
		ft_putstr("light ");
	}
	else
	{
		g_edit.mv.x = 1;
		g_edit.lig.x = 0;
		g_edit.rot.x = 0;
		g_edit.size = 0;
		ft_putstr("object ");
	}
	ft_putstr("translation mode selected\n");
	ft_putstr("\033[0m");
	return (0);
}

int init_rot(void)
{
	g_edit.mv.x = 0;
	g_edit.rot.x = 1;
	g_edit.size = 0;
	g_edit.lig.x = 0;
	ft_putstr("\033[0;33m");
	ft_putstr("rot mode selected\n");
	ft_putstr("\033[0m");
	return (0);
}

int	init_size(void)
{
	g_edit.mv.x = 0;
	g_edit.rot.x = 0;
	g_edit.size = 1;
	g_edit.lig.x = 0;
	ft_putstr("\033[0;33m");
	ft_putstr("size mode selected\n");
	ft_putstr("\033[0m");
	return (0);
}

int	init_lig(void)
{
	g_edit.lig.x = 1;
	g_edit.lig.id++;
	if (g_edit.lig.id > g_lig_num - 1)
		g_edit.lig.id = 0;
	g_edit.mv.x = 0;
	g_edit.rot.x = 0;
	g_edit.size = 0;
	ft_putstr("\033[0;33m");
	ft_putnbr(g_edit.lig.id + 1, 1);
	ft_putstr(" light selected\n");
	ft_putstr("\033[0m");
	return (0);
}


int		 ft_export_data(void)
{
	int i;

	i = 0;
	ft_putstr("------------------------------------\n");
	while (i < g_obj_num)
	{
		if (g_objs[i].id == 1)
			ft_print_sphere(g_objs[i].sp);
		if (g_objs[i].id == 2)
			ft_print_plane(g_objs[i].pl);
		if (g_objs[i].id == 3)
			ft_print_square(g_objs[i].sq);
		if (g_objs[i].id == 4)
			ft_print_cylinder(g_objs[i].cy);
		if (g_objs[i].id == 5)
			ft_print_triangle(g_objs[i].tr);
		i++;
	}
	ft_putstr("------------------------------------\n");
	return (0);
}

int		key_pressed(int keycode, void *param)
{
	param = NULL;
	if (keycode == 0)
		return (0);
	if (keycode == EXIT)
	{
		mlx_destroy_image(g_img_v.ptr, g_img_v.win);
		mlx_clear_window(g_img_v.ptr, g_img_v.win);
		exit(0);
	}
	if (keycode == RIGHT)
	{
		mlx_clear_window(g_img_v.ptr, g_img_v.win);
		(g_pt_cam == g_cam_num - 1) ? g_pt_cam = 0 : g_pt_cam++;
		ft_create_img(g_pt_cam);
	}
	if (keycode == LEFT)
	{
		mlx_clear_window(g_img_v.ptr, g_img_v.win);
		g_pt_cam--;
		if (g_pt_cam < 0)
			g_pt_cam = g_cam_num - 1;
		ft_create_img(g_pt_cam);
	}
	(keycode == MOVE) ? init_move() : 1;
	(keycode == ROT) ? init_rot() : 1;
	(keycode == SIZE) ? init_size() : 1;
	(keycode == LIG) ? init_lig() : 1;
	(keycode == X) ? ft_axes(0) : 1;
	(keycode == Y) ? ft_axes(1) : 1;
	(keycode == Z) ? ft_axes(2) : 1;
	(keycode == EXPORT) ? ft_export_data() : 1;
	(keycode == SAVE) ? save_img(g_pt_cam) : 1;
	if (keycode == NEG || keycode == PLU)
	{
		(keycode == NEG) ? g_edit.dir = -1 : 1;
		(keycode == PLU) ? g_edit.dir = 1 : 1;
		mlx_clear_window(g_img_v.ptr, g_img_v.win);
		(g_edit.mv.x) ? ft_update_var() : 1;
		(g_edit.size) ? ft_update_size() : 1;
		(g_edit.lig.x) ? ft_update_lig() : 1;
		(g_edit.rot.x) ? ft_update_rot() : 1;
		ft_create_img(g_pt_cam);
	}
	return (0);
}
