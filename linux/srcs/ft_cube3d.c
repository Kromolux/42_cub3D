/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:50:26 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:50:57 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	ft_init_cub3d(t_engine *engine);
void		ft_print_map_to_terminal(t_map *map);

	//mlx_hook(cub3d.window, 2, (1L << 0), &ft_key_pressed, &cub3d);
	//mlx_hook(cub3d.window, 3, (1L << 1), &ft_key_released, &cub3d);

int	main(int argc, char **argv)
{
	t_engine	cub3d;

	ft_init_cub3d(&cub3d);
	if (argc != 2)
		return (ft_error_arguments());
	cub3d.screen = ft_read_input_map(argv[1]);
	ft_engine_init(&cub3d);
	cub3d.file = (char *) malloc(ft_strlen(argv[1]) + 1);
	if (!cub3d.file)
		return (ft_error_malloc("main", "cub.file", ft_strlen(argv[1]) + 1));
	ft_copy(cub3d.file, argv[1], 0);
	mlx_hook(cub3d.window, 17, 0, &ft_engine_destroy, &cub3d);
	mlx_hook(cub3d.window, 2, (1L << 0), &ft_key, &cub3d);
	mlx_loop_hook(cub3d.mlx, &ft_render_frame, &cub3d);
	mlx_loop(cub3d.mlx);
}

static void	ft_init_cub3d(t_engine *engine)
{
	engine->mlx = NULL;
	engine->window = NULL;
	ft_memset((void *) &engine->img0, '\0', sizeof(engine->img0));
	ft_memset((void *) &engine->img1, '\0', sizeof(engine->img1));
	ft_memset((void *) &engine->no_tex, '\0', sizeof(engine->no_tex));
	ft_memset((void *) &engine->no_tex, '\0', sizeof(engine->so_tex));
	ft_memset((void *) &engine->no_tex, '\0', sizeof(engine->we_tex));
	ft_memset((void *) &engine->no_tex, '\0', sizeof(engine->ea_tex));
	engine->img = NULL;
	engine->file = NULL;
	engine->screen = NULL;
	engine->offset.x = 0;
	engine->offset.y = 0;
	engine->max_line_h = 640;
	engine->max_rays = (int)(FOV / STEP_ANGLE);
	engine->max_line_w = (engine->max_rays * 2) - 1;
}

//DEBUG
void	ft_print_map_to_terminal(t_map *map)
{
	int	y;
	int	x;

	ft_printf("created map with rows=%i columns=%i\n", map->rows, map->columns);
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			write(1, &map->map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
