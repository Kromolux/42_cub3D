/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:50:54 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/28 18:58:24 by rkaufman         ###   ########.fr       */
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
# define DISTANCE 20

typedef enum e_return {
	RETURN_ERROR = -1,
	RETURN_SUCCESS = 0,
	RETURN_FALSE = 1,
	RETURN_TRUE = 2,
	RETURN_EXIT = 3
}			t_return;

typedef struct s_key {
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_key;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_player {
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		angle;
	int			free_w;
	int			free_s;
	int			free_a;
	int			free_d;
}				t_player;

typedef struct s_2d_point {
	int			x;
	int			y;
}				t_2d_point;

typedef struct s_engine {
	void				*mlx;
	void				*window;
	struct s_data		img0;
	struct s_data		img1;
	struct s_data		*img;
	char				*file;
	struct s_map		*screen;
	struct s_key		key;
	struct s_data		no_tex;
	struct s_data		so_tex;
	struct s_data		we_tex;
	struct s_data		ea_tex;
	struct s_2d_point	offset;
}				t_engine;



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
	int					rows;
	int					columns;
	int					map_start;
	int					floor_color;
	int					ceiling_color;
	char				*texture_no;
	char				*texture_so;
	char				*texture_we;
	char				*texture_ea;
	int					tile_size;
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

//ft_error2.c
int				ft_error_map_file(char *s, int row);

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
int				ft_check_map_identifier(t_map *screen);
size_t			ft_get_map_columns(char **input);

//ft_geometry.c
void			ft_draw_rectangle(t_engine *engine, t_line rectangle);
void			ft_draw_rectangle_full(t_engine *engine, t_line rectangle);

//ft_lines0.c
void			ft_draw_rectangle(t_engine *engine, t_line rectangle);
void			ft_draw_line(t_engine *engine, t_line line);
void			ft_line_preparations(t_line *line);
void			ft_draw_line_edge_case(t_engine *engine, t_line line);
int				ft_at_least_one_point_on_screen(t_line *line);

//ft_lines1.c
void			ft_draw_line_algorythm(t_engine *engine, t_line line);

//ft_pixel.c
void			ft_put_pixel(t_data *data, int x, int y, int color);
void			ft_get_point(t_engine *engine, int row, int column,
					t_3d_point *point);
int				ft_get_pixel(t_data *data, int x, int y);

//ft_color.c
int				ft_get_color(t_line *line);
double			ft_get_percentage(int start, int end, int pos);
int				ft_get_rgb(int start, int end, double percentage);
int				ft_get_rgb_color(char *s);

//ft_math.c
unsigned int	ft_abs(int number);
void			ft_apply_rotation(t_engine *engine);
double			ft_dist(t_player *player, double rx, double ry);
float			ft_dist_new(int dx, int dy, float angle);
double			ft_fix_angle(double a);
double			ft_deg_to_rad(double d);

//ft_rotations.c


//ft_key0.c
int				ft_key(int keycode, t_engine *engine);
void			ft_key_projection_change(int keycode, t_engine *engine);
void			ft_key_player_movement(int keycode, t_engine *engine);
void			ft_key_player_move(t_engine *engine);
void			ft_key_player_rotation(int key, t_engine *engine);

int				ft_key_pressed(int keycode, t_engine *engine);
int				ft_key_released(int keycode, t_engine *engine);
void			ft_key_player_rotate_pressed(int keycode, t_engine *engine);
void			ft_key_player_rotate_released(int keycode, t_engine *engine);
void			ft_key_player_rotate(t_engine *engine);
void	ft_key_player_move_pressed(int keycode, t_engine *engine);
void	ft_key_player_move_released(int keycode, t_engine *engine);
//ft_key1.c


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