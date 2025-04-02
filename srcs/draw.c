/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/04/02 15:09:25 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	select_anim_texture(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	if (infos->curr_tx_index >= (TXNO - 5))
		infos->curr_tx_index = 0;
	if (infos->curr_tx_index <= 0)
		rc->tx_id = 5;
	else
		rc->tx_id = 5 + infos->curr_tx_index;
	if ((get_time_ms() - infos->start_time) % (int)(1 / infos->frame_time) == 0)
		infos->curr_tx_index++;
}

// Define which texture must be rendered on current stripe
// [0] = North texture
// [1] = South texture
// [2] = West texture
// [3] = East texture
// [4] = Open door texture
// [5] = Close door texture
void	select_texture(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	if (rc->torch_hit == 1)
		select_anim_texture(infos);
	else if (rc->side == 0)
	{
		if (rc->map_x < (int)infos->pos_x)
			rc->tx_id = 1;
		else
			rc->tx_id = 0;
	}
	else
	{
		if (rc->map_y < (int)infos->pos_y)
			rc->tx_id = 3;
		else
			rc->tx_id = 2;
	}
	get_door_texture(infos, rc);
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
