/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/04/02 11:38:35 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Define which texture must be rendered on current stripe
// [0] = North texture
// [1] = South texture
// [2] = West texture
// [3] = East texture
void	select_texture(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	if (rc->side == 0)
	{
		if (rc->map_x < (int)infos->pos_x)
			rc->tx_id = 1;
		else
		{
			if (infos->curr_tx_index > (TXNO - 4))
				infos->curr_tx_index = 0;
			if (infos->curr_tx_index <= 0)
				rc->tx_id = 0;
			else
				rc->tx_id = 3 + infos->curr_tx_index;
			if ((get_time_ms() - infos->start_time) % (int)(1 / infos->frame_time) == 0)
				infos->curr_tx_index++;
			// if (infos->frame > 100000)
			// 	infos->frame = 0;
		}
	}
	else
	{
		if (rc->map_y < (int)infos->pos_y)
			rc->tx_id = 3;
		else
			rc->tx_id = 2;
	}
}

// Calculate where exactly the wall was hit
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

void	fill_env_color(t_info *infos, int start, int end, int *col)
{
	int		y;
	t_rc	*rc;

	rc = infos->rc;
	y = start;
	rc->color = (uint32_t)(255 << 24 | col[0] << 16 | col[1] << 8 | col[2]);
	while (++y < end)
		my_mlx_pixel_put(&infos->img, rc->x, y, rc->color);
}

// Cast the texture coordinate to integer, and mask
// with (TX_H - 1) in case of overflow
void	fill_img(t_info *infos)
{
	int		y;
	t_rc	*rc;

	rc = infos->rc;
	y = rc->draw_start;
	fill_env_color(infos, -1, rc->draw_start, infos->c_color_clean);
	fill_env_color(infos, rc->draw_end, WIN_H, infos->f_color_clean);
	while (y < rc->draw_end)
	{
		rc->tx_y = (int)rc->tx_pos & (TX_H - 1);
		rc->tx_pos += rc->tx_step;
		rc->px_index = (TXSIZE * rc->tx_y + rc->tx_x)
			* (infos->txtr[rc->tx_id].bits_per_pixel / 8);
		rc->px = (unsigned char *)&infos->txtr[rc->tx_id].addr[rc->px_index];
		rc->color = (rc->px[2] << 16) | (rc->px[1] << 8) | rc->px[0];
		my_mlx_pixel_put(&infos->img, rc->x, y, rc->color);
		y++;
	}
}
