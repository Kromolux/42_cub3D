/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:50:54 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/26 15:45:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "libft_tools/libft_tools.h"
# include "libft_printf/libft_printf.h"
# include <stdio.h>
# include <fcntl.h>
//open()
# include <stdlib.h>
# include <unistd.h>
//write()
//close()
# include <math.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# define WIDTH 1600
# define HEIGHT 900
# define TITLE "<cub3D> - <42 Wolfsburg Project> - <made by Eduard Hosu and Rene Kaufmann>"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16384
# endif
# ifndef XK_PLUS
#  define XK_PLUS 0xffab
# endif
# ifndef XK_MINUS
#  define XK_MINUS 0xffad
# endif
# define PI_2 6.283185307179586476925286766559
# define M_3PI2 4.71238899
# define M_PI2 1.57079637
# define DR 0.0174533

typedef enum e_return {
	RETURN_ERROR = -1,
	RETURN_SUCCESS = 0,
	RETURN_FALSE = 1,
	RETURN_TRUE = 2,
	RETURN_EXIT = 3
}			t_return;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_player {
	float		x;
	float		y;
	float		dx;
	float		dy;
	float		angle;
}				t_player;

typedef struct s_engine {
	void			*mlx;
	void			*window;
	t_data			img0;
	t_data			img1;
	t_data			*img;
	char			*file;
	struct s_map	*screen;
}				t_engine;

typedef struct s_point {
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct s_2d_point {
	int			x;
	int			y;
}				t_2d_point;

typedef struct s_resolution {
	int			width;
	int			height;
}				t_resolution;

typedef struct s_3d_point {
	int			x;
	int			y;
	int			z;
	int			color;
}				t_3d_point;

typedef struct s_pivot {
	int			column;
	int			row;
}				t_pivot;

typedef struct s_sin_cos {
	float		cos_x;
	float		cos_y;
	float		cos_z;
	float		sin_x;
	float		sin_y;
	float		sin_z;
}				t_sin_cos;

typedef struct s_line {
	t_3d_point		start;
	t_3d_point		pos;
	t_3d_point		end;
	int				dx;
	int				dy;
	int				main_x;
	int				x_next;
	int				y_next;
	int				p_start;
	int				p_less;
	int				p_greater;
}				t_line;

typedef struct s_map {
	struct s_player		player;
	char				**map;
	//struct s_3d_point	**map;
	//struct s_3d_point	**proj;
	//int					paralel;
	//int					colored;
	int					rows;
	int					columns;
	int					zoom;
	int					zoom_z;
	struct s_resolution	resolution;
	struct s_pivot		pivot;
	struct s_2d_point	offset;
	struct s_2d_point	tile_size;
	struct s_point		factor;
	struct s_point		angle;
	struct s_point		movement;
}				t_map;

typedef struct s_algo {
	int			*primary;
	int			*secondary;
	int			*primary_next;
	int			*secondary_next;
	int			*primary_end;
}				t_algo;

//ft_error.c
int				ft_error_arguments(void);
int				ft_error_malloc(char *function, char *variable, size_t size);
int				ft_error_file(char *function, char *file);
int				ft_error_file_result(char *function, char *file, int fd);
int				ft_error_number(char *function, char *value, size_t row,
					size_t column);
void			ft_error_split(t_map *screen, char *input);

//ft_error1.c
int				ft_error_extension(char *file);
int				ft_error_char(char c, int row);
int				ft_error_border(char c, int row, int column);
int				ft_error_player(char c, int row, int column);
int				ft_error_no_player(void);

//ft_error_map.c
void			ft_error_input(t_map *screen, char **string_array);
void			ft_error_map(t_map *screen, char **string_array);
void			ft_error_proj(t_map *screen, char **string_array);
void			ft_error_map_row(t_map *screen, char **string_array,
					int i_row);
void			ft_error_proj_row(t_map *screen, char **string_array,
					int i_row);

//ft_memory_map.c
void			ft_allocate_mem_map(t_map *screen, char **string_array);
void			ft_free_map(t_map *screen);

//ft_engine.c
void			ft_engine_init(t_engine *engine);
int				ft_engine_destroy(t_engine *engine);

//ft_string.c
size_t			ft_count_of_columns(char *s, char c);
void			ft_check_input_exit_on_error(t_map *screen, char **input);
int				ft_valid_number(char *argv);
int				ft_empty_space(char c);
int				ft_check_around(char **input, int row, int column);
int				ft_is_player(char c);

//ft_file.c
t_map			*ft_read_input_map(char *file);

//ft_map_array.c
void			ft_create_map_array(char *input, t_map *screen);
void			ft_get_point(t_engine *engine, int row, int column,
					t_3d_point *point);

//ft_geometry.c
void			ft_draw_rectangle(t_engine *engine, t_line rectangle);
void			ft_draw_rectangle_full(t_engine *engine, t_line rectangle);

//ft_lines0.c
void			ft_draw_rectangle(t_engine *engine, t_line rectangle);
void			ft_draw_line(t_engine *engine, t_line line);
void			ft_line_preparations(t_line *line);
void			ft_draw_line_edge_case(t_engine *engine, t_line line);
int				ft_at_least_one_point_on_screen(t_engine *engine, t_line *line);

//ft_lines1.c
void			ft_draw_line_algorythm(t_engine *engine, t_line line);

//ft_pixel.c
void			ft_put_pixel(t_data *data, int x, int y, int color);
void			ft_get_point(t_engine *engine, int row, int column,
					t_3d_point *point);

//ft_color.c
int				ft_get_color(t_line *line);
double			ft_get_percentage(int start, int end, int pos);
int				ft_get_rgb(int start, int end, double percentage);

//ft_math.c
unsigned int	ft_abs(int number);
void			ft_apply_rotation(t_engine *engine);
float			ft_dist(t_player *player, float rx, float ry);

//ft_rotations.c
void			ft_rotate_x(t_engine *engine, int i_row, int i_column,
					t_sin_cos *calcs);
void			ft_rotate_y(t_engine *engine, int i_row, int i_column,
					t_sin_cos *calcs);
void			ft_rotate_z(t_engine *engine, int i_row, int i_column,
					t_sin_cos *calcs);

//ft_key0.c
int				ft_key(int keycode, t_engine *engine);
void			ft_key_projection_change(int keycode, t_engine *engine);
void			ft_key_player_movement(int keycode, t_engine *engine);
void			ft_key_player_rotation(int key, t_engine *engine);
void			ft_key_zoom(int keycode, t_engine *engine);

//ft_key1.c
void			ft_key_center_view(int keycode, t_engine *engine);

//ft_grafic.c
int				ft_render_frame(t_engine *engine);
void			ft_clear_image(t_engine *engine);
void			ft_draw_map(t_engine *engine);

//ft_display_info.c
void			ft_display_info(t_engine *engine);

//ft_player.c
void			ft_draw_player(t_engine *engine);

//ft_raycasting.c
void			ft_draw_3d_ray(t_engine *engine);

#endif