/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:45:25 by ngharian          #+#    #+#             */
/*   Updated: 2025/02/24 11:29:51 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	update_start_pos(int *trigger, t_info *infos, int y, int x)
{
	if (*trigger == 1)
		print_exit_error("There should be only one start position");
	*trigger = 1;
	infos->direction = infos->map[y][x];
	infos->x_start = x;
	infos->y_start = y;
	infos->map[y][x] = '0';
}

//TO DO:
//changer la logique? -> car là, imaginons qu'on ait
//01110
//10001 => c'est bien ferme, mais detecte une erreur car 0 sur un bord, 
//01110     il faudrait trouver une autre logique pour regler ces problemes.
//
void	check_horizontal(t_info *infos, char **map)
{
	int	j;
	int	i;
	int	start_trigger;

	i = -1;
	start_trigger = 0;
	while (map[++i])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			++j;
		while (map[i][j])
		{
			if ((map[i][j] != '1' && (j == 0 || (ft_isspace(map[i][j - 1])
					|| ft_isspace(map[i][j + 1])))))
				print_exit_error("A wall can't be empty.\n");
			if (map[i][j] == 'N' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'E')
				update_start_pos(&start_trigger, infos, i, j);
			else if (map[i][j] != '0' && map[i][j] != '1'
					&& !ft_isspace(map[i][j]))
				print_exit_error("Invalid char in the map.\n");
			++j;
			infos->y_start ++;
		}
	}
	if (start_trigger == 0)
		print_exit_error("No start position found in map");
}
