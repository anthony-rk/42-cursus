/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:38:37 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:08:20 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_flags
{
	int				width;
	int				precision;
	int				total_length;
	int				point;
	int				zero;
	int				minus;
	char			type;
}					t_flags;

void				ft_analyze_input(char *p, t_flags *flags, va_list arg_ptr);
int					ft_check_conversion_char(char *p, t_flags *flags);
int					ft_check_flags(char *p, t_flags *flags);
int					ft_check_precis(char *p, t_flags *flags, va_list arg_ptr);
int					ft_check_width(char *p, t_flags *flags, va_list arg_ptr);
t_flags				ft_init_flags_struct(void);
int					ft_printf(const char *format, ...);
void				ft_solve_c_output(t_flags *flags, va_list arg_ptr);
void				ft_solve_di_output(t_flags *flags, va_list arg_ptr);
void				ft_solve_p_output(t_flags *flags, va_list arg_ptr);
void				ft_solve_percent_output(t_flags *flags);
void				ft_solve_s_output(t_flags *flags, va_list arg_ptr);
void				ft_solve_u_output(t_flags *flags, va_list arg_ptr);
void				ft_solve_xx_output(t_flags *flags, va_list arg_ptr);
void				ft_solver_base(t_flags *flags, va_list arg_ptr);

#endif
