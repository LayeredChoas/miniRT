/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_ops1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:13:34 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_vec3	v_div(t_vec3 v1, t_vec3 v2)
{
	t_vec3 v;

	v.x = v1.x / v2.x;
	v.y = v1.y / v2.y;
	v.z = v1.z / v2.z;
	return (v);
}

t_vec3	v_unit(t_vec3 v)
{
	t_vec3	u;
	float	x;

	x = 1 / (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	u.x = v.x * x;
	u.y = v.y * x;
	u.z = v.z * x;
	return (u);
}

t_vec3	v_num_mult(float x, t_vec3 v)
{
	t_vec3 u;

	u.x = v.x * x;
	u.y = v.y * x;
	u.z = v.z * x;
	return (u);
}

t_vec3	v_num_div(float x, t_vec3 v)
{
	t_vec3 u;

	u.x = v.x / x;
	u.y = v.y / x;
	u.z = v.z / x;
	return (u);
}

t_vec3	v_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3 v;

	v.x = (v1.y * v2.z) - (v1.z * v2.y);
	v.y = -(v1.x * v2.z) + v1.z * v2.x;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}
