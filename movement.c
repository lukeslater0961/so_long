/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:06:03 by lslater           #+#    #+#             */
/*   Updated: 2024/01/21 15:50:27 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset(t_data *data, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->sprites->player);
	mlx_destroy_image(mlx->mlx, mlx->sprites->wall);
	mlx_destroy_image(mlx->mlx, mlx->sprites->exit);
	mlx_destroy_image(mlx->mlx, mlx->sprites->collectible);
	mlx_clear_window(mlx->mlx, mlx->win);
	create_map(data, mlx);
}

void	move_left(t_data *data, t_mlx *mlx)
{
	int	w;
	int	h;

	if (data->map[data->player_pos_y][data->player_pos_x - 1] == 'C')
	{
		data->collectible_c--;
		data->map[data->player_pos_y][data->player_pos_x - 1] = '0';
	}
	if (data->collectible_c == 0 && data->map[data->player_pos_y] \
		[data->player_pos_x - 1] == 'E')
		window_hook(0, mlx);
	if (data->map[data->player_pos_y][data->player_pos_x - 1] != '1')
		data->move_count++;
	ft_printf("move count = %d\n", data->move_count);
	data->player_pos_x--;
	reset(data, mlx);
	mlx_destroy_image(mlx->mlx, mlx->sprites->player);
	if (data->theme == 1)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->yuji_sprite, &w, &h);
	if (data->theme == 2)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->gojo_sprite, &w, &h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->player, \
		data->player_pos_x * 32, data->player_pos_y * 32);
}

void	move_right(t_data *data, t_mlx *mlx)
{
	int	w;
	int	h;

	if (data->map[data->player_pos_y][data->player_pos_x + 1] == 'C')
	{
		data->collectible_c--;
		data->map[data->player_pos_y][data->player_pos_x + 1] = '0';
	}
	if (data->collectible_c == 0 && data->map[data->player_pos_y] \
		[data->player_pos_x + 1] == 'E')
		window_hook(0, mlx);
	if (data->map[data->player_pos_y][data->player_pos_x + 1] != '1')
		data->move_count++;
	ft_printf("move count = %d\n", data->move_count);
	data->player_pos_x++;
	reset(data, mlx);
	mlx_destroy_image(mlx->mlx, mlx->sprites->player);
	if (data->theme == 1)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->yuji_sprite, &w, &h);
	if (data->theme == 2)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->gojo_sprite, &w, &h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->player, \
		data->player_pos_x * 32, data->player_pos_y * 32);
}

void	move_up(t_data *data, t_mlx *mlx)
{
	int	w;
	int	h;

	if (data->map[data->player_pos_y - 1][data->player_pos_x] == 'C')
	{
		data->collectible_c--;
		data->map[data->player_pos_y - 1][data->player_pos_x] = '0';
	}
	if (data->collectible_c == 0 && data->map[data->player_pos_y - 1] \
		[data->player_pos_x] == 'E')
		window_hook(0, mlx);
	if (data->map[data->player_pos_y - 1][data->player_pos_x] != '1')
		data->move_count++;
	ft_printf("move count = %d\n", data->move_count);
	data->player_pos_y--;
	reset(data, mlx);
	mlx_destroy_image(mlx->mlx, mlx->sprites->player);
	if (data->theme == 1)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->yuji_sprite, &w, &h);
	if (data->theme == 2)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->gojo_sprite, &w, &h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->player, \
		data->player_pos_x * 32, data->player_pos_y * 32);
}

void	move_down(t_data *data, t_mlx *mlx)
{
	int	w;
	int	h;

	if (data->map[data->player_pos_y + 1][data->player_pos_x] == 'C')
	{
		data->collectible_c--;
		data->map[data->player_pos_y + 1][data->player_pos_x] = '0';
	}
	if (data->collectible_c == 0 && data->map[data->player_pos_y + 1] \
		[data->player_pos_x] == 'E')
		window_hook(0, mlx);
	if (data->map[data->player_pos_y + 1][data->player_pos_x] != '1')
		data->move_count++;
	ft_printf("move count = %d\n", data->move_count);
	data->player_pos_y++;
	reset(data, mlx);
	mlx_destroy_image(mlx->mlx, mlx->sprites->player);
	if (data->theme == 1)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->yuji_sprite, &w, &h);
	if (data->theme == 2)
		mlx->sprites->player = mlx_png_file_to_image(mlx->mlx, \
			data->gojo_sprite, &w, &h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites->player, \
		data->player_pos_x * 32, data->player_pos_y * 32);
}
