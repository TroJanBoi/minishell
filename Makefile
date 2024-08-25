# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 11:52:43 by nteechar          #+#    #+#              #
#    Updated: 2024/07/27 15:08:51 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
#CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LFLAGS = -L/usr/include -lreadline

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = header.h
SOURCES = main.c
OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(LFLAGS) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
