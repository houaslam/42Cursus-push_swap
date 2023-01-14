# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:26:10 by houaslam          #+#    #+#              #
#    Updated: 2023/01/14 11:12:34 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS =  errors.c \
		libft.c \
		oper.c \
		outils.c \
		push_swap.c \
		ft_split.c \
		ft_strlen \
		libft_2.c \
		ft_split

all : ${NAME}

OBJ = ${SRCS:.c=.o}


${NAME} : ${OBJ}
	cc $(CFLAGS) ${OBJ} -o ${NAME}


clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)
re: fclean all