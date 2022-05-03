# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 15:24:04 by rkaufman          #+#    #+#              #
#    Updated: 2022/04/28 11:19:05 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft_tools.a

CC			:=	gcc

HEADERFILE	:=	libft_tools.h

SRCFILES 	:=	ft_char_first.c \
				ft_char_in_str.c \
				ft_copy.c \
				ft_count_of_in_str.c \
				ft_free_char_array.c \
				ft_get_next_line.c \
				ft_get_substring.c \
				ft_int_to_string.c \
				ft_read_file.c \
				ft_realloc.c \
				ft_replace_in_string.c \
				ft_split.c \
				ft_strlen.c \
				ft_string_compare.c \
				ft_string_to_int.c \
				ft_string_dup.c \
				ft_string_to_hex.c \
				ft_words_in_str.c \
				ft_calloc.c \
				ft_check_hex.c \
				ft_mem.c

OBJFILES	:= $(SRCFILES:%.c=%.o)

LDFLAGS		?=

CFLAGS		?= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean: 
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

norminette:
	norminette -R CheckForbiddenSourceHeader $(SRCFILES) $(HEADERFILE)

.PHONY: clean fclean re
