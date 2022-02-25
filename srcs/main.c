#include "printing.h"

void	my_mlx_pixel_put(t_frame *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
				my_mlx_pixel_put(img, addr->pix_x, addr->pix_y, 0x15152b);
			else
				my_mlx_pixel_put(img, addr->pix_x, addr->pix_y, 0x6b0000);
			addr->pix_x++;
		}
		addr->pix_x = 0;
		addr->pix_y++;
	}
}

//void	print_walls(t_data *addr, t_data *img)
//{
//	
//}

int	main(int ac, char **av)
{
	t_frame		img;
	t_vars		mlx;
	t_data		addr;

	t_data data;
	char *file = av[1];

	if(ac != 2)
	{
		printf("Wrong number of arguments");
		return (1);
	}
		
		//exit_failure(&data, "Wrong number of arguments");
	if(parser(&data, file))
		printf("yes");
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, W, H, "test");
	img.img = mlx_new_image(mlx.mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	addr.frame = img;
	addr.vars = mlx;
	//printing(&addr, &img, 0);
	print_back(&addr, &img);
	//print_walls(&addr, &img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	//mlx_key_hook(mlx.win, color_chng, &addr);
	//mlx_mouse_hook(mlx.win, zoomchng, &addr);
	//mlx_hook(mlx.win, 17, 1L << 17, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}