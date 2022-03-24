/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:27:32 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:27:42 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	player_move_bcwd(t_data *data)
{
	if (data->map.map[(int)(data->posy)][(int)(data->posx - data->dir_x * \
			data->move_speed)] == '0')
		data->posx -= data->dir_x * data->move_speed;
	if (data->map.map[(int)(data->posy - \
			data->dir_y * data->move_speed)][(int)(data->posx)] == '0')
		data->posy -= data->dir_y * data->move_speed;
}

void	key_update(t_data *data)
{
	if (data->k.key_step_fwd)
		player_move_fwd(data);
	if (data->k.key_step_bcwd)
		player_move_bcwd(data);
	if (data->k.key_look_right)
		player_look_right(data);
	if (data->k.key_look_left)
		player_look_left(data);
	if (data->k.key_step_right)
		player_step_right(data);
	if (data->k.key_step_left)
		player_step_left(data);
	if (data->k.key_esc)
		exit(0);
}
