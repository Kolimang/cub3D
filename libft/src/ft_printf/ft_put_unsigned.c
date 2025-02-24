/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:55:58 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/09 13:37:11 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_nblen(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		++count;
	while (nb > 0)
	{
		++count;
		nb /= 10;
	}
	return (count);
}

int	ft_put_unsigned(unsigned int nb)
{
	char	*dest;
	int		nb_len;

	nb_len = ft_nblen(nb);
	dest = (char *)malloc((nb_len + 1) * sizeof(char));
	if (!dest)
		return (-1);
	dest[nb_len--] = '\0';
	while (nb_len >= 0)
	{
		dest[nb_len--] = ((nb % 10) + '0');
		nb /= 10;
	}
	nb_len = ft_putstr(dest);
	free(dest);
	return (nb_len);
}
