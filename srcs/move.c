/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/03/30 12:06:41 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	displace_u(t_info *infos, double close_walls)
{
	double	move_speed;

	move_speed = infos->frame_time * 5.0;
	if (infos->map[(int)(infos->pos_x + infos->dir_x * move_speed)] \
		[(int)(infos->pos_y)] == '0' && infos->map[(int)(infos->pos_x \
		+ infos->dir_x * move_speed * close_walls)][(int)(infos->pos_y)] == '0')
		infos->pos_x += infos->dir_x * move_speed;
	if (infos->map[(int)(infos->pos_x)][(int)
		(infos->pos_y + infos->dir_y * move_speed)] == '0' \
		&& infos->map[(int)(infos->pos_x)][(int)(infos->pos_y + infos->dir_y \
		* move_speed * close_walls)] == '0')
		infos->pos_y += infos->dir_y * move_speed;
}

void	displace_d(t_info *infos, double close_walls)
{
	double	move_speed;

	move_speed = infos->frame_time * 5.0;
	if (infos->map[(int)(infos->pos_x - infos->dir_x * move_speed)] \
		[(int)(infos->pos_y)] == '0' && infos->map \
		[(int)(infos->pos_x - infos->dir_x * move_speed * close_walls)] \
		[(int)(infos->pos_y)] == '0')
		infos->pos_x -= infos->dir_x * move_speed;
	if (infos->map[(int)(infos->pos_x)][(int)(infos->pos_y - infos->dir_y \
		* move_speed)] == '0' && infos->map[(int)(infos->pos_x)][\
		(int)(infos->pos_y - infos->dir_y * move_speed * close_walls)] == '0')
		infos->pos_y -= infos->dir_y * move_speed;
}

void	displace_l(t_info *infos, double close_walls)
{
	double	move_speed;

	move_speed = infos->frame_time * 5.0;
	if (infos->map[(int)(infos->pos_x - infos->plane_x * move_speed)][(int) \
		(infos->pos_y)] == '0' && infos->map[(int)(infos->pos_x - \
		infos->plane_x * move_speed * close_walls)][(int)(infos->pos_y)] == '0')
		infos->pos_x -= infos->plane_x * move_speed;
	if (infos->map[(int)(infos->pos_x)][(int)(infos->pos_y - infos->plane_y * \
		move_speed)] == '0' && infos->map[(int)(infos->pos_x)][(int) \
		(infos->pos_y - infos->plane_y * move_speed * close_walls)] == '0')
		infos->pos_y -= infos->plane_y * move_speed;
}

void	displace_r(t_info *infos, double close_walls)
{
	double	move_speed;

	move_speed = infos->frame_time * 5.0;
	if (infos->map[(int)(infos->pos_x + infos->plane_x * move_speed)][(int) \
		(infos->pos_y)] == '0' && infos->map[(int)(infos->pos_x + \
		infos->plane_x * move_speed * close_walls)][(int)(infos->pos_y)] == '0')
		infos->pos_x += infos->plane_x * move_speed;
	if (infos->map[(int)(infos->pos_x)][(int)(infos->pos_y + infos->plane_y \
		* move_speed)] == '0' && infos->map[(int)(infos->pos_x)][(int) \
		(infos->pos_y + infos->plane_y * move_speed * close_walls)] == '0')
		infos->pos_y += infos->plane_y * move_speed;
}

int	move_player(t_info *infos)
{
	double	close_walls;

	close_walls = 1.75;
	if (infos->moves.go_fwd == 1)
		displace_u(infos, close_walls);
	else if (infos->moves.go_bckwd == 1)
		displace_d(infos, close_walls);
	if (infos->moves.strafe_r == 1)
		displace_r(infos, close_walls);
	else if (infos->moves.strafe_l == 1)
		displace_l(infos, close_walls);
	if (infos->moves.rot_r == 1)
		rotate_r(infos);
	else if (infos->moves.rot_l == 1)
		rotate_l(infos);
	else if (infos->moves.mouse_move == 1)
	{
		mouse_rotate(infos, infos->moves.mouse_rotation);
		infos->moves.mouse_move = 0;
	}
	raycast(infos, NULL);
	return (0);
}
