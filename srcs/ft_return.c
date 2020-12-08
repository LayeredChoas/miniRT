/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:38:52 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/18 16:15:35 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int		return_fun(void)
{
	free_fun();
	ft_putstr("Error\n");
	ft_putstr("\033[0;31m");
	(g_error == 1) ? ft_putstr("File data: reading file error\n") : 1;
	(g_error == 2) ? ft_putstr("File data: res error\n") : 1;
	(g_error == 3) ? ft_putstr("File data: amb error\n") : 1;
	(g_error == 4) ? ft_putstr("File data: camera error\n") : 1;
	(g_error == 5) ? ft_putstr("File data: lighterror\n") : 1;
	(g_error == 6) ? ft_putstr("File data: sphere error\n") : 1;
	(g_error == 7) ? ft_putstr("File data: plane error\n") : 1;
	(g_error == 8) ? ft_putstr("File data: square error\n") : 1;
	(g_error == 9) ? ft_putstr("File data: cylinder error\n") : 1;
	(g_error == 10) ? ft_putstr("File data: triangle error\n") : 1;
	(g_error == 12) ? ft_putstr("File data: can't rotate this object\n") : 1;
	(g_error == 13) ? ft_putstr("File data: can't rotate light source\n") : 1;
	(g_error == 14) ? ft_putstr("wrong arg\n") : 1;
	(g_error == 15) ? ft_putstr("file doesn't exist\n") : 1;
	(g_error == 16) ? ft_putstr("wrong file extention\n") : 1;
	(g_error == 17) ? ft_putstr("No resolution\n") : 1;
	(g_error == 18) ? ft_putstr("No amb\n") : 1;
	(g_error == 19) ? ft_putstr("No Camera\n") : 1;
	(g_error == 20) ? ft_putstr("rotation/translation error\n") : 1;
	(g_error == 101) ? ft_putstr("malloc error\n") : 1;
	ft_putstr("\033[0m");
	return (0);
}
