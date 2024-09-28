# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 13:03:36 by nteechar          #+#    #+#              #
#    Updated: 2024/09/05 23:24:05 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c
OBJS = $(SRCS:%.c=%.o)
OBJ_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS))

.PHONY: all

all: $(OBJ_FILES)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
