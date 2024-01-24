/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:26:53 by lslater           #+#    #+#             */
/*   Updated: 2024/01/23 13:28:44 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fd_error(t_data *data)
{
	data->file_type_error = 1;
	ft_printf("Error\ncouldn't open file\n");
	return (0);
}

int	count_lines(char *file)
{
	int		fd;
	int		lines_c;
	char	*line;

	lines_c = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		lines_c++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (lines_c);
}

int	map_to_c_setup(t_data *data, char *file, int fd)
{
	if (fd <= 0)
		return (fd_error(data));
	data->line_count = count_lines(file);
	data->map = malloc(sizeof(char *) * (data->line_count + 1));
	data->flooded_map = malloc(sizeof(char *) * (data->line_count + 1));
	if (!data->map || !data->flooded_map)
		return (0);
	return (1);
}

int	map_to_c(t_data *data, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	map_to_c_setup(data, file, fd);
	i = 0;
	while (i < data->line_count)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line != '\n')
			data->map[i] = ft_strdup(line);
		if (*line != '\n')
			data->flooded_map[i++] = ft_strdup(line);
		free(line);
	}
	free(get_next_line(fd));
	data->line_count = i;
	data->map[i] = NULL;
	data->flooded_map[i] = NULL;
	close(fd);
	return (1);
}

int	set_map(t_data *data, t_mlx *mlx, char *file)
{
	mlx->data = data;
	if (file_type(file, data) == 0 || map_to_c(data, file) == 0 \
		|| check_map(data) == 0)
		return (0);
	data->gojo_sprite = "sprite_gojo/gojo.png";
	data->yuji_sprite = "sprite_yuji/yuji.png";
	data->map[data->player_pos_y][data->player_pos_x] = '0';
	return (1);
}
