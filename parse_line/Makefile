# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 12:35:51 by nteechar          #+#    #+#              #
#    Updated: 2024/11/07 09:57:37 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parse_line.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# files
HEADERS = token/token.h command/command.h parse_line.h
SRCS = command/command.c \
	\
	expand_tokens/concatenate_word_subtokens.c \
	expand_tokens/expand_tokens.c \
	expand_tokens/expand_word_subtokens.c \
	expand_tokens/expand_word_token.c \
	expand_tokens/tokenize_word.c \
	\
	token/token.c \
	\
	tokenize_line/get_token_str.c \
	tokenize_line/get_token_type.c \
	tokenize_line/get_token.c \
	tokenize_line/tokenize_line.c \
	\
	tokens_to_commands/handle_tokens.c \
	tokens_to_commands/tokens_to_commands.c \
	tokens_to_commands/transform_tokens.c \
	\
	is_grammar_correct.c parse_line.c
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
