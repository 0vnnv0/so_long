/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:34:31 by anschmit          #+#    #+#             */
/*   Updated: 2024/07/15 11:46:52 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*full_str[666];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	full_str[fd] = ft_read(fd, full_str[fd]);
	if (!full_str[fd])
		return (NULL);
	line = ft_getline(full_str[fd]);
	full_str[fd] = ft_getrest(full_str[fd]);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && (read_bytes != 0))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), NULL);
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_getline(char *full_str)
{
	int		i;
	char	*line;

	i = 0;
	if (!full_str[i])
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getrest(char *full_str)
{
	char	*restofstr;
	int		i;
	int		j;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (!full_str[i])
		return (free(full_str), NULL);
	restofstr = malloc(sizeof(char) * (ft_strlen(full_str) - i + 1));
	if (!restofstr)
		return (NULL);
	i++;
	j = 0;
	while (full_str[i])
		restofstr[j++] = full_str[i++];
	restofstr[j] = '\0';
	free(full_str);
	return (restofstr);
}
