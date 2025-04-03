/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:48:19 by jrichir           #+#    #+#             */
/*   Updated: 2025/04/03 12:40:50 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

static int	create_window(t_info *infos)
{
	infos->windw = mlx_new_window(infos->mlx, WIN_W, WIN_H, NAME);
	if (!(infos->windw))
		free_print_exit_error("mlx_new_window() failed", infos);
	return (0);
}

int	on_destroy(t_info *infos)
{
	ft_free(infos);
	exit(0);
}

int	start_rendering(t_info *infos)
{
	infos->mlx = mlx_init();
	infos->frame = 0;
	if (infos->mlx == NULL)
		free_print_exit_error("mlx_init() failed.", infos);
	create_window(infos);
	load_textures(infos, TXSIZE);
	set_textures(infos);
	set_mlx_screen_img(infos);
	raycast(infos, NULL);
	mlx_mouse_move(infos->mlx, infos->windw, WIN_W / 2, WIN_H / 2);
	mlx_mouse_hide(infos->mlx, infos->windw);
	mlx_hook(infos->windw, ON_DESTROY, 0, &on_destroy, infos);
	mlx_hook(infos->windw, MOUSE_MOVE, (1L << 6), &mouse_moved, infos);
	mlx_hook(infos->windw, ON_KEYRELEASE, 1L << 1, &on_keyrelease, infos);
	mlx_hook(infos->windw, ON_KEYPRESS, 1L << 0, &on_keypress, infos);
	mlx_loop_hook(infos->mlx, &move_player, infos);
	mlx_loop(infos->mlx);
	return (0);
}
