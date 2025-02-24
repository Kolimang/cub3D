/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:39:26 by ngharian          #+#    #+#             */
/*   Updated: 2025/02/24 11:18:57 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	print_map_info(t_info infos)
{
	int	i;

	ft_printf("NO: %s\n", infos.no_texture);
	ft_printf("SO: %s\n", infos.so_texture);
	ft_printf("WE: %s\n", infos.we_texture);
	ft_printf("EA: %s\n", infos.ea_texture);
	ft_printf("C: [%d], [%d], [%d]\n", infos.c_color_clean[0], infos.c_color_clean[1], infos.c_color_clean[2]);
	ft_printf("F: [%d], [%d], [%d]\n", infos.f_color_clean[0], infos.f_color_clean[1], infos.f_color_clean[2]);
	i = -1;
	ft_printf("[map:]\n");
	while (infos.map[++i])
		ft_printf("%s\n", infos.map[i]);
}

static int	open_file(char *file)
{
	int	len_file;
	int	fd;

	len_file = ft_strlen(file);
	if (len_file < 5 || file[len_file - 1] != 'b' || file[len_file - 2] != 'u'
		|| file[len_file - 3] != 'c' || file[len_file - 4] != '.')
		print_exit_error("The file should be in '.cub' format.\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_exit_error("Please enter a valid filename.\n");
	return (fd);
}

int	main(int argc, char *argv[])
{
	t_info	infos;
	int		fd;

	if (argc > 2 || argc < 2)
		print_exit_error("Wrong number of arguments.\n");
	fd = open_file(argv[1]);
	infos = parsing(fd);
	print_map_info(infos);
	//check_infos(infos);
	//start_rendering(infos);
	exit (0);
	return (0);
}
