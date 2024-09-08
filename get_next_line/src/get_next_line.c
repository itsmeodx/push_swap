/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:46:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/28 02:34:41 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_and_append(char **line, int fd)
{
	char		*buff;
	int			count;

	count = 1;
	buff = ft_strnew(BUFFER_SIZE);
	while (count > 0 && !ft_alt_strchr(*line, '\n'))
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free(buff);
			*line = NULL;
			return ;
		}
		buff[count] = '\0';
		*line = ft_alt_strjoin(*line, buff);
	}
	free(buff);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;
	int			i;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (free(line), NULL);
	read_and_append(&line, fd);
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		str = ft_alt_strsub(line, 0, i, 0);
		free(line);
		line = NULL;
		return (str);
	}
	str = ft_alt_strsub(line, 0, i + 1, 0);
	line = ft_alt_strsub(line, i + 1, ft_alt_strlen(line) - i, 1);
	if (!line)
		return (NULL);
	return (str);
}
