/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:35:02 by ngharian          #+#    #+#             */
/*   Updated: 2025/02/24 10:35:40 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static char	*clean_texture(char *texture, int copy_len, int i)
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
		print_exit_error("Malloc failure.\n");
	j = -1;
	while (texture[i] && !ft_isspace(texture[i]))
		buffer[++j] = texture[i++];
	buffer[j + 1] = '\0';
	while (ft_isspace(texture[i]))
		++i;
	if (texture[i] != '\0' && texture[i] != '\n')
		print_exit_error("A texture should not contain more than one path.\n");
	free(texture);
	return (buffer);
}

static int	*clean_color(char *color)
{
	int		i;
	int		*buffer;
	int		count;

	i = 0;
	count = -1;
	buffer = malloc(sizeof(int) * 3);
	if (!buffer)
		print_exit_error("Malloc failure.\n");
	while (ft_isspace(color[i]))
		++i;
	++i;
	while (ft_isspace(color[i]))
		++i;
	while (++count < 3 && color[i] != '\0')
	{
		buffer[count] = ft_atoi(color + i);
		if (buffer[count] < 0 || buffer[count] > 255 || !ft_isdigit(color[i]))
			print_exit_error("Invalid RGB value.\n");
		while (ft_isdigit(color[i]))
			++i;
		while (ft_isspace(color[i]) || color[i] ==',')
		++i;
	}		
	free(color);
	return (buffer);
		
}
	
void	check_infos(t_info *infos)
{
	infos->no_texture = clean_texture(infos->no_texture, 0, 0);
	infos->so_texture = clean_texture(infos->so_texture, 0, 0);
	infos->ea_texture = clean_texture(infos->ea_texture, 0, 0);
	infos->we_texture = clean_texture(infos->we_texture, 0, 0);
	infos->c_color_clean = clean_color(infos->c_color);
	infos->f_color_clean = clean_color(infos->f_color);
	check_horizontal(infos, infos->map);
	//check_vertical(infos->map);
}
