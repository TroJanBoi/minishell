# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 13:03:36 by nteechar          #+#    #+#              #
#    Updated: 2024/08/28 14:25:16 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADERS = 
SRCS = ft_printf.c put_address.c put_char.c put_hex.c put_int.c put_str.c put_unsigned_int.c
OBJS = $(SRCS:%.c=%.o)
OBJ_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS))

.PHONY: all

all: $(OBJ_FILES)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
