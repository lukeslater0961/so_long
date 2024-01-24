/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:02:08 by lslater           #+#    #+#             */
/*   Updated: 2024/01/20 15:56:05 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_type(char *file, t_data *data)
{
	int			i;

	i = ft_strlen(file) - 1;
	if (i < 4)
	{
		ft_printf("Error\ninvalid file name or extension\n");
		data->file_type_error = 1;
		return (0);
	}
	if (file[i] == 'r' && file[i - 1] == 'e' && \
		file[i - 2] == 'b' && file[i - 3] == '.')
		return (1);
	else
	{
		ft_printf("Error\ninvalid file name or extension\n");
		data->file_type_error = 1;
		return (0);
	}
}

void	ft_free_tab(char **s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}

int	check_functions(t_data *data)
{
	int	status;

	status = 0;
	status += line_check(data);
	status += check_borders(data);
	status += objs_check(data);
	if (status < 3)
	{
		ft_printf("Error\nIncorrect map.\n");
		ft_free_tab(data->flooded_map);
		return (0);
	}
	map_flood(data, data->player_pos_y, data->player_pos_x);
	if (flood_check(data) == 0)
	{
		ft_printf("Error\nIncorrect map.\n");
		ft_free_tab(data->flooded_map);
		return (0);
	}
	return (1);
}

int	check_map(t_data *data)
{
	data->column_count = ft_strlen(*data->map) - 1;
	if ((data->column_count == 0 || data->line_count == 0) || \
		((data->column_count * data->line_count - 1) < 12))
	{
		ft_printf("Error\nmap empty or too small\n");
		ft_free_tab(data->flooded_map);
		return (0);
	}
	if (check_functions(data) == 0)
		return (0);
	return (1);
}
