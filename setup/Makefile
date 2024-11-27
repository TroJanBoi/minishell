# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 18:57:57 by nteechar          #+#    #+#              #
#    Updated: 2024/11/20 17:49:03 by pesrisaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = setup.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# files
HEADERS = constants.h env_var.h setup.h
SRCS = create_env_var_list.c env_var_list.c env_var.c setup_signal.c setup.c free_env.c
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
