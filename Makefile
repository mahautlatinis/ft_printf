NAME = libftprintf.a

LIBFT_PROJECT = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_PROJECT}/libft.a

SRCS =	./ft_printf.c \
		./utils/checks.c \
		./utils/print.c \
		./utils/initialize.c \
		./types/type_s.c \
		./types/type_id.c \
		./types/type_u.c \
		./types/type_x.c \
		./types/type_p.c

OBJS = ${SRCS:.c=.o}

RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I${LIBFT_PROJECT}

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS) ${LIBFT_PROJECT}
			ar -rcs ${NAME} $(OBJS)

${LIBFT_PROJECT}:
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} all
			cp ${LIBFT_PATH} ${NAME}

clean:
			${RM} ${OBJS}
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} clean

fclean: clean
			${RM} ${NAME}
			make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} fclean

re: fclean all

.PHONY:		bonus all clean fclean re ${LIBFT_PROJECT}
