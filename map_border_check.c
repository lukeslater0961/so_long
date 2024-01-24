/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:00 by lslater           #+#    #+#             */
/*   Updated: 2024/01/18 11:31:27 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	top_bot(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= data->line_count - 1)
	{
		x = 0;
		while (x < data->column_count)
		{
			if (data->map[y][x] == '1' && (y == 0 || y == data->line_count - 1))
				x++;
			else
				return (0);
		}
		y += data->line_count - 1;
	}
	return (1);
}

int	right_side(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= data->line_count - 1)
	{
		x = 0;
		if (data->map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	left_side(t_data *data)
{
	int	x;
	int	y;

	x = data->column_count;
	y = 0;
	while (y <= data->line_count - 1)
	{
		x = 0;
		if (data->map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_borders(t_data *data)
{
	if (top_bot(data) == 0)
		return (0);
	if (left_side(data) == 0 || right_side(data) == 0)
		return (0);
	return (1);
}
