# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 13:03:36 by nteechar          #+#    #+#              #
#    Updated: 2024/09/20 11:59:28 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	ft_lstnew_add_back.c ft_lstnew_add_front.c
OBJS = $(SRCS:%.c=%.o)
OBJ_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS))

.PHONY: all

all: $(OBJ_FILES)

$(OBJS_DIR)/%.o: %.c t_list.h
	$(CC) $(CFLAGS) -c $< -o $@
