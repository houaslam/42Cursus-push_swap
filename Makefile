# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:26:10 by houaslam          #+#    #+#              #
#    Updated: 2023/02/22 10:51:45 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
BONUS = checker
CFLAGS = -Wall -Wextra -Werror


SRCS =  srcs/general/errors.c \
		srcs/general/useless_op.c \
		srcs/general/main.c \
		srcs/general/oper.c \
		srcs/general/oper_1.c \
		srcs/!small/outils_1.c \
		srcs/!small/first_stage.c \
		srcs/!small/second_stage.c \
		srcs/small/index.c \
		srcs/small/small_outils.c \
		srcs/small/small_swap.c \
		outils/ft_split.c \
		outils/sort.c \
		outils/libft_3.c \
		outils/libft_2.c \
		outils/libft.c \
		srcs/general/main_push.c

B_SRCS =  srcs/general/errors.c \
		  srcs/general/useless_op.c \
		  srcs/general/oper.c \
		  srcs/general/oper_1.c \
		  srcs/!small/outils_1.c \
		  srcs/!small/first_stage.c \
		  srcs/!small/second_stage.c \
		  srcs/small/index.c \
		  srcs/small/small_outils.c \
		  srcs/small/small_swap.c \
		  outils/ft_split.c \
		  outils/sort.c \
		  outils/gnl.c \
		  outils/gnl_outils.c \
		  outils/libft_3.c \
		  outils/libft_2.c \
		  outils/libft.c \
		  srcs/general/main_push.c \
		  srcs/bonus/main.c

all : ${NAME}

OBJ = ${SRCS:.c=.o}
B_OBJ = ${B_SRCS:.c=.o}

bonus : ${B_OBJ}
	cc $(CFLAGS) ${B_OBJ} -o ${BONUS}

${NAME} : ${OBJ}
	cc $(CFLAGS) ${OBJ} -o ${NAME}

clean :
	rm -f ${OBJ}
	rm -f ${B_OBJ}

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)
re: fclean all
