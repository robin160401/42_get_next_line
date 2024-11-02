/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:18 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/02 13:36:31 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1st allocate enough Space for the first read
// 2nd safe bytes read and start reading into find_line

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		find_line[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	buffer = "";
	while (buffer)
	{
		bytes_read = read(fd, find_line, BUFFER_SIZE);
		find_line[bytes_read] = '\0';
		temp = ft_strjoin(buffer, find_line);
		buffer = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("my_poem.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	close(fd);
	return (0);
}
