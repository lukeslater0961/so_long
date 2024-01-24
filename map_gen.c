/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:09:23 by lslater           #+#    #+#             */
/*   Updated: 2024/01/16 15:18:43 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_items(t_data *data, t_mlx *mlx, int y, int x)
{
	int		w;
	int		h;

	if (data->map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->wall, x * 32, \
			y * 32);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->collectible, \
			x * 32, y * 32);
	else if (data->map[y][x] == 'E')
	{
		mlx->sprites->exit = mlx_png_file_to_image(mlx->mlx, \
			"sprites/sukuna_exit.png", &w, &h);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->exit, x * 32, \
			y * 32);
	}
}

void	set_sprites(t_data *data, t_mlx *mlx, int w, int h)
{
	int			y;
	int			x;

	y = 0;
	x = 0;
	mlx->sprites->wall = mlx_png_file_to_image(mlx->mlx, \
		"sprites/wall.png", &w, &h);
	if (data->theme == 1)
		mlx->sprites->collectible = mlx_png_file_to_image(mlx->mlx, \
			"sprite_yuji/sukuna_finger.png", &w, &h);
	else if (data->theme == 2)
		mlx->sprites->collectible = mlx_png_file_to_image(mlx->mlx, \
			"sprite_gojo/candy.png", &w, &h);
	while (y <= data->line_count - 1)
	{
		x = 0;
		while (x <= data->column_count)
		{
			put_items(data, mlx, y, x);
			x++;
		}
		y++;
	}
}

void	create_map(t_data *data, t_mlx *mlx)
{
	int		w;
	int		h;
	char	*text;

	text = ft_itoa(data->move_count);
	mlx_string_put(mlx->mlx, mlx->win, 8, 20, 0x00FFFFFF, text);
	free(text);
	if (data->theme == 1)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->yuji_sprite, &w, &h);
	if (data->theme == 2)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->gojo_sprite, &w, &h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->player, \
		data->player_pos_x * 32, data->player_pos_y * 32);
	set_sprites(data, mlx, w, h);
}
