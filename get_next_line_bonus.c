/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:18 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/07 15:57:19 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// 1st allocate enough Space for the first read
// 2nd safe bytes read and start reading into find_line

char	*ft_read_line(int fd, char *output, char *leftover)
{
	ssize_t		bytes_read;
	char		*temp;

	while (!ft_strchr(output, '\n'))
	{
		bytes_read = read(fd, leftover, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (leftover[0] == 0)
				return (free(output), output = NULL, NULL);
			ft_bzero(leftover, BUFFER_SIZE + 1);
			temp = ft_createline(output);
			free(output);
			return (temp);
		}
		if (bytes_read == -1)
			return (free(output), ft_bzero(leftover, BUFFER_SIZE + 1), NULL);
		leftover[bytes_read] = '\0';
		temp = ft_strjoin(output, leftover);
		free(output);
		if (!temp)
			return (NULL);
		output = temp;
	}
	return (output);
}

void	ft_update_leftover(char *leftover)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (leftover[i] != '\n' && leftover[i])
		i++;
	while (leftover[i])
	{
		leftover[j] = leftover[i + 1];
		i++;
		j++;
	}
	leftover[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	leftover[1024][BUFFER_SIZE + 1];
	char		*output;
	char		*new_output;

	output = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	output = ft_strjoin("", leftover[fd]);
	if (!output)
		return (NULL);
	output = ft_read_line(fd, output, leftover[fd]);
	if (!output)
		return (NULL);
	new_output = ft_createline(output);
	free(output);
	output = NULL;
	if (!new_output)
		return (NULL);
	ft_update_leftover(leftover[fd]);
	return (new_output);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("my_poem.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Failed to open file");
// 		exit(1);
// 	}
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("Test fuer null: %s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
