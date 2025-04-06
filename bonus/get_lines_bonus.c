/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-05 11:46:11 by ngharian          #+#    #+#             */
/*   Updated: 2025-04-05 11:46:11 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

static void	ft_update_arr(t_info *infos, t_line *line, int i)
{
	char	**tmp;

	if (infos->max_len < (int)ft_strlen(line->s))
		infos->max_len = ft_strlen(line->s);
	if (infos->map_len == 0)
	{
		tmp = malloc(sizeof(char *) * 2);
		infos->in_map = 1;
	}
	else
		tmp = malloc(sizeof(char *) * (infos->map_len + 2));
	if (tmp == NULL)
		free_print_exit_error("Malloc failure.", infos, line);
	if (line->s[ft_strlen(line->s) - 1] == '\n')
		line->s[ft_strlen(line->s) - 1] = '\0';
	while (infos->map != NULL && infos->map[++i] != NULL)
		tmp[i] = infos->map[i];
	if (infos->map != NULL)
		free(infos->map);
	else
		i = 0;
	tmp[i] = line->s;
	tmp[i + 1] = NULL;
	infos->map = tmp;
	infos->map_len++;
}

static void	handle_line(t_line *line, t_info *infos, int i)
{
	if (line->s[ft_strlen(line->s) - 1] == '\n')
		line->s[ft_strlen(line->s) - 1] = '\0';
	if (line->s[i] == '1' || line->s[i] == 'T' || line->s[i] == '0')
		ft_update_arr(infos, line, -1);
	else if (line->s[i] == 'C' && ft_isspace(line->s[i + 1])
		&& infos->c_color == NULL)
		infos->c_color = line->s;
	else if (line->s[i] == 'F' && ft_isspace(line->s[i + 1])
		&& infos->f_color == NULL)
		infos->f_color = line->s;
	else if (line->s[i] == 'N' && line->s[i + 1] == 'O'
		&& ft_isspace(line->s[i + 2]) && infos->no_tx_path == NULL)
		infos->no_tx_path = line->s;
	else if (line->s[i] == 'S' && line->s[i + 1] == 'O'
		&& ft_isspace(line->s[i + 2]) && infos->so_tx_path == NULL)
		infos->so_tx_path = line->s;
	else if (line->s[i] == 'W' && line->s[i + 1] == 'E'
		&& ft_isspace(line->s[i + 2]) && infos->we_tx_path == NULL)
		infos->we_tx_path = line->s;
	else if (line->s[i] == 'E' && line->s[i + 1] == 'A'
		&& ft_isspace(line->s[i + 2]) && infos->ea_tx_path == NULL)
		infos->ea_tx_path = line->s;
	else
		free_print_exit_error("Invalid line in the file.", infos, line);
}

t_line	*handle_and_next(t_line *line, t_line *tmp, t_info *infos,
	int i)
{
	if (infos->in_map == 1 && line->s[i] != '0'
		&& line->s[i] != '1' && line->s[i] != 'T')
		free_print_exit_error(
			"Map should be at the end of the file.", infos, line);
	handle_line(line, infos, i);
	tmp = line;
	line = line->next;
	free(tmp);
	return (line);
}

void	ft_free_lines(t_line *line)
{
	t_line	*tmp;

	while (line)
	{
		tmp = line;
		if (line->s != NULL)
			free(line->s);
		line = line->next;
		free(tmp);
	}
}

t_line	*get_lines(t_line *lines, t_info *infos, int fd, t_line *head)
{
	t_line	*tmp;

	lines = head;
	if (!lines)
	{
		close(fd);
		free_print_exit_error("Malloc failure.", infos, lines);
	}
	lines->s = get_next_line(fd);
	while (1)
	{
		tmp = malloc(sizeof(t_line));
		if (!tmp)
		{
			close(fd);
			free_print_exit_error("Malloc failure.", infos, lines);
		}
		tmp->next = NULL;
		tmp->s = get_next_line(fd);
		if (tmp->s == NULL)
			return (close(fd), free(tmp), head);
		lines->next = tmp;
		lines = tmp;
	}
	return (head);
}
