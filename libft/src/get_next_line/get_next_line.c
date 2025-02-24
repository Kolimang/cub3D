/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:55:01 by ngharian          #+#    #+#             */
/*   Updated: 2023/12/29 14:40:09 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_get_remainder(char *line, int i)
{
	int		j;
	int		len;
	int		k;
	char	*dest;

	k = i + 1;
	len = 0;
	while (line[++i])
		++len;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (line[k])
	{
		dest[j] = line[k];
		++ j;
		++ k;
	}
	dest[j] = '\0';
	return (dest);
}

static char	*ft_polish(char *line, char ***remainder, int char_readed)
{
	int		i;
	char	*dest;
	int		j;

	if (ft_is_nl(line, char_readed) == 2)
		return (line);
	i = 0;
	while (line[i] && line[i] != '\n')
		++i;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
	{
		free(line);
		return (NULL);
	}
	j = 0;
	while (line[j] && i >= j)
	{
		dest[j] = line[j];
		++j;
	}
	dest[j] = '\0';
	**remainder = ft_get_remainder(line, i);
	free(line);
	return (dest);
}

static char	*ft_get_line(char *line, char **remainder, int fd, char *buffer)
{
	int		char_readed;

	while (1)
	{
		char_readed = read(fd, buffer, BUFFER_SIZE);
		line = ft_join(buffer, line, char_readed);
		if (!line || line[0] == '\0' || char_readed < 0)
		{
			free(line);
			return (NULL);
		}
		if (ft_is_nl(line, char_readed))
		{
			line = ft_polish(line, &remainder, char_readed);
			break ;
		}
	}
	return (line);
}

static char	*ft_verify(int fd)
{
	char	*dest;

	if (fd < 0 || fd > FD_SETSIZE || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > 2147483647 || read(fd, &dest, 0) < 0)
		return (NULL);
	dest = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;
	char		*buffer;

	buffer = ft_verify(fd);
	if (!buffer)
	{
		if (remainder)
		{
			free(remainder);
			remainder = NULL;
		}
		return (NULL);
	}
	if (remainder)
	{
		line = remainder;
		remainder = NULL;
	}
	else
		line = NULL;
	line = ft_get_line(line, &remainder, fd, buffer);
	free(buffer);
	return (line);
}
