/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/03/28 14:22:08 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	set_textures(t_info *infos)
{
	infos->txtr[0].img = infos->tx[0];
	infos->txtr[1].img = infos->tx[1];
	infos->txtr[2].img = infos->tx[2];
	infos->txtr[3].img = infos->tx[3];
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
	if (infos->txtr[0].addr == NULL || infos->txtr[1].addr == NULL
		|| infos->txtr[2].addr == NULL || infos->txtr[3].addr == NULL)
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
