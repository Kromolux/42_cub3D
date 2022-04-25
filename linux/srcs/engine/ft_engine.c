/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:14 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 09:46:16 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_error_engine_init(char *function, char *variable,
				t_engine *engine, int error);

void	ft_engine_init(t_engine *engine)
{
	engine->mlx = mlx_init();
	if (!engine->mlx)
		ft_error_engine_init("mlx_init", "engine->mlx", engine, 0);
	engine->window = mlx_new_window(engine->mlx, WIDTH, HEIGHT, TITLE);
	if (!engine->window)
		ft_error_engine_init("mlx_new_window", "engine->window", engine, 1);
	engine->img0.img = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	if (!engine->img0.img)
		ft_error_engine_init("mlx_new_image", "engine->img0.img", engine, 2);
	engine->img0.addr = mlx_get_data_addr(engine->img0.img,
			&engine->img0.bits_per_pixel, &engine->img0.line_length,
			&engine->img0.endian);
	if (!engine->img0.addr)
		ft_error_engine_init("mlx_get_data_addr", "engine->img0.addr",
			engine, 3);
	engine->img1.img = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	if (!engine->img1.img)
		ft_error_engine_init("mlx_new_image", "engine->img1.img", engine, 4);
	engine->img1.addr = mlx_get_data_addr(engine->img1.img,
			&engine->img1.bits_per_pixel, &engine->img1.line_length,
			&engine->img1.endian);
	if (!engine->img1.addr)
		ft_error_engine_init("mlx_get_data_addr", "engine->img1.addr",
			engine, 5);
	engine->img = &engine->img0;
}

int	ft_engine_destroy(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->img0.img);
	mlx_destroy_image(engine->mlx, engine->img1.img);
	mlx_destroy_window(engine->mlx, engine->window);
	mlx_destroy_display(engine->mlx);
	free(engine->mlx);
	ft_free_map(engine->screen);
	free(engine->file);
	exit(1);
}

static void	ft_error_engine_init(char *function, char *variable,
	t_engine *engine, int error)
{
	ft_printf("Error! Could not initalize %s by function: %s\n",
		variable, function);
	if (error >= 5)
		mlx_destroy_image(engine->mlx, engine->img1.img);
	if (error >= 3)
		mlx_destroy_image(engine->mlx, engine->img0.img);
	if (error >= 2)
		mlx_destroy_window(engine->mlx, engine->window);
	if (error >= 1)
	{
		mlx_destroy_display(engine->mlx);
		free(engine->mlx);
	}
	ft_free_map(engine->screen);
	free(engine->file);
	exit(1);
}
