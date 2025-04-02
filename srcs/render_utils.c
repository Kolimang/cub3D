/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/04/02 14:43:34 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	set_textures(t_info *infos)
{
	infos->txtr[0].img = infos->tx[0];
	infos->txtr[1].img = infos->tx[1];
	infos->txtr[2].img = infos->tx[2];
	infos->txtr[3].img = infos->tx[3];
	infos->txtr[4].img = infos->tx[4];
	infos->txtr[5].img = infos->tx[5];
	infos->txtr[6].img = infos->tx[6];
	infos->txtr[7].img = infos->tx[7];
	infos->txtr[8].img = infos->tx[8];
	infos->txtr[9].img = infos->tx[9];
	infos->txtr[10].img = infos->tx[10];
	infos->txtr[11].img = infos->tx[11];
	infos->txtr[12].img = infos->tx[12];
	infos->txtr[13].img = infos->tx[13];
	infos->txtr[0].addr = mlx_get_data_addr(infos->txtr[0].img,
			&infos->txtr[0].bits_per_pixel, &infos->txtr[0].line_length,
			&infos->txtr[0].endian);
	infos->txtr[1].addr = mlx_get_data_addr(infos->txtr[1].img,
			&infos->txtr[1].bits_per_pixel, &infos->txtr[1].line_length,
			&infos->txtr[1].endian);
	infos->txtr[2].addr = mlx_get_data_addr(infos->txtr[2].img,
			&infos->txtr[2].bits_per_pixel, &infos->txtr[2].line_length,
			&infos->txtr[2].endian);
	infos->txtr[3].addr = mlx_get_data_addr(infos->txtr[3].img,
			&infos->txtr[3].bits_per_pixel, &infos->txtr[3].line_length,
			&infos->txtr[3].endian);
	infos->txtr[4].addr = mlx_get_data_addr(infos->txtr[4].img,
			&infos->txtr[4].bits_per_pixel, &infos->txtr[4].line_length,
			&infos->txtr[4].endian);
	infos->txtr[5].addr = mlx_get_data_addr(infos->txtr[5].img,
			&infos->txtr[5].bits_per_pixel, &infos->txtr[5].line_length,
			&infos->txtr[5].endian);
	infos->txtr[6].addr = mlx_get_data_addr(infos->txtr[6].img,
			&infos->txtr[6].bits_per_pixel, &infos->txtr[6].line_length,
			&infos->txtr[6].endian);
	infos->txtr[7].addr = mlx_get_data_addr(infos->txtr[7].img,
			&infos->txtr[7].bits_per_pixel, &infos->txtr[7].line_length,
			&infos->txtr[7].endian);
	infos->txtr[8].addr = mlx_get_data_addr(infos->txtr[8].img,
			&infos->txtr[8].bits_per_pixel, &infos->txtr[8].line_length,
			&infos->txtr[8].endian);
	infos->txtr[9].addr = mlx_get_data_addr(infos->txtr[9].img,
			&infos->txtr[9].bits_per_pixel, &infos->txtr[9].line_length,
			&infos->txtr[9].endian);
	infos->txtr[10].addr = mlx_get_data_addr(infos->txtr[10].img,
			&infos->txtr[10].bits_per_pixel, &infos->txtr[10].line_length,
			&infos->txtr[10].endian);
	infos->txtr[11].addr = mlx_get_data_addr(infos->txtr[11].img,
			&infos->txtr[11].bits_per_pixel, &infos->txtr[11].line_length,
			&infos->txtr[11].endian);
	infos->txtr[12].addr = mlx_get_data_addr(infos->txtr[12].img,
			&infos->txtr[12].bits_per_pixel, &infos->txtr[12].line_length,
			&infos->txtr[12].endian);
	infos->txtr[13].addr = mlx_get_data_addr(infos->txtr[13].img,
			&infos->txtr[13].bits_per_pixel, &infos->txtr[13].line_length,
			&infos->txtr[13].endian);
	if (infos->txtr[0].addr == NULL || infos->txtr[1].addr == NULL
		|| infos->txtr[2].addr == NULL || infos->txtr[3].addr == NULL
		|| infos->txtr[4].addr == NULL)
		free_print_exit_error("mlx_get_data_address() failed.", infos);
}

uint64_t	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((uint64_t)(tv.tv_sec * 1000) + (uint64_t)(tv.tv_usec / 1000));
}

void	set_mlx_screen_img(t_info *infos)
{
	infos->img.img = mlx_new_image(infos->mlx, WIN_W, WIN_H);
	if (infos->img.img == NULL)
		free_print_exit_error("mlx_new_image() failed.", infos);
	infos->img.addr = mlx_get_data_addr(infos->img.img,
			&infos->img.bits_per_pixel, &infos->img.line_length,
			&infos->img.endian);
	if (infos->img.img == NULL)
		free_print_exit_error("mlx_get_data_address() failed.", infos);
}
