# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:26:10 by houaslam          #+#    #+#              #
#    Updated: 2023/02/03 19:37:30 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CFLAGS = gcc -Wall -Wextra -Werror

SRCS =  srcs/errors.c \
		outils/libft.c \
		srcs/oper.c \
		srcs/outils.c \
		srcs/push_swap.c \
		outils/ft_split.c \
		outils/ft_strlen.c \
		outils/libft_2.c \
		outils/sort.c \
		srcs/del.c \
		srcs/swap.c \
		srcs/main.c

all : ${NAME}

OBJ = ${SRCS:.c=.o}


${NAME} : ${OBJ}
	$(CFLAGS) ${OBJ} -o ${NAME}


clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)
re: fclean all

mine : all clean