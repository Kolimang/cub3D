/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:50:31 by ngharian          #+#    #+#             */
/*   Updated: 2025/04/02 15:19:40 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	free_print_exit_error(char *message, t_info *infos)
{
	write(2, "Error\n", 6);
	if (message != NULL)
		write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (infos != NULL)
		ft_free(infos);
	exit (1);
}

static void	ft_free_mlx(t_info *infos)
{
	int	i;

	if (infos->img.img != NULL)
		mlx_destroy_image(infos->mlx, infos->img.img);
	i = -1;
	while (++i < TXNO)
	{
		if (infos->tx[i] != NULL)
			mlx_destroy_image(infos->mlx, infos->tx[i]);
	}
	if (infos->windw != NULL)
		mlx_destroy_window(infos->mlx, infos->windw);
	if (infos->mlx != NULL)
		mlx_destroy_display(infos->mlx);
	free(infos->mlx);
}

void	ft_free(t_info *infos)
{
	int	i;

	if (infos->mlx != NULL)
		ft_free_mlx(infos);
	if (infos->rc)
		free(infos->rc);
	if (infos->no_tx_path != NULL)
		free(infos->no_tx_path);
	if (infos->so_tx_path != NULL)
		free(infos->so_tx_path);
	if (infos->we_tx_path != NULL)
		free(infos->we_tx_path);
	if (infos->ea_tx_path != NULL)
		free(infos->ea_tx_path);
	if (infos->f_color_clean != NULL)
		free(infos->f_color_clean);
	if (infos->c_color_clean != NULL)
		free(infos->c_color_clean);
	i = -1;
	while (infos->map != NULL && infos->map[++i])
		free(infos->map[i]);
	if (infos->map != NULL)
		free(infos->map);
	free(infos);
}

void	init_movements(t_info *infos)
{
	infos->moves.go_fwd = 0;
	infos->moves.go_bckwd = 0;
	infos->moves.strafe_l = 0;
	infos->moves.strafe_r = 0;
	infos->moves.rot_l = 0;
	infos->moves.rot_r = 0;
	infos->moves.mouse_move = 0;
	infos->time = get_time_ms();
	infos->old_time = 0;
	infos->moves.prev_mouse_x = WIN_W / 2;
	infos->moves.trigger = 0;
	infos->moves.win_focus = 1;
	infos->tx[4] = NULL;
	infos->tx[5] = NULL;
}

void	init_infos(t_info *infos, int i)
{
	infos->map = NULL;
	infos->no_tx_path = NULL;
	infos->so_tx_path = NULL;
	infos->we_tx_path = NULL;
	infos->ea_tx_path = NULL;
	infos->f_color = NULL;
	infos->c_color = NULL;
	infos->c_color_clean = NULL;
	infos->f_color_clean = NULL;
	infos->map_len = 0;
	infos->in_map = 0;
	infos->x_start = -1;
	infos->y_start = -1;
	infos->direction = 'a';
	infos->max_len = 0;
	infos->curr_tx_index = 0;
	infos->rc = NULL;
	infos->mlx = NULL;
	infos->windw = NULL;
	infos->img.img = NULL;
	while (++i < TXNO)
		infos->tx[i] = NULL;
	infos->mlx = NULL;
	infos->windw = NULL;
	init_movements(infos);
}
