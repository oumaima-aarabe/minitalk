# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 09:11:30 by ouaarabe          #+#    #+#              #
#    Updated: 2023/03/03 09:14:21 by ouaarabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_isdigit.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strlen.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

RM = rm -rf

NAME = utils.a

%.o : %.c utils.h 
	$(CC) -c $(CFLAGS) $< -o $@

${NAME} : ${OBJS}
	ar -rcs $@ ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : fclean clean re