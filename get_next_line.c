/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfatihi <nfatihi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:27:15 by nfatihi           #+#    #+#             */
/*   Updated: 2026/11/16 14:12:04 by nfatihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fillar(int fd, char *ar)
{
	ssize_t	fdr;
	char	*buf;

	while (!ar || !ft_strchr(ar, '\n'))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		fdr = read(fd, buf, BUFFER_SIZE);
		if (fdr == 0)
			return (free(buf), ar);
		if (fdr == -1)
			return (free(ar), free(buf), NULL);
		buf[fdr] = '\0';
		ar = ft_strjoin(ar, buf);
		if (ar == NULL)
			break ;
	}
	return (ar);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*left;
	unsigned int	i;
	static char		*ar;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ar = fillar(fd, ar);
	if (ar == NULL || ar[0] == '\0')
		return (free(ar), NULL);
	i = 0;
	while (ar[i] != '\n' && ar[i] != '\0')
		i++;
	line = ft_substr(ar, 0, i + 1);
	left = ft_substr(ar, i + 1, ft_strlen(ar, i));
	free(ar);
	ar = left;
	return (line);
}
