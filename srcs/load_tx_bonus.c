/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tx_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:05:24 by jrichir           #+#    #+#             */
/*   Updated: 2025/04/03 12:40:50 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

int	load_animation_tx1(t_info *infos, int size)
{
	infos->tx[5] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch01w10.xpm", &size, &size);
	infos->tx[6] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch02w10.xpm", &size, &size);
	infos->tx[7] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch03w10.xpm", &size, &size);
	infos->tx[8] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch04w10.xpm", &size, &size);
	infos->tx[9] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch05w10.xpm", &size, &size);
	infos->tx[10] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch06w10.xpm", &size, &size);
	infos->tx[11] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch07w10.xpm", &size, &size);
	infos->tx[12] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch08w10.xpm", &size, &size);
	infos->tx[13] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch09w10.xpm", &size, &size);
	infos->tx[14] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch10w10.xpm", &size, &size);
	return (0);
}

int	load_animation_tx2(t_info *infos, int size)
{
	infos->tx[15] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch01w80.xpm", &size, &size);
	infos->tx[16] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch02w80.xpm", &size, &size);
	infos->tx[17] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch03w80.xpm", &size, &size);
	infos->tx[18] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch04w80.xpm", &size, &size);
	infos->tx[19] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch05w80.xpm", &size, &size);
	infos->tx[20] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch06w80.xpm", &size, &size);
	infos->tx[21] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch07w80.xpm", &size, &size);
	infos->tx[22] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch08w80.xpm", &size, &size);
	infos->tx[23] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch09w80.xpm", &size, &size);
	infos->tx[24] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch10w80.xpm", &size, &size);
	return (0);
}

int	load_animation_tx3(t_info *infos, int size)
{
	infos->tx[25] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch01w60.xpm", &size, &size);
	infos->tx[26] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch02w60.xpm", &size, &size);
	infos->tx[27] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch03w60.xpm", &size, &size);
	infos->tx[28] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch04w60.xpm", &size, &size);
	infos->tx[29] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch05w60.xpm", &size, &size);
	infos->tx[30] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch06w60.xpm", &size, &size);
	infos->tx[31] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch07w60.xpm", &size, &size);
	infos->tx[32] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch08w60.xpm", &size, &size);
	infos->tx[33] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch09w60.xpm", &size, &size);
	infos->tx[34] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch10w60.xpm", &size, &size);
	return (0);
}

int	load_animation_tx4(t_info *infos, int size)
{
	infos->tx[35] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch01w40.xpm", &size, &size);
	infos->tx[36] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch02w40.xpm", &size, &size);
	infos->tx[37] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch03w40.xpm", &size, &size);
	infos->tx[38] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch04w40.xpm", &size, &size);
	infos->tx[39] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch05w40.xpm", &size, &size);
	infos->tx[40] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch06w40.xpm", &size, &size);
	infos->tx[41] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch07w40.xpm", &size, &size);
	infos->tx[42] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch08w40.xpm", &size, &size);
	infos->tx[43] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch09w40.xpm", &size, &size);
	infos->tx[44] = mlx_xpm_file_to_image(infos->mlx,
			"img/torch10w40.xpm", &size, &size);
	return (0);
}

int	load_textures(t_info *infos, int size)
{
	int	i;

	infos->tx[0] = mlx_xpm_file_to_image(infos->mlx,
			infos->no_tx_path, &size, &size);
	infos->tx[1] = mlx_xpm_file_to_image(infos->mlx,
			infos->so_tx_path, &size, &size);
	infos->tx[2] = mlx_xpm_file_to_image(infos->mlx,
			infos->we_tx_path, &size, &size);
	infos->tx[3] = mlx_xpm_file_to_image(infos->mlx,
			infos->ea_tx_path, &size, &size);
	infos->tx[4] = mlx_xpm_file_to_image(infos->mlx,
			C_DOOR, &size, &size);
	load_animation_tx1(infos, size);
	load_animation_tx2(infos, size);
	load_animation_tx3(infos, size);
	load_animation_tx4(infos, size);
	i = -1;
	while (++i < TXNO)
	{
		if (!infos->tx[i])
			free_print_exit_error("Texture not found", infos, NULL);
	}
	set_textures(infos);
	return (0);
}
