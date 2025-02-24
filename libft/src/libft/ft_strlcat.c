/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:33:11 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/06 15:48:57 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (dest_len < n - 1 && n > 0)
	{
		while (dest_len + i < n - 1 && src[i])
		{
			dest[dest_len + i] = src[i];
			++i;
		}
		dest[dest_len + i] = '\0';
	}
	if (dest_len >= n)
		dest_len = n;
	return (dest_len + src_len);
}
