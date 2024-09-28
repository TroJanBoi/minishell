# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 13:18:31 by nteechar          #+#    #+#              #
#    Updated: 2024/09/18 14:30:20 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

RED = \033[31m
GREEN = \033[32m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

OBJS_DIR = __objs
OBJS = $(OBJS_DIR)/*

.PHONY: all clean fclean re compile

all: compile

$(NAME): $(OBJS)
	$(AR) $@ $^

compile:
	@printf "$(GREEN)Compiling .o files\n$(RESET)"
	@mkdir -p $(OBJS_DIR)
	@$(MAKE) -C conversion OBJS_DIR=$(abspath $(OBJS_DIR))
	@$(MAKE) -C ft_printf OBJS_DIR=$(abspath $(OBJS_DIR))
	@$(MAKE) -C ft_string OBJS_DIR=$(abspath $(OBJS_DIR))
	@$(MAKE) -C get_next_line OBJS_DIR=$(abspath $(OBJS_DIR))
	@$(MAKE) -C list OBJS_DIR=$(abspath $(OBJS_DIR))
	@$(MAKE) -C memory OBJS_DIR=$(abspath $(OBJS_DIR))
	@$(MAKE) -C putting OBJS_DIR=$(abspath $(OBJS_DIR))
	@$(MAKE) -C type_checking OBJS_DIR=$(abspath $(OBJS_DIR))
	@printf "$(GREEN)\nLinking libft.a\n$(RESET)"
	@$(MAKE) $(NAME)
	@printf "\n"

clean:
	@printf "$(RED)Removing .o files\n$(RESET)"
	$(RM) $(OBJS_DIR)/*
	@printf "\n"

fclean: clean
	@printf "$(RED)Removing libft.a\n$(RESET)"
	$(RM) $(NAME)
	@printf "\n"

re: fclean all
