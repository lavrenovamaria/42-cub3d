NAME 	= cub3D

LIBFT	= ../libft/libft.a
LFT_DIR = ../libft

HEADER  = printing.h

SRCS = 	parser.c \
		main.c \
		key.c \
		key2.c \
		choose.c \
		parser_utils.c \
		look_around.c \
		func_for_mlx.c \
		map_check.c \
		map_fill.c \
		map_check2.c \
		some_calcs.c \
		tex_load.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

CC = gcc $(GCC_FLAG)
GCC_FLAG = -Wall -Werror -Wextra -g -I ./ -I ../

OBJS = $(SRCS:.c=.o)

RM	= rm -rf

all: libft minilibx $(NAME)

libft:
	make -C ${LFT_DIR}

minilibx:
	make -C minilibx/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Lminilibx/ -lmlx -framework OPENGL -framework Appkit -L../libft -lft

clean:
	rm -f $(OBJS)
	make -C ../libft/ clean
	make -C minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C ../libft/ fclean
	make -C minilibx/ clean

re: fclean all

.PHONY: libft minilibx
