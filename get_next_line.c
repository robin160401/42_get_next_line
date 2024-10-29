/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:18 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/29 16:05:56 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// char	*get_next_line(int fd)
// {
// }

int	main(void)
{
	FILE	*fptr;
	char	myString[100];

	fptr = fopen("my_poem.txt", "r");
	if (fptr != NULL)
		while (fgets(myString, 3, fptr))
			printf("%s", myString);
	else
		printf("Not able to open the file.");
	fclose(fptr);
}