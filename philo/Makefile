# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:25:06 by afontain          #+#    #+#              #
#    Updated: 2023/10/25 15:19:09 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./srcs/main.c \
	  ./srcs/utils/utils.c \
	  ./srcs/init/data.c \
	  ./srcs/init/thread.c \
      ./srcs/init/mutex.c \
	  ./srcs/parsing/parsing.c \
	  ./srcs/clear/clear.c \
	  ./srcs/action/routine.c \
	  ./srcs/action/checker.c \
	  
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