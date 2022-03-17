/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:13:51 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:13:53 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pourcent(t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putstrn("%", 1);
	if (flags.minus == 1 && flags.star == 1)
		char_count += ft_flags_display(flags.width, 1, 0);
	else
		char_count += ft_flags_display(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstrn("%", 1);
	return (char_count);
}
