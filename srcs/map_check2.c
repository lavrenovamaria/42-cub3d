/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:32:56 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:33:04 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int	sides_check2(t_data *data, int i, int j)
{
	while (data->map.map[i - 1][j] != '\0')
	{
		while (data->map.map[i - 1][j] == ' ')
			j++;
		if (data->map.map[i - 1][j] == '\n')
			break ;
		if (data->map.map[i - 1][j] != '1')
		{
			printf("Error\nwrong map\n");
			return (1);
		}
		j++;
	}
	return (0);
}

void	data_fill(t_data **data, int i, int j)
{
	if ((*data)->map.map[i][j] == 'N')
	{
		(*data)->map.map[i][j] = '0';
		(*data)->posx = j + 0.5;
		(*data)->posy = i + 0.5;
		(*data)->dir_x = 0;
		(*data)->dir_y = -1;
		(*data)->plane_x = -0.66;
		(*data)->plane_y = 0;
		(*data)->move_speed = 0.04;
		(*data)->rot_speed = 0.04;
	}
	if ((*data)->map.map[i][j] == 'S')
	{
		(*data)->map.map[i][j] = '0';
		(*data)->posx = j + 0.5;
		(*data)->posy = i + 0.5;
		(*data)->dir_x = 0;
		(*data)->dir_y = 1;
		(*data)->plane_x = 0.66;
		(*data)->plane_y = 0;
		(*data)->move_speed = 0.04;
		(*data)->rot_speed = 0.04;
	}
}

void	data_fill2(t_data **data, int i, int j)
{
	if ((*data)->map.map[i][j] == 'W')
	{
		(*data)->map.map[i][j] = '0';
		(*data)->posx = j + 0.5;
		(*data)->posy = i + 0.5;
		(*data)->dir_x = -1;
		(*data)->dir_y = 0;
		(*data)->plane_x = 0;
		(*data)->plane_y = 0.66;
		(*data)->move_speed = 0.04;
		(*data)->rot_speed = 0.04;
	}
	if ((*data)->map.map[i][j] == 'E')
	{
		(*data)->map.map[i][j] = '0';
		(*data)->posx = j + 0.5;
		(*data)->posy = i + 0.5;
		(*data)->dir_x = 1;
		(*data)->dir_y = 0;
		(*data)->plane_x = 0;
		(*data)->plane_y = -0.66;
		(*data)->move_speed = 0.04;
		(*data)->rot_speed = 0.04;
	}
}

int	symb_check(t_data *data, int i, int j)
{
	while (data->map.map[i] != NULL)
	{
		j = 0;
		while (data->map.map[i][j] == ' ' || data->map.map[i][j] == '\t')
			j++;
		if (data->map.map[i][j] == '\0')
			return (1);
		while (data->map.map[i][j] != '\0')
		{
			if (data->map.map[i][j] != '1' && data->map.map[i][j] != '0'
				&& data->map.map[i][j] != 'N' && data->map.map[i][j] != 'S'
				&& data->map.map[i][j] != 'W' && data->map.map[i][j] != 'E'
				&& data->map.map[i][j] != ' ')
			{
				printf("Error\nwrong symbol in %d string", i + 1);
				return (1);
			}
			data_fill(&data, i, j);
			data_fill2(&data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
