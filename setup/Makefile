# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 18:57:57 by nteechar          #+#    #+#              #
#    Updated: 2024/11/27 19:00:49 by pesrisaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = setup.a

# commands
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
AR = ar rcs

# files
OBJS_DIR = .setup_objs

HEADERS = setup.h shell_data.h constants.h 

SRCS = init_minishell.c shell_data.c setup_signal.c setup_terminal.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# phony rules
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# rules
$(OBJS_DIR)/%.o: %.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $@
