/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:17:11 by akowalsk          #+#    #+#             */
/*   Updated: 2021/01/27 11:17:26 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Start at 330pm Friday

// #include <stdlib.h> 
// #include <unistd.h>
#include <stdio.h>  
#include <fcntl.h> 

#include "get_next_line.h"

// #define BUFFER_SIZE 100

// FIND LENGTH OF NEXT LINE
static int	ft_fdstrlen(char *buf)
{
	int		len;

	len = 0;
	printf("Line from ft_fdstrlen is = %s\n", buf);
	while (buf[len] != '\n' && buf[len] != '\0' && buf[len] != EOF)
	{
		len++;
		printf("Len from ft_fdstrlen is: %d\n", len);
	}
	return (len + 1);
}

int		get_next_line(int fd, char **line)
{
	char	*new_line;
	int		next_line_len;
	int		num_line;
	char	buf[BUFFER_SIZE + 1];

	if (fd < 0)
		return (-1);

	// Read the entire buf here
	read(fd, buf, BUFFER_SIZE);

	num_line = 0;

	next_line_len = ft_fdstrlen(buf);

	printf("New_Line length = %d\n", next_line_len);

	if (next_line_len < BUFFER_SIZE)
	{
		if (!(new_line = (char *)malloc((next_line_len + 1) * sizeof(char))))
			return (-1);
		ft_strlcpy(new_line, buf, next_line_len);

		line = &new_line;

		printf("new_line: %s\n", new_line);
		printf("line: %s\n", *line);
		// free(new_line);
	}
	return (1);
}
