/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:33:36 by akowalsk          #+#    #+#             */
/*   Updated: 2021/02/06 13:33:38 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line_bonus.h"

// static int	ft_append_line(char **s, char **line)
// {
// 	int		len;
// 	char	*tmp;

// 	len = 0;
// 	while ((*s)[len] != '\n' && (*s)[len] != '\0')
// 		len++;
// 	if ((*s)[len] == '\n')
// 	{
// 		*line = ft_substr(*s, 0, len);
// 		tmp = ft_strdup(&((*s)[len + 1]));
// 		free(*s);
// 		*s = tmp;
// 	}
// 	else
// 	{
// 		*line = ft_strdup(*s);
// 		// free(*s);
// 		// return (0);
// 		*s = NULL;
// 	}
// 	return (1);
// }

// static int	ft_final_read(char **line)
// {
// 	*line = malloc(sizeof(char) * 1);
// 	if (!(*line))
// 		return (-1);
// 	(*line)[0] = '\0';

// 	return (0);
// }

// static char	*ft_read_til_nl(char *s, char *buf, int ret)
// {
// 	char		*tmp;

// 	buf[ret] = '\0';
// 	if (!s)
// 		s = ft_strdup(buf);
// 	else
// 	{
// 		tmp = ft_strjoin(s, buf);
// 		s = ft_strdup(tmp);
// 		free(tmp);
// 	}
// 	return (s);
// }

// int		get_next_line(int fd, char **line)
// {
// 	int			ret;
// 	char		buf[BUFFER_SIZE + 1];
// 	static char	*static_reader;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
// 		return (-1);
// 	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
// 	{
// 		static_reader[fd] = *ft_read_til_nl(&static_reader[fd], buf, ret);
// 		if (ft_strrchr(&static_reader[fd], '\n'))
// 			break ;
// 	}
// 	if (ret < 0)
// 		return (-1);
// 	else if (ret == 0 && (&static_reader[fd] == NULL))
// 	{
// 		// free(static_reader[fd]);
// 		return (ft_final_read(line));
// 	}
// 	else
// 		return (ft_append_line(&static_reader[fd], line));
// }
#include "get_next_line_bonus.h"

static int	ft_append_line(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = malloc(sizeof(char) * 1);
		if (!(*s))
			return (-1);
		(*s)[0] = '\0';
	}
	return (1);
}

static int	ft_final_read(char **line)
{
	*line = malloc(sizeof(char) * 1);
	if (!(*line))
		return (-1);
	(*line)[0] = '\0';

	return (0);
}

static char	*ft_read_til_nl(char *s, char *buf, int ret)
{
	char		*tmp;

	buf[ret] = '\0';
	if (!s)
		s = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(s, buf);
		s = ft_strdup(tmp);
		free(tmp);
	}
	return (s);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*static_reader[1000];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		static_reader[fd] = ft_read_til_nl(static_reader[fd], buf, ret);
		if (ft_strrchr(static_reader[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (static_reader[fd] == NULL))
		return (ft_final_read(line));
	else if (ret == 0 && (static_reader[fd][0] == '\0'))
	{
		free(static_reader[fd]);
		return (ft_final_read(line));
	}
	else
		return (ft_append_line(&static_reader[fd], line));
}
