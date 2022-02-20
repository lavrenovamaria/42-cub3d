# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../srcs/gnl/get_next_line.h"

# define	WIDTH				1280
# define	HEIGHT				1024

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define FLOOR_COLOR 4
# define CEILING_COLOR 5

typedef struct	s_map
{
	int			*rows;
	int			cols;
	char		**map;
	char 		**map_mask;
	char 		*info_map[8];
	int			info_check[8];

}				t_map;

typedef struct s_vars {
	void			*mlx;
	void			*win;
}				t_vars;

typedef struct		s_frame {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_frame;

typedef struct	s_data
{
	int				fd;
	char			*line;
	t_map			*map;
	t_vars 			vars;
	t_frame			frame;
	int				width;
	int				height;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	int				F[3];
	int				C[3];
}				t_data;
