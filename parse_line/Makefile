# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 12:35:51 by nteechar          #+#    #+#              #
#    Updated: 2024/11/16 18:07:25 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parse_line.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# files
HEADERS = tokenize/token.h create_commands/command.h parse_line.h
SRCS = \
	expand_tokens/chop_word.c \
	expand_tokens/concatenate_subtokens.c \
	expand_tokens/expand_tokens.c \
	expand_tokens/interpret_single_subtoken.c \
	expand_tokens/interpret_subtokens.c \
	expand_tokens/expand_variable.c \
	\
	tokenize/token.c \
	tokenize/extract_token.c \
	tokenize/tokenize_line.c \
	\
	create_commands/command.c \
	create_commands/create_command_list.c \
	create_commands/get_argv_and_redirs.c \
	\
	is_grammar_correct.c parse_line.c combine_redirs.c

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
