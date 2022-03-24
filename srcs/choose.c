/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:25:06 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:25:07 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int	for_y(t_data *data)
{
	int	color;

	if (data->dir_y <= 1 && data->dir_y > 0.5)
		color = 0;
	else if (data->dir_y >= -1 && data->dir_y < -0.5)
		color = 1;
	if ((data->dir_x <= 1 && data->dir_x >= -1) \
		&& data->map_y < data->posy)
		color = 1;
	else if ((data->dir_x <= 1 && data->dir_x >= -1) \
		&& data->map_y >= data->posy)
		color = 0;
	return (color);
}

int	for_x(t_data *data)
{
	int	color;

	if (data->dir_x <= 1 && data->dir_x > 0.5)
		color = 2;
	else if (data->dir_x >= -1 && data->dir_x < -0.5)
		color = 3;
	if ((data->dir_y <= 1 && data->dir_y >= -1) \
		&& data->map_x < data->posx)
		color = 3;
	else if ((data->dir_y <= 1 && data->dir_y >= -1) \
		&& data->map_x >= data->posx)
		color = 2;
	return (color);
}

void	tex_put(t_data *data, double tex_pos, double step, int tex_x)
{
	int	tex;
	int	tex_y;
	int	y;
	int	color;

	if (data->side == 1)
		tex = for_y(data);
	else if (data->side == 0)
		tex = for_x(data);
	y = data->draw_start;
	while (y < data->draw_end)
	{
		tex_y = (int)tex_pos & (T_H - 1);
		tex_pos += step;
		color = data->textures[tex][T_H * tex_y + tex_x];
		my_mlx_pixel_put(&data->frame, data->pix_x, y, color);
		y++;
	}
}

void	choose_pixel(t_data *data)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;

	if (data->side == 0)
		wall_x = data->posy + data->perp_wall_dist * data->ray_dir_y;
	else
		wall_x = data->posx + data->perp_wall_dist * data->ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)(wall_x * (double)T_W);
	if (data->side == 0 && data->ray_dir_x > 0)
		tex_x = T_W - tex_x - 1;
	if (data->side == 1 && data->ray_dir_x < 0)
		tex_x = T_W + tex_x - 1;
	step = 1.0 * T_H / data->line_height;
	tex_pos = (data->draw_start - H / 2 + data->line_height / 2) * step;
	tex_put(data, tex_pos, step, tex_x);
}

void	print_back(t_data *addr, t_frame *img)
{
	addr->pix_y = 0;
	addr->pix_x = 0;
	while (addr->pix_y < H)
	{
		while (addr->pix_x < W)
		{
			if (addr->pix_y < H / 2)
				my_mlx_pixel_put(img, addr->pix_x, addr->pix_y, \
					colorize(addr, 1));
			else
				my_mlx_pixel_put(img, addr->pix_x, addr->pix_y, \
					colorize(addr, 2));
			addr->pix_x++;
		}
		addr->pix_x = 0;
		addr->pix_y++;
	}
}
