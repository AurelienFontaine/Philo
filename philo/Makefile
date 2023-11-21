# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:25:06 by afontain          #+#    #+#              #
#    Updated: 2023/11/13 17:26:37 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./srcs/main.c \
	  ./srcs/action/actions.c \
      ./srcs/action/routine.c \
	  ./srcs/action/checker.c \
	  ./srcs/clear/clear.c \
	  ./srcs/init/data.c \
	  ./srcs/init/thread.c \
      ./srcs/init/mutex.c \
	  ./srcs/parsing/parsing.c \
	  ./srcs/time/time.c \
	  ./srcs/utils/utils.c \
	  
CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

AR =  ar rcs

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJ = $(SRC:.c=.o)

$(NAME)	:	${OBJ}
		$(CC) -pthread $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all	:	$(NAME)

clean :
		rm -rf $(OBJ)

fclean :	clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re