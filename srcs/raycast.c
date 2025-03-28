/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/03/28 14:01:21 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

// Perform digital differential analyzer (DDA) algorithm
// Jump to next map square in x or y direction
// then check if wall was hit
void	dda_algo(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	rc->hit = 0;
	while (rc->hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (infos->map[rc->map_x][rc->map_y] > '0')
			rc->hit = 1;
	}
}

// Calculate distance of perpendicular ray
void	get_perp_wall_dist(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	if (rc->side == 0)
		rc->perp_wall_dist = (rc->side_dist_x - rc->delta_dist_x);
	else
		rc->perp_wall_dist = (rc->side_dist_y - rc->delta_dist_y);
}

// Calculate height, start & end points of vertical stripe to draw on screen
void	get_stripe_data(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	rc->line_height = (int)(WIN_H / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + WIN_H / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + WIN_H / 2;
	if (rc->draw_end > WIN_H)
		rc->draw_end = WIN_H;
}

int	raycast(t_info *infos)
{
	t_rc	*rc;

	rc = infos->rc;
	rc->x = -1;
	while (++rc->x < WIN_W)
	{
		get_ray_pos_and_dir(infos);
		get_current_map_cell(infos);
		get_delta_dist(infos);
		get_side_dist(infos);
		dda_algo(infos);
		select_texture(infos);
		get_perp_wall_dist(infos);
		get_stripe_data(infos);
		get_texture_coord(infos);
		fill_img(infos);
	}
	if (mlx_put_image_to_window(infos->mlx, infos->windw, infos->img.img \
		, 0, 0) < 0)
		free_print_exit_error("mlx_put_image_to_window() failed.", infos);
	gettimeofday(&infos->time.tv, NULL);
	infos->time.old_time = infos->time.tv.tv_sec * 1000
		+ infos->time.tv.tv_usec / 1000;
	return (0);
}
