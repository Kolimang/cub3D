/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:08:36 by ngharian          #+#    #+#             */
/*   Updated: 2025/02/24 10:31:15 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void init_infos(t_info *infos)
{
	infos->map = NULL;
	infos->no_texture = NULL;
	infos->so_texture = NULL;
	infos->ea_texture = NULL;
	infos->we_texture = NULL;
	infos->f_color = NULL;
	infos->c_color = NULL;
	infos->map_len = 0;
	infos->in_map = 0;
	infos->x_start = -1;
	infos->y_start = -1;
	infos->direction = 'a';
}

static void	ft_update_arr(t_info *infos, char *line)
{
	char	**tmp;
	int		i;

	if (infos->map_len == 0)
	{
		tmp = malloc(sizeof(char *) * 2);
		infos->in_map = 1;
	}
	else
		tmp = malloc(sizeof(char *) * (infos->map_len + 2));
	if (tmp == NULL)
		print_exit_error("Malloc failure.\n");
	if (line[ft_strlen(line)- 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	i = -1;
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

static void handle_line(char *line, t_info *infos, int i)
{
	if (line[i] == '1' || line[i] == '0')
		ft_update_arr(infos, line);
	else if (line[i] == 'C' && ft_isspace(line[i + 1]))
		infos->c_color = line;
	else if (line[i] == 'F' && ft_isspace(line[i + 1]))
		infos->f_color = line;
	else if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		infos->no_texture = line;
	else if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		infos->so_texture = line;
	else if (line[i] == 'W' && line[i + 1] == 'E' && ft_isspace(line[i + 2]))
		infos->we_texture = line;
	else if (line[i] == 'E' && line[i + 1] == 'A' && ft_isspace(line[i + 2]))
		infos->ea_texture = line;
	else
	{
		ft_printf("line: %s\n", line);
		print_exit_error("Invalid line in the file.\n");
	}
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
				print_exit_error("Map should be at the end of the file.\n");
			free(line);
			continue ;
		}
		if (infos->in_map == 1 && line[i] != '0' && line[i] != '1')
			print_exit_error("Map should be at the end of the file.\n");
		handle_line(line, infos, i);
	}
	close(fd);
}

t_info	parsing(int fd)
{
	t_info	infos;

	init_infos(&infos);
	get_infos(&infos, fd);
	if (infos.c_color == NULL || infos.f_color == NULL
		|| infos.map_len < 3 || infos.no_texture == NULL
		|| infos.so_texture == NULL || infos.ea_texture == NULL
		|| infos.we_texture == NULL)
		print_exit_error("The file lack of informations.\n");
	check_infos(&infos);
	return (infos);
}
