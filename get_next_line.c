/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:18 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/29 16:26:30 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
	
// }

int	main(void)
{
	int		fd;
	char	buffer[100];
	ssize_t	bytes_read;

	fd = open("my_poem.txt", O_RDONLY);
	bytes_read = read(fd, buffer, 3);
	buffer[bytes_read] = '\0';
	printf("%s", buffer);
	close(fd);
	return (0);
}