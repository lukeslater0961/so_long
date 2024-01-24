/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:36:14 by lslater           #+#    #+#             */
/*   Updated: 2024/01/10 11:42:37 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_flood(t_data *data, int y, int x)
{
	if (data->flooded_map[y][x] == '7')
		return ;
	data->flooded_map[y][x] = '7';
	if (y + 1 < data->line_count - 1 && data->flooded_map[y + 1][x] != '1')
		map_flood(data, y + 1, x);
	if (x + 1 < data->column_count - 1 && data->flooded_map[y][x + 1] != '1')
		map_flood(data, y, x + 1);
	if (y - 1 >= 1 && data->flooded_map[y - 1][x] != '1')
		map_flood(data, y - 1, x);
	if (x - 1 >= 1 && data->flooded_map[y][x - 1] != '1')
		map_flood(data, y, x - 1);
}
