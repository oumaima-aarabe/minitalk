# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 22:17:07 by ouaarabe          #+#    #+#              #
#    Updated: 2023/03/01 01:33:49 by ouaarabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	client
SERVER	=	server

LIBFTPRINTF	=	ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	ft_printf

SRC_C	=	client.c
SRC_S	=	server.c

OBJ_S	=	server.o
OBJ_C	=	client.o

INC		=	minitalk.h

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_S)

$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_C)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: clean fclean re