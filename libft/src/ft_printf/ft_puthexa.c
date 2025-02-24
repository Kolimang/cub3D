/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:02:29 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/14 16:47:45 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_len_nb_in_hexa(unsigned long nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb > 0)
	{
		++count;
		nb /= 16;
	}
	return (count);
}

int	ft_puthexa(unsigned long nb, char *base)
{
	int		len;
	char	*dest;

	len = ft_len_nb_in_hexa(nb);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (-1);
	dest[len--] = '\0';
	if (nb == 0)
		dest[0] = '0';
	while (len >= 0)
	{
		dest[len--] = base[nb % 16];
		nb /= 16;
	}
	nb = ft_putstr(dest);
	free(dest);
	return (nb);
}
