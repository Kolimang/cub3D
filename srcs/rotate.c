/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:05:13 by ngharian          #+#    #+#             */
/*   Updated: 2025/03/28 12:25:07 by ngharian         ###   ########.fr       */
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
