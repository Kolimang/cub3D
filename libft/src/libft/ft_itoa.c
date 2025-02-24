/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:04:55 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/06 15:05:48 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_nblen(long int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		++count;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		++count;
	}
	return (count);
}

static int	ft_putnbr_in_str(char *dest, long int nb, int i)
{
	int	sign;

	sign = 0;
	if (nb < 0)
	{
		nb *= -1;
		sign = -1;
	}
	if (i > 0)
		ft_putnbr_in_str(dest, nb / 10, i - 1);
	dest[i] = (nb % 10) + '0';
	if (sign == -1)
		dest[0] = '-';
	return (0);
}

char	*ft_itoa(int n)
{
	char		*dest;
	long int	nb;
	int			nb_len;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	nb_len = ft_nblen(nb);
	dest = (char *)malloc(sizeof(char) * (nb_len + 1));
	if (!dest)
		return (NULL);
	ft_putnbr_in_str(dest, nb, nb_len - 1);
	dest[nb_len] = '\0';
	return (dest);
}
