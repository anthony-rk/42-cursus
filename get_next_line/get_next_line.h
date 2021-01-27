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

int	get_next_line(int fd, char **line);

#endif