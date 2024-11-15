# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 13:24:14 by nteechar          #+#    #+#              #
#    Updated: 2024/11/15 02:17:32 by pesrisaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execute.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# files
HEADERS = execute.h
SRCS = check_file.c execute.c setup_cmd_list.c \
		check_path.c check_backslash.c find_path.c \
		join_path.c free_arr.c heredoc.c redirs_input.c redirs_output.c \
		wait_process.c
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
