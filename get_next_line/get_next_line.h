/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:15:17 by akowalsk          #+#    #+#             */
/*   Updated: 2021/01/27 11:15:48 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Need the following for read, malloc, free
# include <stdlib.h> // for malloc and free
# include <unistd.h> // for read

int		get_next_line(int fd, char **line);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);


// Remove the below
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strnew(size_t size);

#endif