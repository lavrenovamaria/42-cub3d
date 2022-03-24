/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:33:38 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:59:47 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int	num_size(int num)
{
	int	size;

	size = 1;
	while (num / 10 != 0)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

void	fl_n_ceil_col(int *color, char *one_line)
{
	int	j;

	j = 0;
	while (one_line[j] < 48 || one_line[j] > 57)
		j++;
	color[0] = ft_atoi(&one_line[j]);
	j += num_size(color[0]);
	color[1] = ft_atoi(&one_line[j]);
	j += num_size(color[1]);
	color[2] = ft_atoi(&one_line[j]);
}

int	map_fill(t_data *data, char *one_line, int i)
{
	if (check_gnl(data, one_line) == 7)
		return (1);
	if (i == NORTH)
		data->p_no = ft_strtrim(one_line, "\t NO");
	else if (i == SOUTH)
		data->p_so = ft_strtrim(one_line, "\t SO");
	else if (i == WEST)
		data->p_we = ft_strtrim(one_line, "\t WE");
	else if (i == EAST)
		data->p_ea = ft_strtrim(one_line, "\t EA");
	else if (i == FLOOR_COLOR)
		fl_n_ceil_col(data->col_f, one_line);
	else if (i == CEILING_COLOR)
		fl_n_ceil_col(data->col_c, one_line);
	return (0);
}
