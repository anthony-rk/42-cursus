#Makefile - Comment

# CC=gcc #compiler
# CFLAGS=-Wall -Werror -Wextra
# OBJFILES =*.o #$(SRC1:.c=.o)
# DEPS=libft.h
# NAME=libft.a #target file name

# SRC=*.c

# SRC2=part2/*.c
# SRCBONUS=bonus_part/*.c
# SCRADDITIONAL=additional/*.c

# all:	$(NAME)

# $(NAME): $(SRC) #$(OBJFILES)
# 	$(CC) $(CFLAGS) -c $(SRC) 
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJFILES)

# clean:
# 	rm -f $(OBJFILES) 

# fclean: clean
# 		rm -f $(NAME) *~

# re:		fclean all

# .PHONY: all clean fclean re

# +++++++++++++++++++++++++++++++++++++++++++++++++++++



# 	#Makefile - Comment

# CC=gcc #compiler
# CFLAGS=-Wall -Werror -Wextra
# LDFLAGS=
# OBJFILES = 	*.o #$(SRC1:.c=.o)
# DEPS=libft.h
# NAME=main #target file name

# SRC1=part1/*.c
# SRC2=part2/*.c
# SRCBONUS=bonus_part/*.c
# SCRADDITIONALFUNCTIONS=additional_functions/*.c

# all:	$(NAME)

# $(NAME): $(SRC1) #$(OBJFILES)
# 	$(CC) $(CFLAGS) -c $(SRC1) $(SRCADDITIONALFUNCTIONS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJFILES) $(LDFLAGS)

# clean:
# 	rm -f $(OBJFILES) 

# fclean: clean
# 		rm -f $(NAME) *~

# re:		fclean all

# .PHONY: all clean fclean re

# From: https://github.com/martynyk1994/42/blob/master/Makefile
NAME = libft.a

# SRCs=*.c
SRCS =	ft_strlen.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_calloc.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
		ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		

# SRCS =	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
# 		ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c\
# 		ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
# 		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
# 		ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
# 		ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c\
# 		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_putchar.c\
# 		ft_putstr.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
# 		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
# 		ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
# 		ft_putendl_fd.c ft_putnbr_fd.c ft_swap.c ft_max.c ft_min.c\
# 		ft_strupcase.c ft_strlowcase.c ft_itoa.c ft_lstnew.c ft_lstdelone.c\
# 		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c -I. $(SRCS) 
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
