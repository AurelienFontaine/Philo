# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:25:06 by afontain          #+#    #+#              #
#    Updated: 2023/11/22 15:32:45 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./srcs/main.c \
	  ./srcs/actions/actions.c \
      ./srcs/actions/routine.c \
	  ./srcs/actions/checker.c \
	  ./srcs/init/data.c \
	  ./srcs/init/thread.c \
      ./srcs/init/mutex.c \
	  ./srcs/parsing/parsing.c \
	  ./srcs/print/print.c \
	  ./srcs/time/time.c \
	  ./srcs/utils/utils.c \
	  
CC = clang

CFLAGS = -Wall -Werror -Wextra -g3

AR =  ar rcs

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJ = $(SRC:.c=.o)

$(NAME)	:	${OBJ}
		$(CC) -pthread $(CFLAGS) $(OBJ) -o $(NAME)

all	:	$(NAME)

clean :
		rm -rf $(OBJ)

fclean :	clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re