/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:59:11 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/06 15:53:37 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2[i])
		return ((char *)(s1));
	while (s1[i] && n > 0)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] == s2[j] && j + i < n && s2[j]
				&& s1[i + j])
				++j;
			if (s2[j] == '\0')
				return ((char *)(s1 + i));
		}
		++i;
	}
	return (NULL);
}
