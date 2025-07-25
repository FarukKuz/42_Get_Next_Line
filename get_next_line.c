/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:36:24 by fakuz             #+#    #+#             */
/*   Updated: 2025/07/25 19:35:22 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*readed;
	ssize_t		index;
	char		*line;

	while (strchr(readed) != '\n')
	{
		index = read(fd, buffer, BUFFER_SIZE);
		strjoin(buffer, readed);
		buffer[index] = 0;
	}
	line = //newline a kadar olan kısım
	readed = /*yukarıdaki linenın eskilmiş hali (substr)*/ 12;
	return(line);
}
