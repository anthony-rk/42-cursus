# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 13:49:19 by akowalsk          #+#    #+#              #
#    Updated: 2020/11/22 13:49:23 by akowalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_strlen.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_calloc.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
		ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strdup.c\
		ft_strrchr.c ft_strnstr.c ft_strlcat.c ft_strlcpy.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
	
BONUSSRCS =	ft_strlen.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_calloc.c\
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
			ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strdup.c\
			ft_strrchr.c ft_strnstr.c ft_strlcat.c ft_strlcpy.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(SRCS:.c=.o)

BONUSOBJECTS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c -I. $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus:
	@gcc -Wall -Wextra -Werror -c -I. $(BONUSSRCS)
	@ar rc $(NAME) $(BONUSSRCS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) $(BONUSOBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
