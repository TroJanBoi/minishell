# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 13:03:36 by nteechar          #+#    #+#              #
#    Updated: 2024/09/05 23:23:57 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c \
	ft_isprint.c ft_isspace.c ft_isupper.c ft_isinset.c
OBJS = $(SRCS:%.c=%.o)
OBJ_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS))

.PHONY: all

all: $(OBJ_FILES)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
