/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:05:13 by ngharian          #+#    #+#             */
/*   Updated: 2025/03/30 12:10:44 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	rotate_l(t_info *infos)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = infos->frame_time * 2.0;
	old_dir_x = infos->dir_x;
	old_plane_x = infos->plane_x;
	infos->dir_x = infos->dir_x * cos(rot_speed) - infos->dir_y * \
		sin(rot_speed);
	infos->dir_y = old_dir_x * sin(rot_speed) + infos->dir_y * cos(rot_speed);
	infos->plane_x = infos->plane_x * cos(rot_speed) \
					- infos->plane_y * sin(rot_speed);
	infos->plane_y = old_plane_x * sin(rot_speed) \
					+ infos->plane_y * cos(rot_speed);
}

void	rotate_r(t_info *infos)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = infos->frame_time * 2.0;
	old_plane_x = infos->plane_x;
	old_dir_x = infos->dir_x;
	infos->dir_x = infos->dir_x * cos(-rot_speed) \
				- infos->dir_y * sin(-rot_speed);
	infos->dir_y = old_dir_x * sin(-rot_speed) \
				+ infos->dir_y * cos(-rot_speed);
	infos->plane_x = infos->plane_x * cos(-rot_speed) \
				- infos->plane_y * sin(-rot_speed);
	infos->plane_y = old_plane_x * sin(-rot_speed) \
				+ infos->plane_y * cos(-rot_speed);
}

int	mouse_rotate(t_info *infos, int x)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	old_dir_x = infos->dir_x;
	old_plane_x = infos->plane_x;
	angle = (x / infos->frame_time) * 0.00055;
	infos->dir_x = infos->dir_x * cos(angle) - infos->dir_y * sin(angle);
	infos->dir_y = old_dir_x * sin(angle) + infos->dir_y * cos(angle);
	infos->plane_x = infos->plane_x * cos(angle) - infos->plane_y * sin(angle);
	infos->plane_y = old_plane_x * sin(angle) + infos->plane_y * cos(angle);
	return (0);
}

int	mouse_moved(int x, int y, t_info *infos)
{
	int	delta_x;

	delta_x = x - infos->moves.prev_mouse_x;
	infos->moves.mouse_rotation = -delta_x;
	infos->moves.mouse_move = 1;
	infos->moves.prev_mouse_x = x;
	++y;
	return (0);
}
