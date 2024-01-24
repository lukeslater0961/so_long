/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:26:36 by lslater           #+#    #+#             */
/*   Updated: 2024/01/21 15:20:48 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_t_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->sprites->gojo_select);
	mlx_destroy_image(mlx->mlx, mlx->sprites->yuji_select);
	mlx_clear_window(mlx->mlx, mlx->win);
}

void	gen_gojo(t_mlx *mlx, t_data *data)
{
	int	h;
	int	w;

	mlx->sprites->gojo_select = mlx_png_file_to_image(mlx->mlx, \
		"sprite_gojo/gojo_big.png", &w, &h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->gojo_select, \
		(data->column_count * 32) - 150, (data->line_count / 2) + 50);
}

void	gen_yuji(t_mlx *mlx, t_data *data)
{
	int	h;
	int	w;

	mlx->sprites->yuji_select = mlx_png_file_to_image(mlx->mlx, \
		"sprite_yuji/yuji_big.png", &w, &h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->yuji_select, \
		data->column_count, (data->line_count / 2) + 50);
}

void	gen_sprites(t_mlx *mlx, t_data *data)
{
	int	h;
	int	w;

	if ((data->column_count * data->line_count) >= 56)
	{
		gen_yuji(mlx, data);
		gen_gojo(mlx, data);
	}
	else
	{
		mlx->sprites->gojo_select = mlx_png_file_to_image(mlx->mlx, \
			data->gojo_sprite, &w, &h);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->gojo_select, \
			(data->column_count * 25), (data->line_count / 2));
		mlx->sprites->yuji_select = mlx_png_file_to_image(mlx->mlx, \
			data->yuji_sprite, &w, &h);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->yuji_select, \
			data->column_count, (data->line_count / 2));
	}
}

int	theme_selector(t_data *data, t_mlx *mlx)
{
	data->theme_status = 1;
	mlx->win = mlx_new_window(mlx->mlx, data->column_count * 32, \
		data->line_count * 32, "ルークのゲーム");
	gen_sprites(mlx, data);
	return (1);
}
