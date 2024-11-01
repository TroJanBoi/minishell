# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 11:52:43 by nteechar          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2024/10/29 18:13:43 by nteechar         ###   ########.fr        #
=======
#    Updated: 2024/10/16 18:32:42 by pesrisaw         ###   ########.fr        #
>>>>>>> parent of 3c88b8d (update infile)
#                                                                              #
# **************************************************************************** #

NAME = minishell

# commands
CC = cc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -rf

# files
LIBFT = libft/libft.a
LFLAGS = -L/usr/include -lreadline -lhistory

HEADERS = $(INCLUDES) $(PARSE_LINE_HEADERS) $(BUILTIN_HEADERS) \
	$(FT_SIGNAL_HEADERS) $(ENV_VAR_HEADERS) $(DEBUGGING_HEADERS) $(EXECUTE_HEADERS)
SRCS = $(SOURCES) $(PARSE_LINE_SRCS) $(BUILTIN_SRCS) \
	$(FT_SIGNAL_SRCS) $(ENV_VAR_SRCS) $(DEBUGGING_SRCS) $(EXECUTE_SRCS)
OBJS = $(SRCS:%.c=%.o)

# debugging directory
DEBUGGING_HEADERS = __debugging/__debugging.h __debugging/colors.h
DEBUGGING_SRCS = __debugging/__debugging.c

# high_level directory
INCLUDES = includes/minishell.h includes/t_shell_data.h \
	includes/constants.h includes/external_func.h
SOURCES = sources/main.c sources/evaluate_line.c \
	sources/ft_readline.c sources/init.c

# parse_line directory
PARSE_LINE_HEADERS = parse_line/token/token.h \
	parse_line/command/command.h \
	parse_line/parse_line.h
PARSE_LINE_SRCS = parse_line/command/command.c \
	\
	parse_line/expand_tokens/concatenate_word_subtokens.c \
	parse_line/expand_tokens/expand_tokens.c \
	parse_line/expand_tokens/expand_word_subtokens.c \
	parse_line/expand_tokens/expand_word_token.c \
	parse_line/expand_tokens/tokenize_word.c \
	\
	parse_line/token/token.c \
	\
	parse_line/tokenize_line/get_token_str.c \
	parse_line/tokenize_line/get_token_type.c \
	parse_line/tokenize_line/get_token.c \
	parse_line/tokenize_line/tokenize_line.c \
	\
	parse_line/tokens_to_commands/handle_tokens.c \
	parse_line/tokens_to_commands/tokens_to_commands.c \
	parse_line/tokens_to_commands/transform_tokens.c \
	\
	parse_line/is_grammar_correct.c parse_line/parse_line.c

# builtin directory
BUILTIN_HEADERS = builtin/builtin.h
BUILTIN_SRCS = builtin/builtin_cd.c \
	builtin/builtin_echo.c \
	builtin/builtin_env.c \
	builtin/builtin_exit.c \
	builtin/builtin_export.c \
	builtin/builtin_pwd.c \
	builtin/builtin_unset.c

# signal directory
FT_SIGNAL_HEADERS = ft_signal/ft_signal.h
FT_SIGNAL_SRCS = ft_signal/ft_signal.c

# env_var directory
ENV_VAR_HEADERS = env_var/env_var.h
ENV_VAR_SRCS = env_var/env_var.c

# execute dir
EXECUTE_HEADERS = execute/execute.h execute/t_exe.h
EXECUTE_SRCS = execute/check_file.c execute/execute.c execute/free_exe.c \
	execute/ft_err.c execute/init_cmd_list.c  

# phony rules
.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT) $(NAME)

re: fclean all

# rules
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $@

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
