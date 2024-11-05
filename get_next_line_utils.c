/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:56:39 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/05 13:45:07 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
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

char	*ft_createline(char *buffer)
{
	int		len;
	int		i;
	char	*output_line;

	len = 0;
	i = 0;
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (buffer[len] == '\n')
		len += 1;
	output_line = malloc(sizeof(char) * (len + 1));
	if (!output_line)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
	{
		output_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		output_line[i] = '\n';
		i++;
	}
	output_line[i] = '\0';
	return (output_line);
}

char	*ft_getremainder(char *string)
{
	int		len;
	int		len_total;
	int		i;
	char	*p;

	len = 0;
	while (string[len] != '\n' && string[len])
		len++;
	len_total = ft_strlen(string);
	if (len_total - len == 0)
		return (NULL);
	p = malloc(sizeof(char) * ((len_total - len)));
	if (!p)
		return (NULL);
	i = 0;
	len_total = 0;
	p = ft_strchr(string, '\n');
	return (p + 1);
}
