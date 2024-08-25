# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 13:18:31 by nteechar          #+#    #+#              #
#    Updated: 2024/07/27 15:07:38 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

HEADERS = ft_printf/ft_printf.h get_next_line/get_next_line.h libft.h

FT_PRINTF_SOURCES = ft_printf/ft_printf.c \
	ft_printf/putting/put_address.c \
	ft_printf/putting/put_char.c \
	ft_printf/putting/put_hex.c \
	ft_printf/putting/put_int.c \
	ft_printf/putting/put_str.c \
	ft_printf/putting/put_unsigned_int.c

GET_NEXT_LINE_SOURCES = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

SOURCES = $(FT_PRINTF_SOURCES) \
	$(GET_NEXT_LINE_SOURCES) \
	conversion/ft_atoi.c \
	conversion/ft_itoa.c \
	conversion/ft_tolower.c \
	conversion/ft_toupper.c \
	list/ft_lstadd_back.c \
	list/ft_lstadd_front.c \
	list/ft_lstclear.c \
	list/ft_lstdelone.c \
	list/ft_lstiter.c \
	list/ft_lstlast.c \
	list/ft_lstmap.c \
	list/ft_lstnew.c \
	list/ft_lstsize.c \
	memory/ft_bzero.c \
	memory/ft_calloc.c \
	memory/ft_memchr.c \
	memory/ft_memcmp.c \
	memory/ft_memcpy.c \
	memory/ft_memmove.c \
	memory/ft_memset.c \
	my_string/ft_split.c \
	my_string/ft_strchr.c \
	my_string/ft_strdup.c \
	my_string/ft_striteri.c \
	my_string/ft_strjoin.c \
	my_string/ft_strlcat.c \
	my_string/ft_strlcpy.c \
	my_string/ft_strlen.c \
	my_string/ft_strmapi.c \
	my_string/ft_strncmp.c \
	my_string/ft_strnstr.c \
	my_string/ft_strrchr.c \
	my_string/ft_strtrim.c \
	my_string/ft_substr.c \
	putting/ft_putchar_fd.c \
	putting/ft_putendl_fd.c \
	putting/ft_putnbr_fd.c \
	putting/ft_putstr_fd.c \
	type_checking/ft_isalnum.c \
	type_checking/ft_isalpha.c \
	type_checking/ft_isascii.c \
	type_checking/ft_isdigit.c \
	type_checking/ft_islower.c \
	type_checking/ft_isprint.c \
	type_checking/ft_isspace.c \
	type_checking/ft_isupper.c \

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
