/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:41:17 by ngharian          #+#    #+#             */
/*   Updated: 2025/04/03 12:40:50 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	check_door(t_info *infos)
{
	int	i;
	int	j;

	i = -1;
	while (infos->map[++i])
	{
		j = -1;
		while (infos->map[i][++j])
		{
			if (infos->map[i][j] == '2' && ((infos->map[i][j + 1] != '1'
					|| infos->map[i][j - 1] != '1')
					&& (infos->map[i + 1][j] != '1'
					|| infos->map[i - 1][j] != '1')))
				free_print_exit_error(
					"Door should be surrounded by at least 2 walls." \
					, infos);
		}
	}
}

void	open_close_door(t_info *infos)
{
	int	x;
	int	y;

	x = (int)(infos->pos_x + infos->dir_x);
	y = (int)(infos->pos_y + infos->dir_y);
	if (infos->map[x][y] == '2')
		infos->map[x][y] = '3';
	else if (infos->map[x][y] == '3' &&
		!(infos->pos_x >= x && infos->pos_x < x + 1 &&
			infos->pos_y >= y && infos->pos_y < y + 1))
		infos->map[x][y] = '2';
}

void	get_door_texture(t_info *infos, t_rc *rc)
{
	if (infos->map[rc->map_x][rc->map_y] == '2')
		rc->tx_id = 4;
	if (rc->side == 0)
	{
		if (rc->map_x > 0 && infos->map[rc->map_x - 1]
			[rc->map_y] == '3' && rc->map_x > (int)infos->pos_x)
			rc->tx_id = 4;
		else if (rc->map_x + 1 < infos->map_len && infos->map[rc->map_x + 1]
			[rc->map_y] == '3' && rc->map_x < (int)infos->pos_x)
			rc->tx_id = 4;
	}
	else if (rc->side == 1)
	{
		if (rc->map_y > 0 && infos->map[rc->map_x]
			[rc->map_y - 1] == '3' && rc->map_y > (int)infos->pos_y)
			rc->tx_id = 4;
		else if (rc->map_y + 1 < infos->max_len && infos->map[rc->map_x]
			[rc->map_y + 1] == '3' && rc->map_y < (int)infos->pos_y)
			rc->tx_id = 4;
	}
}
