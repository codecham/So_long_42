/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:13:24 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:13:25 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_display_hexa(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_flags_display(flags.dot - 1, ft_strlen(str) - 1, 1);
	char_count += ft_putstrn(str, ft_strlen(str));
	return (char_count);
}

static int	ft_treat_hexa(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_display_hexa(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_flags_display(flags.width, 0, 0);
	}
	else if ((flags.minus == 1 || flags.width > 0) && flags.zero == 0)
		char_count += ft_flags_display(flags.width, ft_strlen(str), 0);
	else if (flags.star == 1 && flags.minus == 1)
		char_count += ft_flags_display(flags.width, ft_strlen(str), 0);
	else
		char_count += ft_flags_display(flags.width, ft_strlen(str), 1);
	if (flags.minus == 0)
		char_count += ft_display_hexa(str, flags);
	return (char_count);
}

int	ft_print_hexa(unsigned int nbr, int type, t_flags flags)
{
	int		char_count;
	char	*str;

	char_count = 0;
	if (flags.dot == 0 && nbr == 0)
	{
		char_count += ft_flags_display(flags.width, 0, 0);
		return (char_count);
	}
	str = ft_itoa_hexa(nbr, type);
	char_count += ft_treat_hexa(str, flags);
	free(str);
	return (char_count);
}
