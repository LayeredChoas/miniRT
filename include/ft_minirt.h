/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:19:50 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/22 16:22:06 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H
# include "ft_struct.h"
# include "ft_math.h"

int			file_h(char **av);
int			ft_isanum(char c);
int			ft_cor_fill(t_vec3 *v, char *str);
int			ft_range(t_vec3 v, int a, int b);
int			ft_col_fill(t_vec3 *v, char *str);
int			ft_col_check(t_vec3 v);
int			fail_check(void);
t_vec3		color(t_ray r);
void		ft_res(char *str);
void		ft_amb(char *str);
void		ft_cylinder(char *str);
void		ft_camera(char *str);
void		ft_light(char *str);
void		ft_plane(char *str);
void		ft_triangle(char *str);
void		ft_square(char *str);
void		ft_sphere(char *str);
int			ft_strlen(char *str);
int			ft_float_skip(char *str);
int			ft_skip_space(char *str);
void		ft_mv(char *str);
void		ft_rt(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_putstr(char *str);
void		add_to_objs(int x);
int			exist_objs(void);
void		rest_objs_all(void);
void		rest_sp(void);
void		rest_pl(void);
void		rest_sq(void);
void		rest_cy(void);
void		rest_tr(void);
void		rest_ca(void);
void		add_to_ca(int x);
int			exist_ca(void);
void		add_to_li(int x);
void		add_to_li(int x);
void		rest_li(void);
int			exist_li(void);
void		init_vars(void);
void		init_img(void);
void		ft_mv_app(void);
t_vec3		objs_normal(t_objs_uv ob, t_vec3 p);
void		ft_putnbr(int nbr, int fd);
t_vec3		col_pix(int i, float t, float *t_old, t_ray r);
t_vec3		obj_col(t_objs_uv ob);
t_vec3		ft_col_prot_1(t_vec3 v1);
int			ft_shadow(float t, t_ray r, t_light li);
t_ray		camera_f(t_camera cam, float x, float y);
int			ft_create_img(int cam);
void		save_img(int cam);
void		add_sp(void);
void		add_tr(void);
void		add_cy(void);
void		add_sq(void);
void		add_pl(void);
t_objs_uv	*copy_objs(void);
float		hit_sphere(t_sphere sp, t_ray ray);
float		hit_plane(t_plane p, t_ray r);
float		hit_square(t_square s, t_ray r);
float		hit_cylinder(t_cylinder c, t_ray r);
float		hit_triangle(t_triangle tr, t_ray ray);
t_vec3		normal_plane(t_plane pl, t_vec3 p);
t_vec3		normal_sphere(t_sphere c, t_vec3 p);
t_vec3		normal_triangle(t_triangle tr, t_vec3 p);
t_vec3		normal_cy(t_cylinder c, t_vec3 p);
t_vec3		normal_sq(t_square sq, t_vec3 p);
int			return_fun(void);
int			free_fun(void);
int			ft_close(void);
int			key_pressed(int keycode, void *param);
float		power(float num, int n);
void        ft_print_sphere(t_sphere sp);
void        ft_print_triangle(t_triangle tr);
void        ft_print_cylinder(t_cylinder cl);
void        ft_print_square(t_square sq);
void        ft_print_plane(t_plane pl);
#endif
