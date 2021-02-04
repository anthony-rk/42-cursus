/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:17:11 by akowalsk          #+#    #+#             */
/*   Updated: 2021/02/03 22:45:41 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  
#include <fcntl.h> 

#include "get_next_line.h"

static char	*ft_append_line(char *s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (s[len] == '\n')
	{
		// printf("__static_reader inside ft_append_line(): %s\n", s);

		*line = ft_strsub(s, 0, len); // copy to line the string until the newline - good

		// printf("__line inside ft_append_line(): %s\n", *line);
		tmp = ft_strdup(&((s)[len + 1])); // sets tmp to the characters after the newline, so the extra stuff we got on read()
		// printf("__tmp inside ft_append_line(): %s\n", tmp);
		// tmp = ft_strdup(s);
		// free(s);
		s = tmp; // this move the s over past the first line we found, so we can use it on the next iteration. This is why we need static
		// printf("__static_reader inside ft_append_line(): %s\n", s);
	}
	else // this is for the first and last iteration where the buf does not read until a newline
	{
		// printf("WE ARE IN THE ELSE STATEMENT NOW BOYS\n");
		*line = ft_strdup(s);
		free(s); // free s once the string has been fully read
	}
	// return (1);
	return (s);
}

// static int ft_is_eof(char *s, char **line)
// {
// 	if (s[0] == '\0')
// 	{
// 		*line = malloc(sizeof(char) * 1);
// 		if (!(*line))
// 			return (-1);
// 		(*line)[0] = '\0';
// 	}
// 	return (0);
// }

// static int	ft_output(char *s, char **line, int ret)
// {
// 	if (ret < 0)
// 		return (-1);
// 	else if (ret == 0)
// 		return (0);
// 	else
// 		return (ft_append_line(s, line)); // case here where it return a line
// 		// return (1);
// }

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*tmp;
	
	char		buf[BUFFER_SIZE + 1];
	static char	*static_reader;

	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line) // Error checking the input
		return (-1);

	// Basic idea is to read the size of the buf, append that string to the static_reader static var, and to 
	// keep looping until we hit a new line, or EOF then return 1, 0, or -1

	// printf("\n-------------------------\n");
	// if (static_reader)
	// 	printf("__static_reader before read() loop: %s\n", static_reader);
	
	// Need a check for if we have read() everything, 


	// read() to the buf until there is a newline, store that in the static_reader
	count = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		// printf("Number of Bytes read to buf: %d\n", ret);

		buf[ret] = '\0';
	
		if (!static_reader)	// copy to the empty string on the first pass
			static_reader = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(static_reader, buf);
			if (!tmp)
				return (-1); // error handling
			static_reader = ft_strdup(tmp);
			// printf("__static_reader in read() while loop: \"%s\"\n", static_reader);
			free(tmp);
		}
		if (ft_strrchr(static_reader, '\n')) // loops for a newline
		{
			// printf("--NEWLINE FOUND--\n");
			break ;
		}
		count++;
			
	}
	// If the entire file has been read into the static_reader var, then we still need to output the 
		// line, maybe check if there is a newline?

	if (ret < 0)
		return (-1);
	else if (ret == 0)
	{
		// Check if there is still a new line or still len, so more lines to read
		if (ft_strrchr(static_reader, '\n') || (ft_strlen(static_reader) > 0))
		{	
			static_reader = ft_append_line(static_reader, line);
			return (1);
		}
		*line = malloc(sizeof(char) * 1);
		if (!(*line))
			return (-1);
		(*line)[0] = '\0';

		return (0);
	}
	else
	{
		static_reader = ft_append_line(static_reader, line);
		return (1);
	}

}
