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

#include <stdio.h>  
#include <fcntl.h> 

#include "get_next_line.h"

static int	ft_append_line(char *s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (s[len] == '\n')
	{
		*line = ft_strsub(s, 0, len); // Need to change this 0 here
		tmp = ft_strdup(&((s)[len + 1]));
		// tmp = ft_strdup(s);
		// free(s);
		s = tmp; // this move the s over past the first line we found, so we can use it on the next iteration. Need static
	}
	else // think this is for the first iteration where the buf does not read until a newline
	{
		*line = ft_strdup(s);
		// free(s);
	}
	return (1);
}

static int	ft_output(char *s, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0)
		return (0);
	else
		return (ft_append_line(s, line)); // case here where it return a line
		// return (1);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*tmp;
	
	char		buf[BUFFER_SIZE + 1];
	static char	*static_reader;

	// char		*static_reader;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line) // Error checking the input
		return (-1);

	// Basic idea is to read the size of the buf, append that string to the static_reader static var, and to 
	// keep looping until we hit a new line, or EOF then return 1, 0, or -1

	// while ((ret = read(fd, buf, BUFFER_SIZE)) >= 0 && ft_has_nl(buf) != 1) // where do I check for the newline?
	count = 0;
	// static_reader = NULL;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0) 
	{
		printf("Number of Bytes read to buf: %d\n", ret);

		buf[ret] = '\0'; // Null terminate the buf string
	
		if (!static_reader)	// copy to the empty string on the first pass
			static_reader = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(static_reader, buf);
			if (!tmp)
				return (-1); // error handling
			printf("static_reader: \"%s\"\n", static_reader);
			// free(static_reader); // cannot free a static variable, as it is in the heap and not the stack, not done with malloc
			printf("static_reader: \"%s\"\n", static_reader);
			// static_reader = ft_strdup(tmp);
			static_reader = tmp;
			printf("static_reader: \"%s\"\n", static_reader);
			free(tmp);
		}
		if (ft_strrchr(static_reader, '\n'))
		{
			printf("\n--NEWLINE FOUND--\n");
			break ;
		}
		count++;
			
	}
	printf("__Buf Read Loops: %d\n", count + 1);
	// printf("static_reader: \"%s\"\n", static_reader);
	
	// *line = static_reader;

	// printf("line: \"%s\"\n", *line);
	// printf("static_reader: \"%s\"\n", static_reader);

	return (ft_output(static_reader, line, ret));

}
