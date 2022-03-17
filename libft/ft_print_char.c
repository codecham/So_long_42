/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:13:17 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:13:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.width > 1)
	{
		if (flags.minus == 0)
		{
			char_count += ft_flags_display(flags.width, 1, 0);
			char_count += ft_putchar_pf(c);
		}
		else
		{
			char_count += ft_putchar_pf(c);
			char_count += ft_flags_display(flags.width, 1, 0);
		}
	}
	else
		char_count += ft_putchar_pf(c);
	return (char_count);
}
