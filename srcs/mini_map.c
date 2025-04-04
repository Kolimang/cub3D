/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-31 10:46:01 by ngharian          #+#    #+#             */
/*   Updated: 2025-03-31 10:46:01 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void	draw_square(t_info *infos, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			my_mlx_pixel_put(&infos->img, x + i, y + j, color);
	}
}

void	draw_minimap(t_info *infos)
{
	int	i;
	int	j;
	int	round_x;
	int	round_y;

	i = -1;
	round_x = round(infos->pos_x - 0.5);
	round_y = round(infos->pos_y - 0.5);
	while (infos->map[++i])
	{
		j = -1;
		while (infos->map[i][++j])
		{
			if (infos->map[i][j] == '1')
				draw_square(infos, WIN_W - ((infos->max_len - j + 2) \
						* 10), (i + 2) * 10, WALL_C);
			if (infos->map[i][j] == '0')
				draw_square(infos, WIN_W - ((infos->max_len - j + 2) * 10) \
						, (2 + i) * 10, FLOOR_C);
		}
		draw_square(infos, WIN_W - ((infos->max_len - round_y + 2) \
				* 10), (2 + round_x) * 10, PLAYER_C);
	}
}
