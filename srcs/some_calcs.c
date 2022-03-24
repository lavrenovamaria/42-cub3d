/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_calcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:01:28 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 19:01:29 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	calc_size_of_wall_x(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->line_height = (int)(H / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + H / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + H / 2;
	if (data->draw_end >= H)
		data->draw_end = H - 1;
}

void	calc_size_len(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->line_height = (int)(H / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + H / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + H / 2;
	if (data->draw_end >= H)
		data->draw_end = H - 1;
	choose_pixel(data);
	data->hit = 0;
}

void	sam_dda_algos(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map.map[data->map_y][data->map_x] == '1')
			data->hit = 1;
	}
	calc_size_len(data);
}

void	some_calcs(t_data **data)
{
	double	camera_x;

	camera_x = 2 * (*data)->pix_x / (double)W - 1;
	(*data)->ray_dir_x = (*data)->dir_x + (*data)->plane_x * camera_x;
	(*data)->ray_dir_y = (*data)->dir_y + (*data)->plane_y * camera_x;
	(*data)->map_y = (int)(*data)->posy;
	(*data)->map_x = (int)(*data)->posx;
	(*data)->delta_dist_x = fabs(1 / (*data)->ray_dir_x);
	(*data)->delta_dist_y = fabs(1 / (*data)->ray_dir_y);
}

void	calc_step_and_dist(t_data *data)
{
	some_calcs(&data);
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->posx - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + \
			1.0 - data->posx) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->posy - \
			data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + \
			1.0 - data->posy) * data->delta_dist_y;
	}
}
