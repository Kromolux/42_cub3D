/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:14 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/29 10:15:59 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_error_engine_init(char *function, char *variable,
				t_engine *engine, int error);
static int	ft_load_texture(t_engine *engine, char *file, t_data *texture);

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
	if (ft_load_texture(engine, engine->screen->texture_no, &engine->no_tex) == RETURN_ERROR)
		ft_error_engine_init("ft_load_texture", "texture_no", engine, 6);
	if (ft_load_texture(engine, engine->screen->texture_we, &engine->we_tex) == RETURN_ERROR)
		ft_error_engine_init("ft_load_texture", "texture_we", engine, 7);
	if (ft_load_texture(engine, engine->screen->texture_ea, &engine->ea_tex) == RETURN_ERROR)
		ft_error_engine_init("ft_load_texture", "texture_ea", engine, 8);
	if (ft_load_texture(engine, engine->screen->texture_so, &engine->so_tex) == RETURN_ERROR)
		ft_error_engine_init("ft_load_texture", "texture_so", engine, 9);
	//engine->we_tex.img = mlx_xpm_file_to_image(engine->mlx, engine->screen->texture_we,
	//	&engine->we_tex.width, &engine->we_tex.height);
	//engine->we_tex.addr = mlx_get_data_addr(engine->we_tex.img, &engine->we_tex.bits_per_pixel,
	//	&engine->we_tex.line_length, &engine->we_tex.endian);
}

static int	ft_load_texture(t_engine *engine, char *file, t_data *texture)
{
	texture->img = mlx_xpm_file_to_image(engine->mlx, file,
		&texture->width, &texture->height);
	if (!texture->img)
		return (RETURN_ERROR);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
		&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		mlx_destroy_image(engine->mlx, texture->img);
		return (RETURN_ERROR);
	}
	return (RETURN_SUCCESS);
}

int	ft_engine_destroy(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->img0.img);
	mlx_destroy_image(engine->mlx, engine->img1.img);
	mlx_destroy_image(engine->mlx, engine->no_tex.img);
	mlx_destroy_image(engine->mlx, engine->we_tex.img);
	mlx_destroy_image(engine->mlx, engine->so_tex.img);
	mlx_destroy_image(engine->mlx, engine->ea_tex.img);
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
	if (error >= 10)
		mlx_destroy_image(engine->mlx, engine->so_tex.img);
	if (error >= 9)
		mlx_destroy_image(engine->mlx, engine->ea_tex.img);
	if (error >= 8)
		mlx_destroy_image(engine->mlx, engine->we_tex.img);
	if (error >= 7)
		mlx_destroy_image(engine->mlx, engine->no_tex.img);
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
	exit(RETURN_ERROR);
}
