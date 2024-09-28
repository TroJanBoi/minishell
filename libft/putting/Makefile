# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 13:03:36 by nteechar          #+#    #+#              #
#    Updated: 2024/09/05 23:24:03 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
OBJS = $(SRCS:%.c=%.o)
OBJ_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS))

.PHONY: all

all: $(OBJ_FILES)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
