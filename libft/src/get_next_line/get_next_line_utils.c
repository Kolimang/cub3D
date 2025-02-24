/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:17:18 by ngharian          #+#    #+#             */
/*   Updated: 2023/12/27 13:40:10 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_append_line(char *line, char *dest, int *i)
{
	while (line[*i])
	{
		dest[*i] = line[*i];
		++(*i);
	}
	return (dest);
}

char	*ft_join(char *buffer, char *line, int char_readed)
{
	int		i;
	int		j;
	char	*dest;

	buffer[char_readed] = '\0';
	dest = malloc((ft_strlen(buffer) + ft_strlen(line) + 1) * sizeof(char));
	if (!dest)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	j = -1;
	if (line)
	{
		dest = ft_append_line(line, dest, &i);
		free(line);
	}
	while (buffer[++j])
	{
		dest[i] = buffer[j];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_is_nl(char *line, int char_readed)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		++i;
	}
	if (char_readed < BUFFER_SIZE)
		return (2);
	return (0);
}
