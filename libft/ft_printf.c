/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:14:25 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:14:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.type = 0;
	flags.stardot = 0;
	return (flags);
}

static int	ft_treat_save(const char *input, va_list args)
{
	int		i;
	int		char_count;
	t_flags	flags;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!input[i])
			break ;
		else if (input[i] == '%' && input[i + 1])
		{
			i = ft_flag(input, ++i, &flags, args);
			if (ft_type_list(input[i]))
				char_count += ft_print_var(flags.type, flags, args);
			else if (input[i])
				char_count += ft_putchar_pf(input[i]);
		}
		else if (input[i] != '%')
			char_count += ft_putchar_pf(input[i]);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	int				char_count;

	char_count = 0;
	va_start(args, input);
	char_count = char_count + ft_treat_save(input, args);
	va_end(args);
	return (char_count);
}
