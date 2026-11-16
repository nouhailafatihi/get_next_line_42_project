/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfatihi <nfatihi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:26:28 by nfatihi           #+#    #+#             */
/*   Updated: 2026/11/16 14:12:24 by nfatihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int					i;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s, int start)
{
	size_t	n;

	n = 0;
	while (s[start] != '\0')
	{
		start++;
		n++;
	}
	return (n);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (s2);
	r = malloc((ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1));
	if (r == NULL)
		return (free(s1), free(s2), NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j])
		r[i++] = s2[j++];
	r[i] = '\0';
	free(s1);
	free(s2);
	return (r);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (!s || start > ft_strlen(s, 0))
		return (NULL);
	r = malloc(len + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		r[i++] = s[start++];
	r[i] = '\0';
	return (r);
}
