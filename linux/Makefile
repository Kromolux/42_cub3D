# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 08:48:00 by rkaufman          #+#    #+#              #
#    Updated: 2022/04/26 10:01:51 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	cub3D
NAME_BONUS			:=	
LIBFT_TOOLS_LIB		:=	libft_tools.a
LIBFT_TOOLS_PATH	:=	libft_tools
LIBFT_PRINTF_LIB	:=	libft_printf.a
LIBFT_PRINTF_PATH	:=	libft_printf

LIB_PATH			:=	./
MLX_PATH			:=	minilibx-linux
MLX_LIB				:=	mlx_Linux

OBJ_FOLDER			:=	objs
SRC_FOLDER			:=	srcs

CC					:=	gcc
HEADERFILE			:=	cube3d.h

SRC_LIB				:=	

SRCS			:=	ft_cube3d.c \
					map/map_validation.c \
					engine/ft_engine.c \
					engine/ft_lines0.c \
					engine/ft_lines1.c \
					engine/ft_math.c \
					engine/ft_rotations.c \
					engine/ft_pixel.c \
					engine/ft_player.c \
					keys/ft_key0.c \
					keys/ft_key1.c \
					map/ft_file.c \
					map/ft_string.c \
					map/ft_map_array.c \
					engine/ft_grafic.c \
					engine/ft_display_info.c \
					errors/ft_error.c \
					errors/ft_error1.c \
					errors/ft_error_map.c \
					map/ft_memory_map.c \
					engine/ft_geometry.c \
					engine/ft_color.c \
					engine/ft_raycasting.c

SRC_BONUS	:=	

OBJS		:=	$(SRCS:%.c=$(OBJ_FOLDER)/%.o)

CFLAGS		:=	-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	make -C $(LIBFT_TOOLS_PATH)
	make -C $(LIBFT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PRINTF_PATH) -lft_printf -L$(LIBFT_TOOLS_PATH) -lft_tools -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): $(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ_FOLDER)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_TOOLS_PATH) clean
	make -C $(LIBFT_PRINTF_PATH) clean

fclean: clean
	rm -fr $(NAME)
	make -C $(LIBFT_TOOLS_PATH) fclean
	make -C $(LIBFT_PRINTF_PATH) fclean

re: fclean all
	make -C $(LIBFT_TOOLS_PATH) re
	make -C $(LIBFT_PRINTF_PATH) re

norminette:
	cd srcs norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckForbiddenSourceHeader $(HEADERFILE)
	make -C $(LIBFT_TOOLS_PATH) norminette
	make -C $(LIBFT_PRINTF_PATH) norminette

val:
	valgrind --leak-check=full -s ./$(NAME)

.PHONY: clean fclean re