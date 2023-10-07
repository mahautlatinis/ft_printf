# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 17:50:14 by mahautlatin       #+#    #+#              #
#    Updated: 2023/10/07 17:50:42 by mahautlatin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libftprintf.a

LIBFT_PROJECT	= ./project/libft
LIBFT_MAKE		= Makefile
LIBFT_PATH 		= ${LIBFT_PROJECT}/libft.a

SRCS =			./project/ft_printf.c \
				./project/utils/checks.c \
				./project/utils/print.c \
				./project/utils/initialize.c \
				./project/types/type_s.c \
				./project/types/type_id.c \
				./project/types/type_u.c \
				./project/types/type_x.c \
				./project/types/type_p.c

OBJS 			= ${SRCS:.c=.o}

RM 				= rm -rf
CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror -I${LIBFT_PROJECT}

all: ${NAME}

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 		$(OBJS) ${LIBFT_PROJECT}
				ar -rcs ${NAME} $(OBJS)

${LIBFT_PROJECT}:
				make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} all
				cp ${LIBFT_PATH} ${NAME}

clean:
				${RM} ${OBJS}
				make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} clean

fclean: 		clean
				${RM} ${NAME}
				make -C ${LIBFT_PROJECT} -f ${LIBFT_MAKE} fclean

re: 			fclean all

test:
				ls -lR; make; cd ./tester; make; ./test m

.PHONY:			bonus all clean fclean re ${LIBFT_PROJECT}
