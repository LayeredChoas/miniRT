/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_ops2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:28:14 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/15 19:40:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_vec3	unit_vec(t_vec3 v)
{
	return (v_num_div(vec_length(v), v));
}

t_vec3	v_mult_cof(t_vec3 v1, t_vec3 v2)
{
	t_vec3 v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	return (v);
}
