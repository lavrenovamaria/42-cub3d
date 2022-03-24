/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:25:21 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:58:31 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	my_mlx_pixel_put(t_frame *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_vars *vars)
{
	write(1, "Exit\n", 5);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	keyboard_hook(t_vars *vars)
{
	close_window(vars);
	return (0);
}

int	colorize(t_data *data, int i)
{
	if (i == 1)
	{
		data->c_color = data->col_c[0] << 16;
		data->c_color |= data->col_c[1] << 8;
		data->c_color |= data->col_c[2];
		return (data->c_color);
	}
	else if (i == 2)
	{
		data->f_color = data->col_f[0] << 16;
		data->f_color |= data->col_f[1] << 8;
		data->f_color |= data->col_f[2];
		return (data->f_color);
	}
	return (0);
}
