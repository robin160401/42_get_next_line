/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:18 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/06 18:51:39 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1st allocate enough Space for the first read
// 2nd safe bytes read and start reading into find_line

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 3];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		output = ft_strjoin(output, buffer);
	}
	output = ft_createline(output);
	bytes_read = 0;
	while (buffer[bytes_read])
	{
		
	}
	return (output);
}

int	main(void)
{
	// int fd;
	
	// fd = open("my_poem.txt", O_RDONLY);
	// char	*buffer1;
	// char	*buffer2;
	// char	*buffer3;
	// char	*buffer4;

	// buffer1 = get_next_line(fd);
	// buffer2 = get_next_line(fd);
	// buffer3 = get_next_line(fd);
	// buffer4 = get_next_line(fd);
	// printf("%s", buffer1);
	// printf("%s", buffer2);
	// printf("%s", buffer3);
	// printf("%s", buffer4);
	// close(fd);
	
	int		fd;
	char	*line;

	fd = open("my_poem.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("open file failed\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
	}
	close(fd);
	return (0);
}
