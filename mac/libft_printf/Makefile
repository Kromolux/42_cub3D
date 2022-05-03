# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 19:38:27 by rkaufman          #+#    #+#              #
#    Updated: 2022/03/08 14:59:55 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:=	libft_printf.a
CC 			:=	gcc
HEADERFILE	:=	libft_printf.h

SRCFILES 	:=	ft_printf_bonus.c \
				ft_sprintf_bonus.c \
				ft_conversation0.c \
				ft_conversation1.c \
				ft_hex.c \
				ft_output_bonus.c \
				ft_init_flags_bonus.c \
				ft_read_flags_bonus.c \
				ft_apply_flags_bonus.c \
				ft_apply_precision_bonus.c \
				ft_additional_tools_bonus.c

OBJFILES	:=	$(SRCFILES:%.c=%.o)

CFLAGS		:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJFILES)
	$(AR) rcs $(NAME) $(OBJFILES)

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
