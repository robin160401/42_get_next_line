/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:18 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/02 16:32:40 by rstumpf          ###   ########.fr       */
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
	char		*output;

	if (!buffer)
		buffer = "";
	while (buffer && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, find_line, BUFFER_SIZE);
		if (bytes_read == 0)
			return (buffer);
		find_line[bytes_read] = '\0';
		temp = ft_strjoin(buffer, find_line);
		if (!temp && buffer)
			free(buffer);
		buffer = temp;
	}
	output = ft_createline(buffer, '\n');
	buffer = ft_getremainder(buffer, '\n');
	return (output);
}

int	main(void)
{
	int		fd;
	char	*buffer1;
	char	*buffer2;
	char	*buffer3;
	char	*buffer4;

	fd = open("my_poem.txt", O_RDONLY);
	buffer1 = get_next_line(fd);
	buffer2 = get_next_line(fd);
	// buffer3 = get_next_line(fd);
	// buffer4 = get_next_line(fd);
	printf("%s", buffer1);
	printf("%s", buffer2);
	// printf("%s", buffer3);
	// printf("%s", buffer4);
	close(fd);
	return (0);
}
