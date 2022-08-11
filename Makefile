# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 20:11:55 by crigonza          #+#    #+#              #
#    Updated: 2022/08/04 20:46:02 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
SERVER	= server
CLIENT	= client
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
LIBFT	= ./LIBFT
SRCS_SERVER	= server.c \

SRCS_CLIENT = client.c \

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER_BONUS	= server_bonus.c \

SRCS_CLIENT_BONUS = client_bonus.c \

OBJS_SERVER_BONUS	= $(SRCS_SERVER_BONUS:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all:	libft $(SERVER) $(CLIENT)
 
$(NAME): all

libft:
		@$(MAKE) -C $(LIBFT)

%.o: %.c
		@$(CC) $(FLAGS) -o $@ -c $<

$(SERVER): $(OBJS_SERVER)
		$(CC) $(FLAGS) $(LIBFT)/libft.a $(OBJS_SERVER) -o $(SERVER)
		
$(CLIENT): $(OBJS_CLIENT)
		$(CC) $(FLAGS) $(LIBFT)/libft.a $(OBJS_CLIENT) -o $(CLIENT)

bonus: $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
		$(MAKE) -C $(LIBFT)
		$(CC) $(FLAGS) $(LIBFT)/libft.a $(OBJS_SERVER_BONUS) -o $(SERVER)
		$(CC) $(FLAGS) $(LIBFT)/libft.a $(OBJS_CLIENT_BONUS) -o $(CLIENT)

clean:
		@rm -f $(OBJS_SERVER)
		@rm -f $(OBJS_CLIENT)
		@rm -f $(OBJS_SERVER_BONUS)
		@rm -f $(OBJS_CLIENT_BONUS)
		@$(MAKE) -C $(LIBFT) clean

fclean: clean
		@rm -f $(SERVER)
		@rm -f $(CLIENT)
		@$(MAKE) -C $(LIBFT) fclean

re: clean all

.PHONY: all, clean, fclean, re, libft