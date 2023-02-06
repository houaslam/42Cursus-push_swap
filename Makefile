# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:26:10 by houaslam          #+#    #+#              #
#    Updated: 2023/02/06 01:08:11 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
# CFLAGS = -Wall -Wextra -Werror

SRCS =  srcs/errors.c \
		outils/libft.c \
		srcs/oper.c \
		srcs/outils_0.c \
		srcs/outils_1.c \
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


# ${NAME} : ${OBJ}
# 	cc $(CFLAGS) ${OBJ} -o ${NAME}


${NAME} : ${OBJ}
	cc  ${OBJ} -o ${NAME}


clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)
re: fclean all

mine : all clean