/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:08:36 by ngharian          #+#    #+#             */
/*   Updated: 2025/04/02 13:55:29 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void	ft_update_arr(t_info *infos, char *line, int i)
{
	char	**tmp;

	if (infos->max_len < (int)ft_strlen(line))
		infos->max_len = ft_strlen(line);
	if (infos->map_len == 0)
	{
		tmp = malloc(sizeof(char *) * 2);
		infos->in_map = 1;
	}
	else
		tmp = malloc(sizeof(char *) * (infos->map_len + 2));
	if (tmp == NULL)
		free_print_exit_error("Malloc failure.", infos);
	if (line[ft_strlen(line)- 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	while (infos->map != NULL && infos->map[++i] != NULL)
		tmp[i] = infos->map[i];
	if (infos->map != NULL)
		free(infos->map);
	else
		i = 0;
	tmp[i] = line;
	tmp[i + 1] = NULL;
	infos->map = tmp;
	infos->map_len++;
}

static void	handle_line(char *line, t_info *infos, int i)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (line[i] == '1' || line[i] == '0')
		ft_update_arr(infos, line, -1);
	else if (line[i] == 'C' && ft_isspace(line[i + 1]))
		infos->c_color = line;
	else if (line[i] == 'F' && ft_isspace(line[i + 1]))
		infos->f_color = line;
	else if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		infos->no_tx_path = line;
	else if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		infos->so_tx_path = line;
	else if (line[i] == 'W' && line[i + 1] == 'E' && ft_isspace(line[i + 2]))
		infos->we_tx_path = line;
	else if (line[i] == 'E' && line[i + 1] == 'A' && ft_isspace(line[i + 2]))
		infos->ea_tx_path = line;
	else
		free_print_exit_error("Invalid line in the file.", infos);
}

static void	get_infos(t_info *infos, int fd)
{
	char	*line;
	int		i;

	while (1)
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (ft_isspace(line[i]))
			++i;
		if (line[i] == '\n' || line[i] == '\0')
		{
			if (line[i] == '\n' && infos->in_map == 1)
				free_print_exit_error(
					"Map should be at the end of the file.", infos);
			free(line);
			continue ;
		}
		if (infos->in_map == 1 && line[i] != '0' && line[i] != '1')
			free_print_exit_error(
				"Map should be at the end of the file.", infos);
		handle_line(line, infos, i);
	}
	close(fd);
}

void	uniform_map(t_info *infos)
{
	int		i;
	int		j;
	char	*new_line;

	i = -1;
	while (infos->map[++i])
	{
		if ((int) ft_strlen(infos->map[i]) < infos->max_len)
		{
			new_line = malloc(sizeof(char *) * (infos->max_len + 1));
			if (!new_line)
				free_print_exit_error("Malloc failure.", infos);
			j = -1;
			while (infos->map[i][++j] && infos->map[i][j] != '\n')
				new_line[j] = infos->map[i][j];
			while (j < infos->max_len - 1)
				new_line[j++] = '.';
			new_line[j] = '\0';
			free(infos->map[i]);
			infos->map[i] = new_line;
		}
	}
}

void	parsing(t_info *infos, int fd)
{
	if (WIN_W < 320 || WIN_H < 160 || WIN_W > 3840 || WIN_H > 2020)
		free_print_exit_error(
			"Min window resolution = 320*160, Max = 3840*2020.", infos);
	init_infos(infos);
	get_infos(infos, fd);
	if (infos->c_color == NULL || infos->f_color == NULL
		|| infos->map_len < 3 || infos->no_tx_path == NULL
		|| infos->so_tx_path == NULL || infos->ea_tx_path == NULL
		|| infos->we_tx_path == NULL)
		free_print_exit_error("The file lacks information.", infos);
	check_infos(infos);
	check_door(infos);
	uniform_map(infos);
}
