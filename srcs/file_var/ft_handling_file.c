/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:27:16 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/16 12:24:31 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_minirt.h"

int		check(char c)
{
	if (c == 'R' || c == 'A' || c == 'c' || c == 'l'
	|| c == 'p' || c == 's' || c == 't' || c == 'm' || c == 'r')
		return (1);
	return (0);
}

void	ft_div(char *str)
{
	if (str[0] == 'R')
		ft_res(str);
	if (str[0] == 'A')
		ft_amb(str);
	if (str[0] == 'c' && str[1] == 'y')
		ft_cylinder(str);
	if (str[0] == 'c' && str[1] == ' ')
		ft_camera(str);
	if (str[0] == 'l' && str[1] == ' ')
		ft_light(str);
	if (str[0] == 'p' && str[1] == 'l')
		ft_plane(str);
	if (str[0] == 't' && str[1] == 'r')
		ft_triangle(str);
	if (str[0] == 's' && str[1] == 'p')
		ft_sphere(str);
	if (str[0] == 's' && str[1] == 'q')
		ft_square(str);
	if (str[0] == 'm' && str[1] == 'v')
		ft_mv(str);
	if (str[0] == 'r' && str[1] == 't')
		ft_rt(str);
}

void	rest_all(void)
{
	rest_sq();
	rest_cy();
	rest_pl();
	rest_sp();
	rest_tr();
	rest_li();
	rest_ca();
}

int		file_data_ex(char *tab)
{
	int i;
	int x;

	i = 0;
	x = 0;
	g_mv.id = 0;
	while (tab[i] == ' ')
		i++;
	if (check(tab[i]))
		ft_div(&tab[i]);
	if ((x = fail_check()))
		return (x);
	if (g_mv.id != 0)
		ft_mv_app();
	add_to_ca(exist_ca());
	add_to_objs(exist_objs());
	add_to_li(exist_li());
	rest_all();
	return (0);
}

int		file_h(char **av)
{
	int		fd;
	char	*str;
	int		ret;

	if ((fd = open(av[1], O_RDONLY)) <= 0)
	{
		g_error = 15;
		return (0);
	}
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (str[0] != '\0' && str[0] != '#')
			file_data_ex(str);
		free(str);
		if (ret == 0)
			break ;
	}
	if (ret < 0)
		g_error = 1;
	(g_res_v.id == 0) ? g_error = 17 : 1;
	(g_amb_v.id == 0) ? g_error = 18 : 1;
	(g_cam_num == 0) ? g_error = 19 : 1;
	free(str);
	return (0);
}
