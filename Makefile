# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 16:48:53 by houaslam          #+#    #+#              #
#    Updated: 2023/03/03 21:18:47 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

SRCS = philo.c \
	  outil.c \
	  initialize.c \
	  actions.c \
	  check.c


all : ${NAME}

OBJ = ${SRCS:.c=.o}

${NAME} : ${OBJ}
	cc $(CFLAGS) ${OBJ} -o ${NAME}

push :
	git add .
	git commit -m philo
	git push

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)
re: fclean all