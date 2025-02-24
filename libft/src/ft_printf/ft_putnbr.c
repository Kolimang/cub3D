/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:06:49 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/09 13:26:21 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_putnbr(int nb)
{
	size_t	tot;
	char	*buffer;

	buffer = ft_itoa(nb);
	if (!buffer)
		return (-1);
	tot = ft_putstr(buffer);
	free(buffer);
	return (tot);
}
