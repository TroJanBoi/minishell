# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 19:13:22 by nteechar          #+#    #+#              #
#    Updated: 2024/11/16 18:06:58 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = builtin.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# files
HEADERS = builtin.h
SRCS = execute_builtin.c is_builtin_name.c \
	builtin_cd.c builtin_echo.c builtin_env.c builtin_exit.c \
	builtin_export.c builtin_pwd.c builtin_unset.c
OBJS = $(SRCS:%.c=%.o)

# phony rules
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# rules
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
