/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:46:39 by lslater           #+#    #+#             */
/*   Updated: 2024/01/20 15:59:26 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	objs_type(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'P')
	{
		data->player_pos_x = x;
		data->player_pos_y = y;
		data->player_c++;
	}
	if (data->map[y][x] == 'E')
		data->exit_c++;
	if (data->map[y][x] == 'C')
		data->collectible_c++;
	if (data->map[y][x] == '1')
		data->wall_c++;
	return (1);
}

int	objs_check(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->line_count - 1)
	{
		x = 0;
		while (x <= data->column_count)
		{
			if (data->map[y][x] != '0' && data->map[y][x] != '1' && \
				data->map[y][x] != 'P' && data->map[y][x] != 'E' && \
				data->map[y][x] != 'C' && data->map[y][x] != '\n')
				return (0);
			objs_type(x, y, data);
			x++;
		}
		y++;
	}
	if (data->exit_c != 1 || data->player_c != 1 || data->collectible_c < 1)
		return (0);
	return (1);
}

int	last_line(char *line, int line_length, int column_count)
{
	if (line_length == column_count && line[line_length] == '\n')
		return (0);
	if (line_length == column_count - 1 && line[line_length + 1] != '\n')
		return (0);
	return (1);
}

int	line_check(t_data *data)
{
	int	y;
	int	line_length;

	line_length = 0;
	y = 0;
	while (y <= data->line_count - 1)
	{
		line_length = ft_strlen(data->map[y]) - 1;
		if ((line_length != data->column_count && y != data->line_count - 1) || \
			(y == data->line_count - 1 && last_line(data->map[y], line_length, \
			data->column_count)))
			return (0);
		y++;
	}
	return (1);
}

int	flood_check(t_data *data)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	x = 0;
	c = 0;
	while (y <= data->line_count - 1)
	{
		x = 0;
		while (x <= data->column_count - 2)
		{
			if (data->flooded_map[y][x] == 'C')
				c++;
			if (data->flooded_map[y][x] == 'E')
				return (0);
			if (data->flooded_map[y][x] == 'P')
				return (0);
			x++;
		}
		y++;
	}
	if (c != 0)
		return (0);
	return (1);
}
