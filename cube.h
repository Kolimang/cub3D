/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:38:54 by ngharian          #+#    #+#             */
/*   Updated: 2025/02/24 10:33:43 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define FOV 66

# include <unistd.h>
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"

typedef struct s_info
{
	int		map_len;
	int		y_start;
	int		x_start;
	char	direction;
	int		in_map;
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*f_color;
	char	*c_color;
	int		*c_color_clean;
	int		*f_color_clean;
}	t_info;

typedef struct s_clean_info
{
	int		y_start;
	int		x_start;
	char	direction;
	char	**map;
	int		*f_color;
	int		*c_color;
	//toutes les infos mlx (connection, fenetre, image, etc...)
	//images textures
}	t_clean_infos;


void	print_exit_error(char *message);
t_info	parsing(int fd);
void	check_infos(t_info *info);
void	check_horizontal(t_info *infos, char **map);

#endif