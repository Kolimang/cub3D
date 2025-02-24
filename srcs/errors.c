/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:50:31 by ngharian          #+#    #+#             */
/*   Updated: 2025/02/24 11:38:41 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	print_exit_error(char *message)
{
	write(2, "Error\n", 6);
	if (message != NULL)
		write(2, message, ft_strlen(message));
	exit (1);
}
