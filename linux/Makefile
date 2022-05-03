# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 08:48:00 by rkaufman          #+#    #+#              #
#    Updated: 2022/05/03 12:06:27 by rkaufman         ###   ########.fr        #
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
OBJ_FOLDER_BONUS	:=	objs_bonus
SRC_FOLDER			:=	srcs

CC					:=	gcc
HEADERFILE			:=	cube3d.h

SRC_LIB				:=	

SRCS			:=	ft_cube3d.c \
					engine/ft_engine0.c \
					engine/ft_engine1_linux.c \
					engine/ft_lines0.c \
					engine/ft_lines1.c \
					engine/ft_math.c \
					engine/ft_pixel.c \
					engine/ft_player.c \
					engine/ft_horizontal_ray.c \
					engine/ft_vertical_ray.c \
					engine/ft_background.c \
					engine/ft_texture.c \
					engine/ft_grafic.c \
					engine/ft_display_info.c \
					engine/ft_geometry.c \
					engine/ft_color.c \
					engine/ft_raycasting0.c \
					engine/ft_raycasting1.c \
					keys/ft_key0_linux.c \
					keys/ft_key1_linux.c \
					keys/ft_key2_linux.c \
					map/ft_file.c \
					map/ft_string.c \
					map/ft_map_array.c \
					map/ft_check_input_map0.c \
					map/ft_check_input_map1.c \
					map/ft_check_input_map2.c \
					map/ft_memory_map0.c \
					map/ft_memory_map1.c \
					errors/ft_error0.c \
					errors/ft_error1.c \
					errors/ft_error2.c \
					errors/ft_error_map.c

SRCS_BONUS		:=	ft_cube3d.c \
					engine/ft_engine0.c \
					engine/ft_engine1_linux.c \
					engine/ft_lines0.c \
					engine/ft_lines1.c \
					engine/ft_math.c \
					engine/ft_pixel.c \
					engine/ft_player.c \
					engine/ft_horizontal_ray.c \
					engine/ft_vertical_ray.c \
					engine/ft_background.c \
					engine/ft_texture.c \
					engine/ft_grafic_bonus.c \
					engine/ft_display_info.c \
					engine/ft_geometry.c \
					engine/ft_color.c \
					engine/ft_raycasting0.c \
					engine/ft_raycasting1.c \
					keys/ft_key0_linux.c \
					keys/ft_key1_linux.c \
					keys/ft_key2_linux.c \
					map/ft_file.c \
					map/ft_string.c \
					map/ft_map_array.c \
					map/ft_overview_bonus.c \
					map/ft_check_input_map0.c \
					map/ft_check_input_map1.c \
					map/ft_check_input_map2.c \
					map/ft_memory_map0.c \
					map/ft_memory_map1.c \
					errors/ft_error0.c \
					errors/ft_error1.c \
					errors/ft_error2.c \
					errors/ft_error_map.c

OBJS			:=	$(SRCS:%.c=$(OBJ_FOLDER)/%.o)
OBJS_BONUS		:=	$(SRCS_BONUS:%.c=$(OBJ_FOLDER_BONUS)/%.o)

CFLAGS		:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	make -C $(LIBFT_TOOLS_PATH)
	make -C $(LIBFT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PRINTF_PATH) -lft_printf -L$(LIBFT_TOOLS_PATH) -lft_tools -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): $(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	make -C $(MLX_PATH)
	make -C $(LIBFT_TOOLS_PATH)
	make -C $(LIBFT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_PRINTF_PATH) -lft_printf -L$(LIBFT_TOOLS_PATH) -lft_tools -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS_BONUS): $(OBJ_FOLDER_BONUS)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ_FOLDER)
	rm -fr $(OBJ_FOLDER_BONUS)
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

norm:
	cd srcs && norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckForbiddenSourceHeader $(HEADERFILE)
	make -C $(LIBFT_TOOLS_PATH) norminette
	make -C $(LIBFT_PRINTF_PATH) norminette

val:
	clear
	valgrind --leak-check=full -s ./$(NAME) test_maps/test.cub

.PHONY: clean fclean re