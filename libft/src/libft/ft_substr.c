/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:17:09 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/06 15:54:38 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			size;
	unsigned int	i;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size > len)
		dest = (char *)malloc(sizeof(char) * len + 1);
	else
		dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		dest[i] = s[start + i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
