/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:07:37 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:07:38 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags	ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int	ft_flag_dot(const char *input, int start,
t_flags *flags, va_list args)
{
	int	i;

	i = start;
	i++;
	if (input[i] == '*')
	{
		flags->dot = va_arg(args, int);
		flags->stardot = 1;
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(input[i]))
			flags->dot = (flags->dot * 10) + (input[i++] - '0');
	}
	return (i);
}
