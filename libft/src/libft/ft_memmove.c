/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:57:35 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/06 15:55:40 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if ((!dest && !src))
		return (NULL);
	if (dest + n > src + n)
	{
		while (n)
		{
			i = n - 1;
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			--n;
		}
	}
	else if (dest + n <= src + n)
	{
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			++i;
		}
	}
	return (dest);
}
