/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_li_ca.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:10:16 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/19 15:25:14 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

t_light		*copy_light(void)
{
	int		i;
	t_light	*new;

	i = 0;
	if (!(new = malloc(sizeof(t_light) * (g_lig_num + 1))))
	{
		g_error = 101;
		return (NULL);
	}
	while (i < g_lig_num)
	{
		new[i] = g_ls[i];
		i++;
	}
	return (new);
}

void		add_to_li(int x)
{
	t_light*temp;

	if (x)
	{
		temp = g_ls;
		if (!(g_ls = copy_light()))
			return ;
		g_ls[g_lig_num] = g_light_v;
		free(temp);
		g_mv_app = 3;
		g_last[0] = 3;
		g_last[1] = g_lig_num;
		g_lig_num++;
	}
}

t_camera	*copy_cam(void)
{
	int			i;
	t_camera	*new;

	i = 0;
	if (!(new = malloc(sizeof(t_camera) * (g_cam_num + 1))))
	{
		g_error = 101;
		return (NULL);
	}
	while (i < g_cam_num)
	{
		new[i] = g_cs[i];
		i++;
	}
	return (new);
}

void		add_to_ca(int x)
{
	t_camera *temp;

	if (x)
	{
		temp = g_cs;
		if (!(g_cs = copy_cam()))
			return ;
		g_cs[g_cam_num] = g_camera_v;
		free(temp);
		g_mv_app = 1;
		g_last[0] = 1;
		g_last[1] = g_cam_num;
		g_cam_num++;
	}
}
