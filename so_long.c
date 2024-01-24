/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:38:10 by lslater           #+#    #+#             */
/*   Updated: 2024/01/23 13:26:27 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_theme_s(t_mlx *mlx)
{
	t_data	*data;

	data = mlx->data;
	mlx_loop_end(mlx->mlx);
	mlx_destroy_image(mlx->mlx, mlx->sprites->gojo_select);
	mlx_destroy_image(mlx->mlx, mlx->sprites->yuji_select);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	ft_free_tab(data->map);
	ft_free_tab(data->flooded_map);
	free(mlx->sprites);
	free(data);
	free(mlx);
	exit(EXIT_SUCCESS);
}

void	e_exit(t_mlx *mlx, t_data *data)
{
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	if (data->file_type_error == 0)
		ft_free_tab(data->map);
	free(mlx->sprites);
	free(data);
	free(mlx);
}

int	window_hook(int event, void *param)
{
	t_mlx		*mlx;
	t_data		*data;

	mlx = (t_mlx *) param;
	data = mlx->data;
	if (event == 0 && data->theme_status == 0)
	{
		mlx_loop_end(mlx->mlx);
		mlx_destroy_image(mlx->mlx, mlx->sprites->player);
		mlx_destroy_image(mlx->mlx, mlx->sprites->wall);
		mlx_destroy_image(mlx->mlx, mlx->sprites->exit);
		mlx_destroy_image(mlx->mlx, mlx->sprites->collectible);
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		ft_free_tab(data->map);
		ft_free_tab(data->flooded_map);
		free(mlx->sprites);
		free(data);
		free(mlx);
		exit(EXIT_SUCCESS);
	}
	if (event == 0 && data->theme_status == 1)
		destroy_theme_s(mlx);
	return (0);
}

int	setup(t_data *data, t_mlx *mlx, char **argv)
{
	data->move_count = 0;
	data->file_type_error = 0;
	if (set_map(data, mlx, argv[1]) == 0)
	{
		e_exit(mlx, data);
		return (0);
	}
	mlx->mlx = mlx_init();
	theme_selector(data, mlx);
	mlx_on_event(mlx->mlx, mlx->win, 5, window_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, 0, keyboard_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_data		*data;

	if (argc != 2)
	{
		ft_printf("Error\nNo map file or too many instructions\n");
		exit(EXIT_FAILURE);
	}
	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		free(mlx);
		return (0);
	}
	mlx->sprites = malloc(sizeof(t_sprites));
	if (!mlx->sprites)
	{
		free(mlx);
		free(data);
		return (0);
	}
	setup(data, mlx, argv);
}
