/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:49:34 by fakuz             #+#    #+#             */
/*   Updated: 2025/08/30 20:31:41 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *readed_part)
{
	char	*buf;
	ssize_t	readed_len;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	readed_len = 1;
	while (!ft_strchr(readed_part, '\n') && readed_len > 0)
	{
		readed_len = read(fd, buf, BUFFER_SIZE);
		if (readed_len < 0)
		{
			free(readed_part);
			return (NULL);
		}
		if (readed_len == 0)
			break ;
		buf[readed_len] = '\0';
		tmp = ft_strjoin(readed_part, buf);
		free(readed_part);
		readed_part = tmp;
	}
	free(buf);
	return (readed_part);
}

static char	*selected_line(char *readed_part)
{
	size_t	addr_nl_index;
	size_t	i;

	if (!readed_part || !*readed_part)
		return (NULL);
	addr_nl_index = ft_strchr(readed_part, '\n');
	i = 0;
	while (readed_part[i])
	{
		if (addr_nl_index)
			return (ft_substr(readed_part, 0, addr_nl_index + 1));
		i++;
	}
	return (ft_substr(readed_part, 0, i));
}

static char	*update_readed(char *readed_part)
{
	size_t	addr_nl_index;
	char	*rest;

	if (!readed_part)
		return (NULL);
	addr_nl_index = ft_strchr(readed_part, '\n');
	if (!addr_nl_index)
	{
		free(readed_part);
		return (NULL);
	}
	rest = ft_substr(readed_part, addr_nl_index + 1, ft_strlen(readed_part));
	free(readed_part);
	if (!rest && !*rest)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*readed_part;
	char		*dest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(readed_part), NULL);
	readed_part = read_line(fd, readed_part);
	if (!readed_part)
		return (NULL);
	dest = selected_line(readed_part);
	readed_part = update_readed(readed_part);
	return (dest);
}
