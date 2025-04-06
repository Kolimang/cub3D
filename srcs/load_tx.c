/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tx .c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:05:24 by jrichir           #+#    #+#             */
/*   Updated: 2025/04/03 12:40:50 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
	i = -1;
	while (++i < TXNO)
	{
		if (!infos->tx[i])
			free_print_exit_error("Texture not found", infos, NULL);
	}
	set_textures(infos);
	return (0);
}
