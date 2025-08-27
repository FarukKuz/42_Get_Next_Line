/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:50:54 by fakuz             #+#    #+#             */
/*   Updated: 2025/08/27 09:43:58 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*dest;
	int		j;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	len2;

	if (!s || ft_strlen(s) < start)
		return (ft_strdup(""));
	len2 = ft_strlen(s);
	if (len > len2 - start)
		len = len2 - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (0);
}
