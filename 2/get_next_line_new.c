/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:59:57 by fakuz             #+#    #+#             */
/*   Updated: 2025/09/10 18:29:38 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*read_line(int fd, char **dest, char *readed_part)
{
	char	*buf;
	ssize_t	readed_len;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	readed_len = 1;
	while (readed_len > 0)
	{
		if (!has_new_line(readed_part))
			readed_len = read(fd, buf, BUFFER_SIZE);
		if (readed_len <= 0)
		{
			free(readed_part);
			return (NULL);
		}
		buf[readed_len + 1] = '\0';
		tmp = ft_strjoin(readed_part, buf);
		readed_part = tmp;
		return_line(dest, readed_part);
		free(dest);
	}
	return (readed_part);
}

void	return_line(char **str, char *readed_part)
{
	char	*dest;
	int		i;

	i = 0;
	while (readed_part[i] && readed_part[i] != '\n')
		i++;
	if (readed_part[i] == '\0')
		i--;
	ft_substr(*str, 0, i);
}

char	*get_next_line(int fd)
{
	static char	*readed_part;
	char		*dest;

	readed_part = read_line(fd, &dest, readed_part);
	return (dest);
}
