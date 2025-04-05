/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:39:26 by ngharian          #+#    #+#             */
/*   Updated: 2025/04/03 12:40:50 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

/*void	print_map_info(t_info infos)
{
	int	i;

	ft_printf("NO: %s\n", infos.no_tx_path);
	ft_printf("SO: %s\n", infos.so_tx_path);
	ft_printf("WE: %s\n", infos.we_tx_path);
	ft_printf("EA: %s\n", infos.ea_tx_path);
	ft_printf("C: [%d], [%d], [%d]\n", infos.c_color_clean[0],
		infos.c_color_clean[1], infos.c_color_clean[2]);
	ft_printf("F: [%d], [%d], [%d]\n", infos.f_color_clean[0],
		infos.f_color_clean[1], infos.f_color_clean[2]);
	i = -1;
	ft_printf("[map:]\n");
	while (infos.map[++i])
		ft_printf("%s\n", infos.map[i]);
}*/

static int	open_file(char *file)
{
	int	len_file;
	int	fd;

	len_file = ft_strlen(file);
	if (len_file < 4 || file[len_file - 1] != 'b' || file[len_file - 2] != 'u'
		|| file[len_file - 3] != 'c' || file[len_file - 4] != '.')
		free_print_exit_error("The file should be in '.cub' format.",
			NULL, NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_print_exit_error("Please enter a valid filename.", NULL, NULL);
	return (fd);
}

int	main(int argc, char *argv[])
{
	t_info	*infos;
	int		fd;

	if (argc > 2 || argc < 2)
		free_print_exit_error("Wrong number of arguments.", NULL, NULL);
	fd = open_file(argv[1]);
	infos = malloc(sizeof(t_info));
	if (infos == NULL)
		free_print_exit_error("Malloc failure", NULL, NULL);
	parsing(infos, fd);
	infos->rc = malloc(sizeof(t_rc));
	if (infos->rc == NULL)
		free_print_exit_error("Malloc failure", infos, NULL);
	infos->start_time = get_time_ms();
	start_rendering(infos);
	ft_free(infos, -1);
	return (0);
}
