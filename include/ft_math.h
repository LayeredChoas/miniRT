/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:11:11 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:33:10 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H
# include "ft_struct.h"

int		ft_atoi(char *str);
float	ft_atoi_float(char *str);
float	rad(float alpha);
t_vec3	v_create(float x, float y, float z);
t_vec3	v_add(t_vec3 v1, t_vec3 v2);
float	v_mult(t_vec3 v1, t_vec3 v2);
t_vec3	v_sub(t_vec3 v1, t_vec3 v2);
float	vec_length(t_vec3 v);
t_vec3	v_div(t_vec3 v1, t_vec3 v2);
t_vec3	v_unit(t_vec3 v);
t_vec3	v_num_mult(float x, t_vec3 v);
t_vec3	v_mult_cof(t_vec3 v1, t_vec3 v2);
t_vec3	v_num_div(float x, t_vec3 v);
t_vec3	v_cross(t_vec3 v1, t_vec3 v2);
t_ray	ray_create(t_vec3 v1, t_vec3 v2);
t_vec3	pt_at_parameter(float t, t_ray r);
int		ft_num_color(int r, int g, int b);
float	ft_max(float x, float y);
float	v_mult_max(t_vec3 v1, t_vec3 v2);
#endif
