/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:50:26 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/27 12:22:26 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	ft_init_cub3d(t_engine *engine);

int	main(int argc, char **argv)
{
	t_engine	cub3d;

	ft_init_cub3d(&cub3d);
	if (argc != 2)
		return (ft_error_arguments());
	cub3d.screen = ft_read_input_map(argv[1]);
	ft_printf("created map for cub3D with rows=%i columns=%i\n", cub3d.screen->rows, cub3d.screen->columns);
	int	y = 0;
	int x = 0;
	while (y < cub3d.screen->rows)
	{
		x = 0;
		while (x < cub3d.screen->columns)
		{
			write(1, &cub3d.screen->map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
	
	//exit(1);
	ft_engine_init(&cub3d);
	cub3d.file = (char *) malloc(ft_strlen(argv[1]) + 1);
	if (!cub3d.file)
	return (ft_error_malloc("main", "cub.file", ft_strlen(argv[1]) + 1));
	ft_copy(cub3d.file, argv[1], 0);
	mlx_hook(cub3d.window, 17, 0, &ft_engine_destroy, &cub3d);
	mlx_hook(cub3d.window, 2, (1L << 0), &ft_key, &cub3d);
	//mlx_hook(cub3d.window, 2, (1L << 0), &ft_key_pressed, &cub3d);
	//mlx_hook(cub3d.window, 3, (1L << 1), &ft_key_released, &cub3d);
	mlx_loop_hook(cub3d.mlx, &ft_render_frame, &cub3d);
	//mlx_do_key_autorepeaton(cub3d.mlx);
	//mlx_do_sync(cub3d.mlx);
	mlx_loop(cub3d.mlx);
}

static void	ft_init_cub3d(t_engine *engine)
{
	engine->mlx = NULL;
	engine->window = NULL;
	engine->img0.img = NULL;
	engine->img0.addr = NULL;
	engine->img0.bits_per_pixel = 0;
	engine->img0.line_length = 0;
	engine->img0.endian = 0;
	engine->img1.img = NULL;
	engine->img1.addr = NULL;
	engine->img1.bits_per_pixel = 0;
	engine->img1.line_length = 0;
	engine->img1.endian = 0;
	engine->img = NULL;
	engine->file = NULL;
	engine->screen = NULL;
}
