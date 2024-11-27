# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 13:24:14 by nteechar          #+#    #+#              #
#    Updated: 2024/11/20 17:33:22 by pesrisaw         ###   ########.fr        #
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
SRCS = setup_cmd_list.c find_path.c join_path.c run_heredocs.c \
	wait_for_all_processes.c ft_childprocess.c handle_redir_input_output.c \
	check_infiles.c execute.c command_not_found.c ft_parentprocess.c single_builtin.c

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
