# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 15:21:55 by mtavares          #+#    #+#              #
#    Updated: 2022/08/04 16:11:14 by mtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER	= server.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

SRC_CLIENT	= client.c

OBJ_CLIENT	= $(SRC_CLIENT:.o=.c)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

SERVER_NAME	= server

CLIENT_NAME	= client

all: server client

server:	$(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER_NAME)

client:	$(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT_NAME)

clean:
	rm -rf *.o

fclean:	clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re:	fclean all

.PHONY: all clean fclean re
