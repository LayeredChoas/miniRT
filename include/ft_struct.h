/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:13:24 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/22 20:28:37 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "get_next_line.h"
# define BLACK v_create(0, 0, 0)
# define T_MAX 1000000
# define EXIT 53
# define RIGHT 124
# define LEFT 123
# define MOVE 46
# define X 7
# define Y 16
# define Z 6
# define ROT 15
# define NEG 78
# define PLU 69
# define SIZE 1
# define ONE v_create(1, 1, 0)
# define LIG 37
# define EXPORT 14
# define SAVE 65
typedef struct		s_vec3
{
	float x;
	float y;
	float z;
}					t_vec3;
typedef struct		s_ray
{
	t_vec3 o;
	t_vec3 d;
}					t_ray;

typedef struct		s_img1
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}					t_img1;
typedef struct		s_img
{
	void	*ptr;
	void	*win;
	t_img1	img;
}					t_img;

typedef struct		s_res
{
	int		id;
	float	x;
	float	y;
	float	asp;
	float	hi;
	float	w;
	int		error;
}					t_res;

typedef	struct		s_amb
{
	int		id;
	float	l;
	t_vec3	col;
	int		error;
}					t_amb;

typedef	struct		s_camera
{
	int		id;
	int		fov;
	int		error;
	t_vec3	cor;
	t_vec3	nor;
	t_vec3	right;
	t_vec3	up;
	t_vec3	lower_left;
}					t_camera;

typedef struct		s_light
{
	int		id;
	t_vec3	cor;
	float	ratio;
	t_vec3	col;
	int		error;
}					t_light;

typedef struct		s_sphere
{
	int		id;
	t_vec3	cor;
	float	d;
	t_vec3	col;
	int		error;
}					t_sphere;

typedef struct		s_plane
{
	int		id;
	t_vec3	cor;
	t_vec3	nor;
	t_vec3	col;
	int		error;
}					t_plane;
typedef struct		s_square
{
	int		id;
	t_vec3	cor;
	t_vec3	nor;
	float	s;
	t_vec3	col;
	int		error;
}					t_square;
typedef struct		s_cylinder
{
	int		id;
	t_vec3	cor;
	t_vec3	nor;
	float	d;
	float	h;
	t_vec3	col;
	int		error;
}					t_cylinder;
typedef struct		s_triangle
{
	int		id;
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;
	t_vec3	col;
	int		error;
}					t_triangle;

typedef union		u_objs
{
	int			id;
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
	int			ele;
}					t_objs_uv;

typedef struct		s_mv_rt
{
	int		id;
	t_vec3	mv;
	t_vec3	rt;
	int		error;
}					t_mv_rt_s;

typedef struct		s_mv
{
	int x;
	int id;
	int axe;
}					t_mv;

typedef struct		s_rot
{
	int x;
	int id;
	int axe;
}					t_rot;

typedef struct		s_lig
{
	int x;
	int id;
	int axe;
}					t_lig;

typedef struct		s_objs_mv_rt
{
	int		obj;
	t_mv	mv;
	t_rot	rot;
	t_lig	lig;
	int		dir;
	int		size;
}					t_objs_mv_rt;

t_objs_mv_rt g_edit;
t_res		g_res_v;
t_amb		g_amb_v;
t_camera	g_camera_v;
t_light		g_light_v;
t_sphere	g_sphere_v;
t_plane		g_plane_v;
t_square	g_square_v;
t_cylinder	g_cylinder_v;
t_triangle	g_triangle_v;
t_img		g_img_v;
t_objs_uv	*g_objs;
t_camera	*g_cs;
t_light		*g_ls;
t_mv_rt_s	g_mv;
int			g_start;
int			g_obj_num;
int			g_cam_num;
int			g_lig_num;
int			g_pt_cam;
int			g_error;
int			g_shadow_acne;
int			g_mv_app;
int			g_last[2];
t_vec3		g_pcy[6];
#endif
