/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:13:27 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/06 15:47:15 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_free(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		++i;
	}
	free(dest);
}

static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = -1;
	count = 0;
	flag = 0;
	while (s[++i])
	{
		if (flag && s[i] == c)
			flag = 0;
		if (!flag && s[i] != c)
		{
			flag = 1;
			++count;
		}
	}
	return (count);
}

static char	*ft_dup(char sep, const char *s, int *s_i)
{
	int		i;
	int		len;
	char	*ret;

	len = 0;
	while (s[*s_i] == sep && s[*s_i] != '\0')
		++(*s_i);
	while (s[len + *s_i] != sep && s[len + *s_i] != '\0' )
		++len;
	ret = (char *)malloc (sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = s[*s_i + i];
	ret[i] = '\0';
	*s_i += len;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		nb_word;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nb_word = ft_count_word(s, c);
	dest = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!dest)
		return (NULL);
	dest[nb_word] = NULL;
	i = -1;
	j = 0;
	while (++i < nb_word)
	{
		dest[i] = ft_dup(c, s, &j);
		if (dest[i] == NULL)
		{
			ft_free(dest);
			return (NULL);
		}
	}
	return (dest);
}
