/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:29:26 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:30:38 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int	main_loop(t_data *data)
{
	print_back(data, &data->frame);
	key_update(data);
	data->pix_x = 0;
	while (data->pix_x < W)
	{
		calc_step_and_dist(data);
		sam_dda_algos(data);
		data->pix_x++;
	}
	mlx_put_image_to_window(data->vars.mlx, \
		data->vars.win, data->frame.img, 0, 0);
	return (0);
}

t_vars	mlx_in(void)
{
	t_vars	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, W, H, "cub3d yay");
	return (mlx);
}

t_frame	img_in(t_vars mlx)
{
	t_frame	img;

	img.img = mlx_new_image(mlx.mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	return (img);
}

int	**mall(t_data *data)
{
	int	i;

	i = 0;
	data->textures = (int **)malloc(sizeof(int *) * 4);
	if (!data->textures)
	{
		ft_putstr_fd("Error\nmalloc error\n", 2);
		exit (1);
	}
	while (i < 4)
	{
		data->textures[i] = (int *)malloc(sizeof(int) * (T_W * T_H));
		if (!data->textures[i])
		{
			ft_putstr_fd("Error\nmalloc error\n", 2);
			exit (1);
		}
		i++;
	}
	return (data->textures);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("Error\nWrong number of arguments");
		return (1);
	}
	if (parser(&data, av[1]))
		printf("yes");
	data.vars = mlx_in();
	data.frame = img_in(data.vars);
	print_back(&data, &data.frame);
	data.textures = mall(&data);
	load_textures(&data);
	data.pix_x = 0;
	data.pix_y = 0;
	main_loop(&data);
	mlx_hook(data.vars.win, PRESS, 0, &key_press, &data);
	mlx_hook(data.vars.win, RELEASE, 0, &key_release, &data);
	mlx_hook(data.vars.win, 17, 0L, close_window, &data.vars);
	mlx_loop_hook(data.vars.mlx, &main_loop, &data);
	mlx_loop(data.vars.mlx);
	return (0);
}
