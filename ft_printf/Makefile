# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 16:22:31 by akowalsk          #+#    #+#              #
#    Updated: 2021/03/10 02:14:31 by akowalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	./source/ft_analyze_input.c\
		./source/ft_check_conversion_char.c\
		./source/ft_check_flags.c\
		./source/ft_check_precis.c\
		./source/ft_check_width.c\
		./source/ft_init_flags_struct.c\
		./source/ft_printf.c\
		./source/ft_solve_c_output.c\
		./source/ft_solve_di_output.c\
		./source/ft_solve_p_output.c\
		./source/ft_solve_percent_output.c\
		./source/ft_solve_s_output.c\
		./source/ft_solve_u_output.c\
		./source/ft_solve_xx_output.c\
		./source/ft_solver_base.c\

OBJECTS = ./ft_analyze_input.o\
		./ft_check_conversion_char.o\
		./ft_check_flags.o\
		./ft_check_precis.o\
		./ft_check_width.o\
		./ft_init_flags_struct.o\
		./ft_printf.o\
		./ft_solve_c_output.o\
		./ft_solve_di_output.o\
		./ft_solve_p_output.o\
		./ft_solve_percent_output.o\
		./ft_solve_s_output.o\
		./ft_solve_u_output.o\
		./ft_solve_xx_output.o\
		./ft_solver_base.o\


all: $(NAME)

$(NAME):
	@make re -C ./libft
	@cp ./libft/libft.a ./${NAME}
	@gcc -Wall -Wextra -Werror -c -I. $(SRCS)
	@ar -rc $(NAME) $(OBJECTS)

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME) libft.a
	@/bin/rm -f $(OBJECTS)
	@make fclean -C ./libft

re: fclean all
