# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:25:06 by afontain          #+#    #+#              #
#    Updated: 2023/10/24 14:27:15 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./srcs/main.c \
	  ./srcs/utils/utils.c \
	  ./srcs/create/thread.c \
      ./srcs/create/mutex.c \
	  ./srcs/parsing/parsing.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

AR =  ar rcs

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJ = $(SRC:.c=.o)

$(NAME)	:	${OBJ}
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all	:	$(NAME)

clean :
		rm -rf $(OBJ)

fclean :	clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re