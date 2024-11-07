/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:56:39 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/07 15:57:10 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	if (!s1 || !s2)
		return (NULL);
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
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
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

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}
