/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:24:54 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 19:01:46 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int	int_union(int tex, char *addr, int x)
{
	tex = (int)addr[x + 2] << 16;
	tex |= (int)addr[x + 1] << 8;
	tex |= (int)addr[x];
	return (tex);
}

t_frame	img_ini(t_data *data, char *p)
{
	t_frame	img;

	img.img = mlx_xpm_file_to_image(data->vars.mlx, p, &data->i_w, &data->i_h);
	if (img.img == NULL)
	{
		printf("Error\nCan't find path to texture\n");
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	return (img);
}

void	load_image(t_data *data, int *texture, char *p)
{
	int		x;
	int		y;
	int		z;
	t_frame	img;

	img = img_ini(data, p);
	y = 0;
	x = 0;
	while (y < T_H)
	{
		z = 0;
		while (z < T_W)
		{
			texture[T_H * y + z] = int_union(texture[T_H * y + z], img.addr, x);
			if (texture[T_H * y + z] < 0)
			{
				texture[T_H * y + z] = texture[T_H * y + z] & 0xcc << 16;
				texture[T_H * y + z] = texture[T_H * y + z] | 0x77 << 8;
			}
			x += 4;
			z++;
		}
		y++;
	}
}

void	load_textures(t_data *data)
{
	load_image(data, data->textures[0], data->p_no);
	load_image(data, data->textures[1], data->p_so);
	load_image(data, data->textures[2], data->p_ea);
	load_image(data, data->textures[3], data->p_we);
}
