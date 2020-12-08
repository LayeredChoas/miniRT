/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:25:33 by ayennoui          #+#    #+#             */
/*   Updated: 2020/02/19 16:06:34 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minirt.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	*lim;

	str = b;
	lim = b + len;
	while (str != lim)
		*(str++) = (unsigned char)c;
	return (b);
}

int		img_header(unsigned int nx, unsigned int ny)
{
	int				fd;
	unsigned char	header[54];
	int				pixels_row;
	int				pixels_pad;

	ft_memset(header, 0, 54);
	pixels_row = nx * 4;
	pixels_pad = (4 - (pixels_row % 4)) % 4;
	header[0] = 'B';
	header[1] = 'M';
	header[2] = 54 + (pixels_row + pixels_pad) * ny;
	header[10] = 54;
	header[14] = 40;
	*(unsigned int *)&header[18] = nx;
	*(unsigned int *)&header[22] = ny;
	header[26] = 1;
	header[28] = 24;
	fd = open("image.bmp", O_RDWR | O_CREAT | O_TRUNC);
	write(fd, header, 54);
	return (fd);
}

int		ft_data(float i, t_camera c, int fd)
{
	int				j;
	int				k;
	unsigned char	*data;
	t_vec3			col;

	j = 0;
	k = 0;
	if (!(data = malloc(g_res_v.x * 3)))
	{
		g_error = 101;
		return (0);
	}
	while (j < g_res_v.x)
	{
		col = color(camera_f(c, j / g_res_v.x, (g_res_v.y - i) / g_res_v.y));
		data[k] = ((int)(col.z * 255));
		data[k + 1] = ((int)(col.y * 255));
		data[k + 2] = ((int)(col.x * 255));
		k += 3;
		j++;
	}
	write(fd, data, g_res_v.x * 3);
	free(data);
	return (1);
}

void	save_img(int cam)
{
	float	i;
	int		x;
	int		fd;

	fd = img_header(g_res_v.x, g_res_v.y);
	i = 0;
	while (i < g_res_v.y)
	{
		x = ft_data(i, g_cs[cam], fd);
		if (x == 0)
		{
			close(fd);
			return ;
		}
		i++;
	}
	close(fd);
}
