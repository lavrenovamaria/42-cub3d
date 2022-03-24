/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:28:27 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:28:28 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	player_look_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->rot_speed) - \
		data->dir_y * sin(-data->rot_speed);
	data->dir_y = old_dir_x * sin(-data->rot_speed) + \
		data->dir_y * cos(-data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-data->rot_speed) - \
		data->plane_y * sin(-data->rot_speed);
	data->plane_y = old_plane_x * sin(-data->rot_speed) + \
		data->plane_y * cos(-data->rot_speed);
}

void	player_look_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(data->rot_speed) - \
		data->dir_y * sin(data->rot_speed);
	data->dir_y = old_dir_x * sin(data->rot_speed) + \
		data->dir_y * cos(data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(data->rot_speed) - \
		data->plane_y * sin(data->rot_speed);
	data->plane_y = old_plane_x * sin(data->rot_speed) + \
		data->plane_y * cos(data->rot_speed);
}
