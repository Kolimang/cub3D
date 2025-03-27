/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:45:25 by ngharian          #+#    #+#             */
/*   Updated: 2025/03/26 12:56:47 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	other_pos(t_info *infos, int y, int x)
{
	if (infos->map[x][y] == 'W')
	{
		infos->dir_x = 0;
		infos->dir_y = -1;
		infos->plane_x = -(double)FOV / 100;
		infos->plane_y = 0;
	}
	else if (infos->map[x][y] == 'E')
	{
		infos->dir_x = 0;
		infos->dir_y = 1;
		infos->plane_x = (double)FOV / 100;
		infos->plane_y = 0;
	}
}

void	update_start_pos(int *trigger, t_info *infos, int y, int x)
{
	if (*trigger == 1)
		free_print_exit_error("There should be only one start position", infos);
	*trigger = 1;
	infos->direction = infos->map[x][y];
	infos->x_start = x;
	infos->y_start = y;
	infos->pos_x = (double)x + 0.5;
	infos->pos_y = (double)y + 0.5;
	if (infos->map[x][y] == 'N')
	{
		infos->dir_x = -1;
		infos->dir_y = 0;
		infos->plane_x = 0;
		infos->plane_y = (double)FOV / 100;
	}
	else if (infos->map[x][y] == 'S')
	{
		infos->dir_x = 1;
		infos->dir_y = 0;
		infos->plane_x = 0;
		infos->plane_y = -(double)FOV / 100;
	}
	other_pos(infos, y, x);
	infos->map[x][y] = '0';
}

void	check_horizontal(t_info *infos, char **map, int i, int start_trigger)
{
	int	j;

	while (map[++i])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			++j;
		while (map[i][j])
		{
			if (map[i][j] != '1' && !ft_isspace(map[i][j]) && (j == 0
					|| ft_isspace(map[i][j - 1])
					|| ft_isspace(map[i][j + 1]) || map[i][j + 1] == '\0'))
				free_print_exit_error("The map must be surrounded by walls." \
									, infos);
			if (map[i][j] == 'N' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'E')
				update_start_pos(&start_trigger, infos, j, i);
			else if (map[i][j] != '0' && map[i][j] != '1'
					&& !ft_isspace(map[i][j]))
				free_print_exit_error("Invalid char in the map.", infos);
			++j;
		}
	}
	if (start_trigger == 0)
		free_print_exit_error("No start position found in map.", infos);
}

int	get_map_height(char **map)
{
	int	i;
	int	map_height;

	i = -1;
	while (map[++i])
	{
		map_height = i;
	}
	map_height += 1;
	return (map_height);
}

void	check_vertical(char **map, int i, int j, t_info *infos)
{
	int	map_height;

	map_height = get_map_height(map);
	while (map[++i])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			++j;
		while (map[i][j])
		{
			if (map[i][j] != '1' && !ft_isspace(map[i][j]) \
				&& (i == 0 || i == map_height - 1))
				free_print_exit_error("The map must be surrounded by walls." \
									, infos);
			else if (map[i][j] != '1' && !ft_isspace(map[i][j]))
			{
				if ((int)ft_strlen(map[i - 1]) - 1 < j || \
					(int)ft_strlen(map[i + 1]) - 1 < j || \
					ft_isspace(map[i - 1][j]) || ft_isspace(map[i + 1][j]))
					free_print_exit_error(
						"The map must be surrounded by walls.", infos);
			}
			++j;
		}
	}
}
