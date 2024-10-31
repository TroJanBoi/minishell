# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 11:52:43 by nteechar          #+#    #+#              #
#    Updated: 2024/10/16 22:06:56 by pesrisaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
RM = rm -rf
LFLAGS = -L/usr/include -lreadline -lhistory

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = parse/parse.h \
	__debugging.h \
	execute/execute.h

EXECUTE_SRCS = execute/init_execute.c \
	execute/free_exe.c \
	execute/check_file.c \
	execute/error.c \
	execute/wait_allprocess.c
SIGNAL_SRCS = 
HISTORY_SRCS = 

__DEBUGGING_SRCS = __debugging.c

PARSE_SRCS = parse_line/command/command.c \
	parse_line/command/handle_tokens.c \
	parse_line/command/tokens_to_commands.c \
	parse_line/command/transform_tokens.c \
	parse_line/token/expand_tokens.c \
	parse_line/token/token.c \
	parse_line/token/tokenize.c \
	parse_line/is_grammar_correct.c \
	parse_line/parse_line.c \

SRCS = main.c $(PARSE_SRCS) $(__DEBUGGING_SRCS) \
	$(EXECUTE_SRCS) $(SIGNAL_SRCS) $(HISTORY_SRCS)
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all
