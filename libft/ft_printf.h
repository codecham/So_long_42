/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:14:35 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:14:36 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	star;
	int	type;
	int	stardot;

}				t_flags;

int					ft_printf(const char *input, ...);
int					ft_putchar_pf(int c);
int					ft_char_to_int(char c);
int					ft_flags_list(char c);
int					ft_type_list(char c);
int					ft_putstr(char *str);
int					ft_putstrn(char *str, int n);
int					ft_flag(const char *save, int i, t_flags *flags,
						va_list args);
int					ft_flag_dot(const char *save, int start, t_flags *flags,
						va_list args);
int					ft_flags_display(int size, int minus, int type);
int					ft_print_int(int nbr, t_flags flags);
int					ft_print_unsigned_int(unsigned int nbr, t_flags flags);
int					ft_print_pointer(unsigned long long p, t_flags flags);
int					ft_print_hexa(unsigned int nbr, int type, t_flags flags);
int					ft_print_char(int c, t_flags flags);
int					ft_print_string(char *str, t_flags flags);
int					ft_print_pourcent(t_flags flags);
int					ft_print_var(char type, t_flags flags, va_list args);
int					ft_print_pourcent(t_flags flags);
char				*ft_itoa_hexa(unsigned long long nbr, int type);
char				*ft_uitoa(unsigned long long nb);
char				*ft_litoa(long nb);
t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);
t_flags				ft_flag_width(va_list args, t_flags flags);

#endif
