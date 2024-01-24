/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:15:03 by lslater           #+#    #+#             */
/*   Updated: 2024/01/20 15:21:01 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_codes(t_data *data, t_mlx *mlx, int keycode)
{
	if (keycode == 4 && (data->map[data->player_pos_y][data->player_pos_x - 1] \
		!= '1') && data->theme_status == 0)
		move_left(data, mlx);
	if (keycode == 7 && (data->map[data->player_pos_y][data->player_pos_x + 1] \
		!= '1') && data->theme_status == 0)
		move_right(data, mlx);
	if (keycode == 26 && (data->map[data->player_pos_y - 1][data->player_pos_x] \
		!= '1') && data->theme_status == 0)
		move_up(data, mlx);
	if (keycode == 22 && (data->map[data->player_pos_y + 1][data->player_pos_x] \
		!= '1') && data->theme_status == 0)
		move_down(data, mlx);
}

void	keycodes(t_data *data, t_mlx *mlx, int keycode)
{
	if (keycode == 30 && data->theme_status == 1)
	{
		data->theme = 1;
		data->theme_status = 0;
		clear_t_window(mlx);
		create_map(data, mlx);
	}
	if (keycode == 31 && data->theme_status == 1)
	{
		data->theme_status = 0;
		data->theme = 2;
		clear_t_window(mlx);
		create_map(data, mlx);
	}
	if (keycode == 4 || keycode == 7 || keycode == 26 || keycode == 22)
		movement_codes(data, mlx, keycode);
	if (keycode == 41)
		window_hook(0, mlx);
}

int	keyboard_hook(int keycode, void *param)
{
	t_mlx		*mlx;
	t_data		*data;

	mlx = (t_mlx *) param;
	data = mlx->data;
	keycodes(data, mlx, keycode);
	return (0);
}
