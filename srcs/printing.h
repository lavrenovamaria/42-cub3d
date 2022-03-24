/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:54:35 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:57:48 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H

# define W 640
# define H 480
# define T_W 64
# define T_H 64

# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define FLOOR_COLOR 5
# define CEILING_COLOR 6
# define ESC 53
# define LOOK_LEFT 123
# define LOOK_RIGHT 124
# define ST_BCWD 1
# define ST_FWD 13
# define ST_L 0
# define ST_R 2
# define PRESS 2
# define RELEASE 3
# define TXTR_W 64
# define TXTR_H 64

# define KEY_PRESS				2
# define KEY_ESC				53
# define MASK_KEY_PRESS			1L

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_map
{
	int		*rows;
	int		cols;
	char	**map;
	int		**m_mask;
	char	*info_map[6];
	int		info_check[6];

}				t_map;

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		*data;
	int		bpp;
	int		ll;
	int		endian;
}				t_frame;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_keys
{
	int		key_look_left;
	int		key_step_fwd;
	int		key_step_bcwd;
	int		key_look_right;
	int		key_step_right;
	int		key_step_left;
	int		key_esc;
}				t_keys;

typedef struct s_data
{
	int		fd;
	char	*line;
	double	pix_x;
	double	pix_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	posx;
	double	posy;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		draw_start;
	int		draw_end;
	int		line_height;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	t_map	map;
	t_keys	k;
	t_frame	frame;
	t_vars	vars;
	int		**textures;
	int		screen_buf[H][W];
	int		width;
	int		height;
	double	move_speed;
	double	rot_speed;
	char	*p_no;
	char	*p_so;
	char	*p_we;
	char	*p_ea;
	int		col_f[3];
	int		col_c[3];
	int		f_color;
	int		c_color;
	int		i_w;
	int		i_h;
}				t_data;

void	*parser(t_data *data, char *filename);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
void	key_update(t_data *data);
void	load_textures(t_data *data);
void	my_mlx_pixel_put(t_frame *img, int x, int y, int color);
int		for_y(t_data *data);
int		for_x(t_data *data);
void	tex_put(t_data *data, double tex_pos, double step, int tex_x);
void	choose_pixel(t_data *data);
void	print_back(t_data *addr, t_frame *img);
int		close_window(t_vars *vars);
int		keyboard_hook(t_vars *vars);
int		colorize(t_data *data, int i);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
void	player_step_left(t_data *data);
void	player_step_right(t_data *data);
void	player_move_fwd(t_data *data);
void	player_move_bcwd(t_data *data);
void	player_look_right(t_data *data);
void	player_look_left(t_data *data);
void	key_update(t_data *data);
void	player_look_right(t_data *data);
void	player_look_left(t_data *data);
int		closed_map(t_data *data, int i, int j);
void	spaces2end(t_data *data, int i);
void	tab2space(t_data *data);
int		sides_check(t_data *data, int i, int j, char *tmp_map);
int		map_check(t_data *data);
int		sides_check2(t_data *data, int i, int j);
void	data_fill(t_data **data, int i, int j);
void	data_fill2(t_data **data, int i, int j);
int		symb_check(t_data *data, int i, int j);
int		num_size(int num);
void	fl_n_ceil_col(int *color, char *one_line);
int		map_fill(t_data *data, char *one_line, int i);
void	calc_size_of_wall_x(t_data *data);
void	calc_size_len(t_data *data);
void	sam_dda_algos(t_data *data);
void	some_calcs(t_data **data);
void	calc_step_and_dist(t_data *data);
int		int_union(int tex, char *addr, int x);
void	load_image(t_data *data, int *texture, char *p);
void	load_textures(t_data *data);
int		check_gnl(t_data *data, char *one_line);
void	error_exit(char *msg);
void	*v_malloc(size_t size);
int		overlap_error(t_data *data, int type);
int		ft_strcmp(char *s1, char *s2);
int		check_gnl(t_data *data, char *one_line);

#endif
