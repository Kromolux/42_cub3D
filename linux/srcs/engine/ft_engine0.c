/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:46:14 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/03 08:45:59 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_engine_init_image(t_engine *engine);
static int	ft_load_image(t_engine *engine, t_data *new_i);
static void	ft_engine_init_texture(t_engine *engine);
static int	ft_load_texture(t_engine *engine, char *file, t_data *texture);

void	ft_engine_init(t_engine *engine)
{
	engine->mlx = mlx_init();
	if (!engine->mlx)
		ft_error_engine_init("mlx_init", "engine->mlx", engine, 0);
	engine->window = mlx_new_window(engine->mlx, WIDTH, HEIGHT, TITLE);
	if (!engine->window)
		ft_error_engine_init("mlx_new_window", "engine->window", engine, 1);
	ft_engine_init_image(engine);
	ft_engine_init_texture(engine);
}

static void	ft_engine_init_image(t_engine *engine)
{
	if (ft_load_image(engine, &engine->img0) == RETURN_ERROR)
		ft_error_engine_init("mlx_new_image", "engine->img0", engine, 2);
	if (ft_load_image(engine, &engine->img1) == RETURN_ERROR)
		ft_error_engine_init("mlx_new_image", "engine->img1", engine, 4);
	engine->img = &engine->img0;
}

static int	ft_load_image(t_engine *engine, t_data *new_i)
{
	new_i->img = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	if (!new_i->img)
		return (RETURN_ERROR);
	new_i->addr = mlx_get_data_addr(new_i->img, &new_i->bits_per_pixel,
			&new_i->line_length, &new_i->endian);
	if (!new_i->addr)
	{
		mlx_destroy_image(engine->mlx, new_i->img);
		return (RETURN_ERROR);
	}
	return (RETURN_SUCCESS);
}

static void	ft_engine_init_texture(t_engine *engine)
{
	if (ft_load_texture(engine, engine->screen->texture_no, &engine->no_tex)
		== RETURN_ERROR)
		ft_error_engine_init("ft_load_texture", "texture_no", engine, 6);
	if (ft_load_texture(engine, engine->screen->texture_we, &engine->we_tex)
		== RETURN_ERROR)
		ft_error_engine_init("ft_load_texture", "texture_we", engine, 7);
	if (ft_load_texture(engine, engine->screen->texture_ea, &engine->ea_tex)
		== RETURN_ERROR)
		ft_error_engine_init("ft_load_texture", "texture_ea", engine, 8);
	if (ft_load_texture(engine, engine->screen->texture_so, &engine->so_tex)
		== RETURN_ERROR)
		ft_error_engine_init("ft_load_texture", "texture_so", engine, 9);
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
