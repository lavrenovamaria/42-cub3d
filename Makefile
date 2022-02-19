SRCS = ./srcs/parser.c \
	   ./srcs/gnl/get_next_line.c \
	   ./srcs/gnl/get_next_line_utils.c \

NAME = Cub3D
GCC_FLAG = -Wall -Werror -Wextra -g
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

bonus: libft minilibx $(NAME_BONUS)

libft:
	make -C libft/

minilibx:
	make -C srcs/minilibx/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Lsrcs/minilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft

clean:
	rm -f $(OBJS)
	make -Clibft/ clean
	make -C srcs/minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C srcs/minilibx/ clean

re: fclean all

.PHONY: libft minilibx
