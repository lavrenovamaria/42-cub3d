NAME = test.a

SRCS = main.c parser.c

OBJS = ${SRCS:.c=.o}

HEADER = printing.h

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I . -I ..

$(NAME): ${OBJS} ${HEADER}
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -L mlx -lmlx -framework OpenGL -framework AppKit -o test

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}  test

re: fclean all
