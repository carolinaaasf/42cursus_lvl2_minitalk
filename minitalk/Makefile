# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2022/12/20 19:12:36 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
LIBFT = libft/libft.a
NAME = $(SERVER) $(CLIENT)

all: $(NAME)

$(NAME): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		${CC} ${OBJS_SERVER} libft/libft.a -o ${SERVER}
		${CC} ${OBJS_CLIENT} libft/libft.a -o ${CLIENT}

$(LIBFT):
		${MAKE} -C ./libft

clean:	
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:	clean
		rm -rf $(NAME)

re:	fclean all
