/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:35:02 by ngharian          #+#    #+#             */
/*   Updated: 2025/03/28 14:21:35 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static char	*clean_texture(char *texture, int copy_len, int i, t_info *infos)
{
	int		j;
	char	*buffer;

	while (ft_isspace(texture[i]))
		++i;
	i += 2;
	while (ft_isspace(texture[i]))
		++i;
	while (texture[i + copy_len] != '\0' && !ft_isspace(texture[i + copy_len]))
		++ copy_len;
	buffer = malloc((copy_len + 1) * sizeof(char));
	if (!buffer)
		free_print_exit_error("Malloc failure.", infos);
	j = -1;
	while (texture[i] && !ft_isspace(texture[i]))
		buffer[++j] = texture[i++];
	buffer[j + 1] = '\0';
	while (ft_isspace(texture[i]))
		++i;
	if (texture[i] != '\0' && texture[i] != '\n')
		free_print_exit_error(
			"A texture should not contain more than one path.", infos);
	free(texture);
	return (buffer);
}

static void	check_rgb(char *str, t_info *infos)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == ',')
			++count;
		while (ft_isspace(str[i]))
			++i;
		while (ft_isdigit(str[i]))
			++i;
		while (ft_isspace(str[i]))
			++i;
		if (str[i] != ',' && str[i] != '\0')
			free_print_exit_error("Invalid RGB value.", infos);
	}
	if (count != 2)
		free_print_exit_error("Invalid RGB value.", infos);
}

static int	*clean_color(char *color, int i, t_info *infos, int count)
{
	int		*buffer;

	buffer = malloc(sizeof(int) * 3);
	if (!buffer)
		free_print_exit_error("Malloc failure.", infos);
	while (ft_isspace(color[i]))
		++i;
	++i;
	while (ft_isspace(color[i]))
		++i;
	while (++count < 3 && color[i] != '\0')
	{
		buffer[count] = ft_atoi(color + i);
		while (ft_isspace(color[i]))
			++i;
		if (!ft_isdigit(color[i]))
			free_print_exit_error("Invalid RGB value.", infos);
		while (ft_isdigit(color[i]))
			++i;
		while (ft_isspace(color[i]))
			++i;
		if (color[i] == ',')
			++i;
	}
	return (free(color), buffer);
}

void	check_infos(t_info *infos)
{
	int	*color;

	infos->no_tx_path = clean_texture(infos->no_tx_path, 0, 0, infos);
	infos->so_tx_path = clean_texture(infos->so_tx_path, 0, 0, infos);
	infos->ea_tx_path = clean_texture(infos->ea_tx_path, 0, 0, infos);
	infos->we_tx_path = clean_texture(infos->we_tx_path, 0, 0, infos);
	check_rgb(infos->c_color, infos);
	infos->c_color_clean = clean_color(infos->c_color, 0, infos, -1);
	check_rgb(infos->f_color, infos);
	infos->f_color_clean = clean_color(infos->f_color, 0, infos, -1);
	color = infos->c_color_clean;
	if (color[0] < 0 || color[0] > 255 || color[1] < 0 || color[1] > 255
		|| color[1] < 0 || color[2] > 255)
		free_print_exit_error("Invalid RGB value.", infos);
	color = infos->f_color_clean;
	if (color[0] < 0 || color[0] > 255 || color[1] < 0 || color[1] > 255
		|| color[1] < 0 || color[2] > 255)
		free_print_exit_error("Invalid RGB value.", infos);
	check_horizontal(infos, infos->map, -1, 0);
	check_vertical(infos->map, -1, 0, infos);
}
