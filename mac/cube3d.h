/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:50:54 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 10:34:35 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "libft_tools/libft_tools.h"
# include "libft_printf/libft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx_opengl_20191021/mlx.h"
# define WIDTH 1600
# define HEIGHT 900
# define TITLE "<cub3D> - <made by Eduard Hosu and Rene Kaufmann>"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16384
# endif
# define XK_ESC 0x35
# define XK_X 0x07
# define XK_C 0x08
# define XK_PLUS 69
# define XK_PLUS2 30
# define XK_MINUS 78
# define XK_MINUS2 44
# define XK_LEFT 123
# define XK_RIGHT 124
# define XK_UP 126
# define XK_DOWN 125
# define XK_A 0
# define XK_D 2
# define XK_S 1
# define XK_W 13
# define XK_Q 12
# define XK_E 14
# define XK_I 34
# define XK_P 35
# define XK_F 3
# define XK_V 9
# define XK_HOME 115
# define DISTANCE 20
# define FOV	60.0
# define STEP_ANGLE 0.1
# define ROT_MULTI 2
# define MOV_MULTI 5
# define ROT_STEP 6.0

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
	int					max_line_h;
	int					max_rays;
	int					max_line_w;
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
	int					map_tile_size;
	struct s_2d_point	offset;
}				t_map;

typedef struct s_algo {
	int			*primary;
	int			*secondary;
	int			*primary_next;
	int			*secondary_next;
	int			*primary_end;
}				t_algo;

typedef struct s_ray_hit {
	double		x;
	double		y;
	double		dist;
}				t_ray_hit;

typedef struct s_ray {
	double				angle;
	double				x;
	double				y;
	double				step_x;
	double				step_y;
	double				dist;
	int					step_dist;
	int					map_x;
	int					map_y;
	struct s_ray_hit	hori;
	struct s_ray_hit	vert;
}				t_ray;

typedef struct s_3d_line_calc {
	double			angle;
	double			line_h;
	double			line_step;
	double			line_off;
	double			line_o;
	double			tx;
	double			ty;
	struct s_data	*texture;
}				t_3d_line_calc;

typedef struct s_3d_data {
	struct s_ray			ray;
	struct s_3d_line_calc	cam;
	struct s_line			line;
	int						i;
}				t_3d_data;

//ft_error0.c
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
int				ft_error_border(char c, int row, int column, t_map *map);
int				ft_error_player(char c, int row, int column, t_map *map);
int				ft_error_no_player(t_map *map);

//ft_error2.c
int				ft_error_map_file(char *s, int row, t_map *map);

//ft_error_map.c
void			ft_error_input(t_map *screen, char **string_array);
void			ft_error_map(t_map *screen, char **string_array);
void			ft_error_map_row(t_map *screen, char **string_array,
					int i_row);

//ft_memory_map0.c
void			ft_allocate_mem_map(t_map *screen, char **string_array);
void			ft_free_map(t_map *screen);
void			ft_check_map_exit_on_error(t_map *map);
void			ft_check_map_borders(t_map *map);
void			ft_check_map_open(t_map *map);

//ft_memory_map1.c
void			ft_check_for_player_on_map(t_map *map);
void			ft_player_on_map(t_map *map, int i_row,
					int i_column, int *player);

//ft_engine0.c
void			ft_engine_init(t_engine *engine);
int				ft_engine_destroy(t_engine *engine);

//ft_engine1.c
void			ft_error_engine_init(char *function, char *variable,
					t_engine *engine, int error);

//ft_string.c
int				ft_valid_number(char *argv);
int				ft_check_number(char *s);
int				ft_check_number_rgb(char *s);

//ft_check_input_map0.c
void			ft_check_input_exit_on_error(t_map *screen, char **input);
int				ft_check_identifiers_in_file(t_map *map, char **input);
int				ft_check_around(char **input, int r, int c);

//ft_check_input_map1.c
size_t			ft_count_of_columns(char *s, char c);
int				ft_is_empty_space(char c);
int				ft_is_player(char c);
int				ft_valid_char(char *argv, int row);

//ft_file.c
t_map			*ft_read_input_map(char *file);

//ft_map_array.c
void			ft_init_struct_t_map(t_map *map);
void			ft_create_map_array(char *input, t_map *screen);
void			ft_get_point(t_engine *engine, int row, int column,
					t_3d_point *point);
int				ft_check_all_map_identifier(t_map *screen);
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
void			ft_set_line_color(t_line *line, int color);

//ft_pixel.c
void			ft_put_pixel(t_data *data, int x, int y, int color);
int				ft_get_pixel(t_data *data, int x, int y);

//ft_color.c
int				ft_get_color(t_line *line);
double			ft_get_percentage(int start, int end, int pos);
int				ft_get_rgb(int start, int end, double percentage);
int				ft_get_rgb_color(char *s);

//ft_math.c
unsigned int	ft_abs(int number);
double			ft_dist(t_player *player, double rx, double ry);
double			ft_fix_angle(double a);
double			ft_deg_to_rad(double d);

//ft_key0.c
int				ft_key(int keycode, t_engine *engine);
void			ft_key_player_movement(int keycode, t_engine *engine);
void			ft_key_player_rotation(int key, t_engine *engine);

//ft_key1.c
int				ft_key_pressed(int keycode, t_engine *engine);
int				ft_key_released(int keycode, t_engine *engine);
void			ft_key_player_move_pressed(int keycode, t_engine *engine);
void			ft_key_player_move_released(int keycode, t_engine *engine);
void			ft_key_player_move(t_engine *engine);

//ft_key2.c
void			ft_key_player_rotate_pressed(int keycode, t_engine *engine);
void			ft_key_player_rotate_released(int keycode, t_engine *engine);
void			ft_key_player_rotate(t_engine *engine);

//ft_grafic.c
int				ft_render_frame(t_engine *engine);
void			ft_clear_image(t_engine *engine);

//ft_overview_bonus.c
void			ft_draw_map(t_engine *engine);
void			ft_draw_player(t_engine *engine);

//ft_display_info.c
void			ft_display_info(t_engine *engine);

//ft_player.c
void			ft_check_player_area(t_engine *engine);

//ft_raycasting0.c
void			ft_cast_3d_ray(t_engine *engine);
void			ft_invalid_angle(t_ray *ray, t_player *player);
t_ray_hit		ft_ray_hit(t_ray *ray, t_player *player, t_map *screen);
t_ray_hit		ft_ray_hit_area(t_ray *ray, t_player *player);

//ft_raycasting1.c
void			ft_prepare_ray(t_engine *engine, t_ray *ray);
void			ft_draw_ray(t_engine *engine, t_3d_data *data);
void			ft_select_shortest_ray(t_3d_data *data);
void			ft_prepare_cam(t_engine *engine, t_3d_data *data);

//ft_horizontal_ray.c
void			ft_cast_horizontal_ray(t_engine *engine, t_ray *ray);

//ft_vertical_ray.c
void			ft_cast_vertical_ray(t_engine *engine, t_ray *ray);

//ft_background.c
void			ft_draw_background(t_engine *engine);

//ft_texture.c
void			ft_select_texture(t_engine *engine, t_3d_data *data);
void			ft_draw_texture(t_engine *engine, t_3d_data *data);

#endif