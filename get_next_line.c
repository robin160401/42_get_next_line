/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:18 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/07 10:53:22 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1st allocate enough Space for the first read
// 2nd safe bytes read and start reading into find_line

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*output;
	int			i;

	output = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!output)
	{
		output = malloc(1 * sizeof(char));
		if (!output)
			return (NULL);
		output[0] = '\0';
	}
	output = ft_strjoin(output, leftover);
	if (!output)
		return (NULL);
	while (!ft_strchr(output, '\n'))
	{
		bytes_read = read(fd, leftover, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (leftover[0] == 0)
				return (NULL);
			ft_bzero(leftover, BUFFER_SIZE + 1);
			i = 0;
			while (output[bytes_read] != '\n' && output[bytes_read])
				bytes_read++;
			while (output[bytes_read])
			{
				leftover[i] = output[bytes_read + 1];
				i++;
				bytes_read++;
			}
			output = ft_createline(output);
			if (!output)
				return (NULL);
			return (output);
		}
		leftover[bytes_read] = '\0';
		output = ft_strjoin(output, leftover);
		if (!output)
			return (NULL);
	}
	output = ft_createline(output);
	if (!output)
		return (NULL);
	bytes_read = 0;
	i = 0;
	while (leftover[bytes_read] != '\n' && leftover[bytes_read])
		bytes_read++;
	while (leftover[bytes_read])
	{
		leftover[i] = leftover[bytes_read + 1];
		i++;
		bytes_read++;
	}
	return (output);
}

// int	main(void)
// {
// 	// int fd;
	
// 	// fd = open("my_poem.txt", O_RDONLY);
// 	// char	*buffer1;
// 	// char	*buffer2;
// 	// char	*buffer3;
// 	// char	*buffer4;

// 	// buffer1 = get_next_line(fd);
// 	// buffer2 = get_next_line(fd);
// 	// buffer3 = get_next_line(fd);
// 	// buffer4 = get_next_line(fd);
// 	// printf("%s", buffer1);
// 	// printf("%s", buffer2);
// 	// printf("%s", buffer3);
// 	// printf("%s", buffer4);
// 	// close(fd);
	
// 	int		fd;
// 	char	*line;

// 	fd = open("my_poem.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("open file failed\n");
// 		exit(1);
// 	}
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 	}
// 	close(fd);
// 	return (0);
// }
