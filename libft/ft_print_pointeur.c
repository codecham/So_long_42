/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointeur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:13:42 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:13:43 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_display_pointer(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	char_count += ft_putstrn("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += ft_flags_display(flags.dot, ft_strlen(str), 1);
		char_count += ft_putstrn(str, flags.dot);
	}
	else
		char_count += ft_putstrn(str, ft_strlen(str));
	return (char_count);
}

static int	ft_display_null(t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot < flags.width)
		flags.dot = flags.width;
	if (flags.minus == 0)
		char_count = ft_flags_display(flags.dot, 2, 0);
	char_count = ft_putstrn("0x", 2);
	if (flags.minus == 1)
		char_count = ft_flags_display(flags.dot, 2, 0);
	return (char_count);
}

int	ft_print_pointer(unsigned long long p, t_flags flags)
{
	char	*str;
	int		char_count;

	char_count = 0;
	if (p == 0 && (flags.dot >= 0 || (flags.star == 1 && flags.width == 0)))
		ft_display_null(flags);
	else
	{
		str = ft_itoa_hexa(p, 0);
		if ((size_t)flags.dot < ft_strlen(str))
			flags.dot = ft_strlen(str);
		if (flags.minus == 1)
			char_count += ft_display_pointer(str, flags);
		char_count += ft_flags_display(flags.width, ft_strlen(str) + 2, 0);
		if (flags.minus == 0)
			char_count += ft_display_pointer(str, flags);
		free(str);
	}
	return (char_count);
}
