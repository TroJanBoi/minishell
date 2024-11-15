# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 11:52:43 by nteechar          #+#    #+#              #
#    Updated: 2024/11/13 14:51:11 by pesrisaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# styles
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
RESET = \033[0m

# commands
MAKEFLAGS += --no-print-directory

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

# files
SRCS = main.c read_line.c
OBJS = $(SRCS:%.c=%.o)

MODULE_DIRS = parse_line builtin execute setup __debugging
MODULES = $(foreach dir, $(MODULE_DIRS),$(dir)/$(dir).a)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

LFLAGS = -L/usr/include -lreadline -lhistory

# phony rules
.PHONY: all clean fclean re $(LIBFT_DIR) $(MODULE_DIRS)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@for dir in $(MODULE_DIRS); do \
		echo "$(RED)delete $$dir's .o files$(RESET)"; \
		$(MAKE) clean -C $$dir; \
	done
	$(RM) $(OBJS)

fclean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@for dir in $(MODULE_DIRS); do \
		$(MAKE) fclean -C $$dir; \
	done
	$(RM) $(NAME)

re: fclean all

$(LIBFT_DIR) $(MODULE_DIRS):
	@echo "$(BOLD)$(GREEN)build $@$(RESET)"
	@$(MAKE) -C $@

# rules
$(LIBFT): $(LIBFT_DIR)
$(MODULES): $(MODULE_DIRS)

$(NAME): $(LIBFT) $(MODULES) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MODULES) $(LIBFT) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
