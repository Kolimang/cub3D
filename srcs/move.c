/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:52:33 by jrichir           #+#    #+#             */
/*   Updated: 2025/03/27 15:06:56 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	displace_u(t_info *infos, double close_walls)
{
	double	move_speed;

	move_speed = 0.095;
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

	move_speed = 0.095;
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

	move_speed = 0.095;
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

	move_speed = 0.095;
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

	gettimeofday(&infos->time.tv, NULL);
	infos->time.curr_time = infos->time.tv.tv_sec * 1000 + infos->time.tv.tv_usec / 1000;
	if (infos->time.curr_time - infos->time.old_time < 20)
		return (0);
	close_walls = 4;
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
	
	if (infos->moves.go_fwd == 1
		|| infos->moves.go_bckwd == 1
		|| infos->moves.strafe_r == 1
		|| infos->moves.strafe_l == 1
		|| infos->moves.rot_r == 1
		|| infos->moves.rot_l == 1)
		raycast(infos);
	return (0);
}

int	on_keypress(int key, t_info *infos)
{
	if (key == U_ARROW || key == W_KEY || key == Z_KEY)
		infos->moves.go_fwd = 1;
	else if (key == D_ARROW || key == S_KEY)
		infos->moves.go_bckwd = 1;
	if (key == D_KEY)
		infos->moves.strafe_r = 1;
	else if (key == A_KEY || key == Q_KEY)
		infos->moves.strafe_l = 1;
	if (key == R_ARROW)
		infos->moves.rot_r = 1;
	else if (key == L_ARROW)
		infos->moves.rot_l = 1;
	if (key == ESC_KEY)
		on_destroy(infos);
	//move_player(infos);
	return (0);
}

int	on_keyrelease(int key, t_info *infos)
{
	if (key == U_ARROW || key == W_KEY || key == Z_KEY)
		infos->moves.go_fwd = 0;
	if (key == D_ARROW || key == S_KEY)
		infos->moves.go_bckwd = 0;
	if (key == D_KEY)
		infos->moves.strafe_r = 0;
	if (key == A_KEY || key == Q_KEY)
		infos->moves.strafe_l = 0;
	if (key == R_ARROW)
		infos->moves.rot_r = 0;
	if (key == L_ARROW)
		infos->moves.rot_l = 0;
	return (0);
}
