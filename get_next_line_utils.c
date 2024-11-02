/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:56:39 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/02 15:22:23 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	p = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (*string != '\0')
	{
		string++;
		i++;
	}
	return (i);
}

char	*ft_createline(char *string, int c)
{
	int		len;
	char	*p;

	len = 0;
	while (string[len] != c && string[len])
		len++;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (*string != c && *string)
	{
		*p = *string;
		p++;
		string++;
	}
	*p = '\n';
	p++;
	*p = '\0';
	return (p - (len + 1));
}
