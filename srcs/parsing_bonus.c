/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:08:36 by ngharian          #+#    #+#             */
/*   Updated: 2025/04/03 12:40:50 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

static void	get_infos(t_info *infos, t_line *line, int i)
{
	t_line	*tmp;

	while (1)
	{
		i = 0;
		if (!line)
			break ;
		while (ft_isspace(line->s[i]))
			++i;
		if (line->s[i] == '\n' || line->s[i] == '\0')
		{
			if (line->s[i] == '\n' && infos->in_map == 1)
				free_print_exit_error(
					"Map should be at the end of the file.", infos, line);
			tmp = line;
			line = line->next;
			free(tmp->s);
			free(tmp);
			continue ;
		}
		line = handle_and_next(line, tmp, infos, i);
	}
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
				free_print_exit_error("Malloc failure.", infos, NULL);
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
	t_line	*lines;

	lines = NULL;
	if (WIN_W < 320 || WIN_H < 160 || WIN_W > 3840 || WIN_H > 2020)
		free_print_exit_error(
			"Min window resolution = 320*160, Max = 3840*2020.", infos, NULL);
	lines = get_lines(lines, infos, fd, malloc(sizeof(t_line)));
	init_infos(infos, -1);
	get_infos(infos, lines, 0);
	if (infos->c_color == NULL || infos->f_color == NULL
		|| infos->map_len < 3 || infos->no_tx_path == NULL
		|| infos->so_tx_path == NULL || infos->ea_tx_path == NULL
		|| infos->we_tx_path == NULL)
		free_print_exit_error("The file lacks information.", infos, NULL);
	check_infos(infos);
	check_door(infos);
	uniform_map(infos);
}
