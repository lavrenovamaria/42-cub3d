/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:25:40 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:28:07 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int	key_press(int key, t_data *data)
{
	if (key == ESC)
		exit(0);
	else if (key == ST_FWD)
		data->k.key_step_fwd = 1;
	else if (key == ST_BCWD)
		data->k.key_step_bcwd = 1;
	else if (key == LOOK_LEFT)
		data->k.key_look_left = 1;
	else if (key == LOOK_RIGHT)
		data->k.key_look_right = 1;
	else if (key == ST_R)
		data->k.key_step_right = 1;
	else if (key == ST_L)
		data->k.key_step_left = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == ESC)
		exit(0);
	else if (key == ST_FWD)
		data->k.key_step_fwd = 0;
	else if (key == LOOK_LEFT)
		data->k.key_look_left = 0;
	else if (key == ST_BCWD)
		data->k.key_step_bcwd = 0;
	else if (key == LOOK_RIGHT)
		data->k.key_look_right = 0;
	else if (key == ST_R)
		data->k.key_step_right = 0;
	else if (key == ST_L)
		data->k.key_step_left = 0;
	return (0);
}

void	player_step_left(t_data *data)
{
	if (data->map.map[(int)(data->posy)][(int)(data->posx - data->plane_x * \
			data->move_speed)] == '0')
		data->posx -= data->plane_x * data->move_speed;
	if (data->map.map[(int)(data->posy - \
			data->plane_y * data->move_speed)][(int)(data->posx)] == '0')
		data->posy -= data->plane_y * data->move_speed;
}

void	player_step_right(t_data *data)
{
	if (data->map.map[(int)(data->posy)][(int)(data->posx + data->plane_x * \
			data->move_speed)] == '0')
		data->posx += data->plane_x * data->move_speed;
	if (data->map.map[(int)(data->posy + \
			data->plane_y * data->move_speed)][(int)(data->posx)] == '0')
		data->posy += data->plane_y * data->move_speed;
}

void	player_move_fwd(t_data *data)
{
	float	x1;
	float	y1;

	x1 = data->posx + data->dir_x * data->move_speed;
	y1 = data->posy + data->dir_y * data->move_speed;
	if (data->map.map[(int)(data->posy)][(int)(data->posx + data->dir_x * \
			data->move_speed)] == '0')
		data->posx += data->dir_x * data->move_speed;
	if (data->map.map[(int)(data->posy + \
			data->dir_y * data->move_speed)][(int)(data->posx)] == '0')
		data->posy += data->dir_y * data->move_speed;
}
