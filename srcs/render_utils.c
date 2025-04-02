/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/04/02 15:11:41 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	set_textures(t_info *infos)
{
	int	i;

	i = -1;
	while (++i < TXNO)
	{
		infos->txtr[i].img = infos->tx[i];
		infos->txtr[i].addr = mlx_get_data_addr(infos->txtr[i].img,
				&infos->txtr[i].bits_per_pixel, &infos->txtr[i].line_length,
				&infos->txtr[i].endian);
		if (infos->txtr[i].addr == NULL)
			free_print_exit_error("mlx_get_data_address() failed.", infos);
	}
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

int	put_img(t_info *infos, int id, int x, int y)
{
	if (mlx_put_image_to_window(infos->mlx, infos->windw, infos->tx[id] \
		, x, y) < 0)
		free_print_exit_error("mlx_put_image_to_window() failed.", infos);
	return (0);
}

void	get_texture_coord(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	if (rc->side == 0)
		rc->wall_x = infos->pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->wall_x = infos->pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	rc->wall_x -= floor(rc->wall_x);
	rc->tx_x = (int)(rc->wall_x * (double)TX_W);
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->tx_x = TX_W - rc->tx_x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		rc->tx_x = TX_W - rc->tx_x - 1;
	rc->tx_step = (double)TX_H / rc->line_height;
	rc->tx_pos = (rc->draw_start - WIN_H / 2 + rc->line_height / 2)
		* rc->tx_step;
}
