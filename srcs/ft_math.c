/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:35:00 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/22 17:27:28 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

float	rad(float alpha)
{
	float x;

	x = alpha / (180.0 * M_PI);
	return (x);
}

float	ft_max(float x, float y)
{
	if (x > y)
		return (x);
	if (y > x)
		return (y);
	return (x);
}

float	v_mult_max(t_vec3 v1, t_vec3 v2)
{
	float n;

	n = v_mult(v1, v2);
	if (n > 0.0)
		return (n);
	return (0);
}

float	power(float num, int n)
{
	float x;

	x = num;
	while (n > 1)
	{
		x = x * num;
		n--;
	}
	return (x);
}

void	ft_putnbr(int nbr, int fd)
{
	char tmp;

	if (nbr < 0)
		{
			write(fd, "-", 1);
			ft_putnbr(-1 * nbr, fd);
			return ;
		}
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (nbr >= 1 && nbr <= 9)
	{
		tmp = nbr + '0';
		write(fd, &tmp, 1);
	}
	else
	{
		ft_putnbr(nbr / 10, fd);
		ft_putnbr(nbr % 10, fd);
	}
}
