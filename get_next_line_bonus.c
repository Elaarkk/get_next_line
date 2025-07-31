/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:50:31 by acolonne          #+#    #+#             */
/*   Updated: 2024/11/25 11:58:49 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*build_line(char *buf)
{
	int			i;
	int			j;
	char		*line;

	i = 0;
	j = 0;
	if (!buf[i])
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (j < i + 1)
	{
		line[j] = buf[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*buffer_remainder(char *buf)
{
	int		i;
	int		j;
	char	*buf_remainder;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	buf_remainder = malloc(ft_strlen(buf) - i + 1);
	if (!buf_remainder)
		return (NULL);
	i++;
	while (buf[i])
		buf_remainder[j++] = buf[i++];
	buf_remainder[j] = '\0';
	free(buf);
	return (buf_remainder);
}

char	*read_file(char *buf, int fd)
{
	char		*line;
	int			nbytes;

	nbytes = 1;
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (0);
	ft_bzero(line, BUFFER_SIZE + 1);
	while (nbytes > 0 && !(ft_strchr(line, '\n')))
	{
		nbytes = read(fd, line, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free (line);
			free(buf);
			return (NULL);
		}
		line[nbytes] = '\0';
		buf = ft_strjoin(buf, line);
	}
	free(line);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[2048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 2048)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = malloc(BUFFER_SIZE + 1);
		if (!buf[fd])
			return (NULL);
		ft_bzero(buf[fd], BUFFER_SIZE + 1);
	}
	buf[fd] = read_file(buf[fd], fd);
	if (!buf[fd])
		return (NULL);
	line = build_line(buf[fd]);
	buf[fd] = buffer_remainder(buf[fd]);
	return (line);
}
