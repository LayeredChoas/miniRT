/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objs_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:32:03 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_vec3	objs_normal(t_objs_uv ob, t_vec3 p)
{
	t_vec3 normal;

	normal = BLACK;
	if (ob.id == 1)
		normal = normal_sphere(ob.sp, p);
	if (ob.id == 2)
		normal = normal_plane(ob.pl, p);
	if (ob.id == 3)
		normal = normal_sq(ob.sq, p);
	if (ob.id == 4)
		normal = normal_cy(ob.cy, p);
	if (ob.id == 5)
		normal = normal_triangle(ob.tr, p);
	return (normal);
}
