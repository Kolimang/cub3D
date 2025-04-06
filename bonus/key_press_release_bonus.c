/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_release .c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:14:07 by ngharian          #+#    #+#             */
/*   Updated: 2025/04/03 12:40:50 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

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
	if (key == X_KEY)
		mouse_focus(infos);
	if (key == F_KEY)
		open_close_door(infos);
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
