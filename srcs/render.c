/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:48:19 by jrichir           #+#    #+#             */
/*   Updated: 2025/04/02 09:32:29 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	create_window(t_info *infos)
{
	infos->windw = mlx_new_window(infos->mlx, WIN_W, WIN_H, NAME);
	if (!(infos->windw))
		free_print_exit_error("mlx_new_window() failed", infos);
	return (0);
}

// static int	load_anim_textures(t_info *infos)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (infos->no_tx_nb > 1)
// 	{
// 		while (i < no_tx_nb)
// 		{
// 			infos->tx[0][i] = mlx_xpm_file_to_image(infos->mlx,
// 			infos->no_tx_path, &size, &size);
// 			i++;
// 		}
// 	}
// }

static int	load_textures(t_info *infos)
{
	int	size;

	size = TXSIZE;
	infos->tx[0] = mlx_xpm_file_to_image(infos->mlx,
			infos->no_tx_path, &size, &size);
	infos->tx[1] = mlx_xpm_file_to_image(infos->mlx,
			infos->so_tx_path, &size, &size);
	infos->tx[2] = mlx_xpm_file_to_image(infos->mlx,
			infos->we_tx_path, &size, &size);
	infos->tx[3] = mlx_xpm_file_to_image(infos->mlx,
			infos->ea_tx_path, &size, &size);
	infos->tx[4] = mlx_xpm_file_to_image(infos->mlx,
			"img/1.xpm", &size, &size);
	infos->tx[5] = mlx_xpm_file_to_image(infos->mlx,
			"img/2.xpm", &size, &size);
	if (!infos->tx[0] || !infos->tx[1] || !infos->tx[2] || !infos->tx[3])
		free_print_exit_error("Texture not found", infos);
	set_textures(infos);
	return (0);
}

int	put_img(t_info *infos, int id, int x, int y)
{
	if (mlx_put_image_to_window(infos->mlx, infos->windw, infos->tx[id] \
		, x, y) < 0)
		free_print_exit_error("mlx_put_image_to_window() failed.", infos);
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
	if (infos->mlx == NULL)
		free_print_exit_error("mlx_init() failed.", infos);
	create_window(infos);
	load_textures(infos);
	set_textures(infos);
	set_mlx_screen_img(infos);
	raycast(infos, NULL);
	mlx_mouse_move(infos->mlx, infos->windw, WIN_W / 2, WIN_H / 2);
	mlx_mouse_hide(infos->mlx, infos->windw);
	mlx_hook(infos->windw, ON_DESTROY, 0, &on_destroy, infos);
	mlx_hook(infos->windw, 6, (1L << 6), &mouse_moved, infos);
	mlx_hook(infos->windw, ON_KEYRELEASE, 1L << 1, &on_keyrelease, infos);
	mlx_hook(infos->windw, ON_KEYPRESS, 1L << 0, &on_keypress, infos);
	mlx_loop_hook(infos->mlx, &move_player, infos);
	mlx_loop(infos->mlx);
	return (0);
}
