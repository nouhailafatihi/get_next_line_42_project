/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfatihi <nfatihi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:25:35 by nfatihi           #+#    #+#             */
/*   Updated: 2026/11/16 15:11:19 by nfatihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		*ar[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ar[fd] = fillar(fd, ar[fd]);
	if (ar[fd] == NULL || ar[fd][0] == '\0')
		return (free(ar[fd]), NULL);
	i = 0;
	while (ar[fd][i] != '\n' && ar[fd][i] != '\0')
		i++;
	line = ft_substr(ar[fd], 0, i + 1);
	left = ft_substr(ar[fd], i + 1, ft_strlen(ar[fd], i));
	free(ar[fd]);
	ar[fd] = left;
	return (line);
}
