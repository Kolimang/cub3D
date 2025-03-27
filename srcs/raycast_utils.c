/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/03/21 13:58:17 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	get_ray_pos_and_dir(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	rc->camera_x = 2 * rc->x / (double)WIN_W - 1;
	rc->ray_dir_x = infos->dir_x + (infos->plane_x * rc->camera_x);
	rc->ray_dir_y = infos->dir_y + (infos->plane_y * rc->camera_x);
}

// Which box of the map we're in
void	get_current_map_cell(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	rc->map_x = (int)infos->pos_x;
	rc->map_y = (int)infos->pos_y;
}

//length of ray from one x or y-side to next x or y-side
void	get_delta_dist(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	if (rc->ray_dir_x)
		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	else
		rc->delta_dist_x = 1e30;
	if (rc->ray_dir_y)
		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	else
		rc->delta_dist_y = 1e30;
}

// calculate step and initial side distance
void	get_side_dist(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (infos->pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - infos->pos_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (infos->pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - infos->pos_y) * rc->delta_dist_y;
	}
}
