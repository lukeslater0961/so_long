/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:55:08 by lslater           #+#    #+#             */
/*   Updated: 2024/01/21 14:39:05 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_Printf/ft_printf.h"
# include "MacroLibX/includes/mlx.h"

typedef struct s_data
{
	char	**map;
	char	**flooded_map;
	int		move_count;
	int		line_count;
	int		column_count;
	int		player_c;
	int		exit_c;
	int		collectible_c;
	int		wall_c;
	int		player_pos_y;
	int		player_pos_x;
	int		theme;
	int		theme_status;
	char	*yuji_sprite;
	char	*gojo_sprite;
	int		file_type_error;
}	t_data;

typedef struct s_sprites
{
	char	*player;
	char	*wall;
	char	*collectible;
	char	*exit;
	char	*theme_t;
	char	*yuji_select;
	char	*gojo_select;
}	t_sprites;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*win2;
	t_sprites	*sprites;
	t_data		*data;
}	t_mlx;

int		keyboard_hook(int keycode, void *param);
int		window_hook(int event, void *param);
int		set_map(t_data *data, t_mlx *mlx, char *file);
void	ft_free_tab(char **s1);
int		check_map(t_data *data);
int		check_borders(t_data *data);
int		left_side(t_data *data);
int		right_side(t_data *data);
int		top_bot(t_data *data);
int		objs_check(t_data *data);
void	map_flood(t_data *data, int y, int x);
int		flood_check(t_data *data);
int		line_check(t_data *data);
int		file_type(char *file, t_data *data);
void	create_map(t_data *data, t_mlx *mlx);
int		theme_selector(t_data *data, t_mlx *mlx);
void	clear_t_window(t_mlx *mlx);
void	move_up(t_data *data, t_mlx *mlx);
void	move_right(t_data *data, t_mlx *mlx);
void	move_left(t_data *data, t_mlx *mlx);
void	move_down(t_data *data, t_mlx *mlx);
#endif
