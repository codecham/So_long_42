/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:13:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:13:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_display_number(char *str, int tmp, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (tmp < 0 && flags.dot >= 0)
		ft_putchar_pf('-');
	if (flags.dot >= 0)
		char_count += ft_flags_display(flags.dot - 1,
				ft_strlen(str) - 1, 1);
	char_count += ft_putstrn(str, ft_strlen(str));
	return (char_count);
}

static int	ft_treat_int(char *str, int tmp, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_display_number(str, tmp, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_flags_display(flags.width, 0, 0);
	}
	else if (flags.zero == 1 && flags.minus == 0)
		char_count += ft_flags_display(flags.width, ft_strlen(str), 1);
	else
		char_count += ft_flags_display(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_display_number(str, tmp, flags);
	return (char_count);
}

int	ft_print_int(int nbr, t_flags flags)
{
	char	*str;
	int		char_count;
	long	tmp;

	char_count = 0;
	tmp = (long)nbr;
	if (flags.dot == 0 && nbr == 0)
	{
		char_count += ft_flags_display(flags.width, 0, 0);
		return (char_count);
	}
	if (nbr < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if ((flags.zero == 1 && flags.dot == -1)
			|| (flags.stardot == 1 && flags.dot < 0))
			ft_putstrn("-", 1);
		tmp *= -1;
		flags.width--;
		char_count++;
	}
	str = ft_litoa(tmp);
	char_count += ft_treat_int(str, nbr, flags);
	free(str);
	return (char_count);
}
