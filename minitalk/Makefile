# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2022/12/15 23:32:32 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
LIBFT = libft/libft.a
NAME = $(CLIENT) $(SERVER)

all: $(NAME)

$(NAME): $(OBJS_CLIENT) $(OBJS_SERVER) $(LIBFT)
		${CC} ${OBJS_CLIENT} libft/libft.a -o ${CLIENT}
		${CC} ${OBJS_SERVER} libft/libft.s -o ${SERVER}

$(LIBFT):
		${MAKE} -C ./libft

clean:	
		rm -rf ${OBJS_CLIENT} ${OBJS_SERVER}

fclean:	clean
		rm -rf $(NAME)

re:	fclean all
