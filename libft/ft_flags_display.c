/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:07:29 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:07:31 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_display(int size, int minus, int type)
{
	int	i;

	i = 0;
	while (size - minus > 0)
	{
		if (type == 1)
			ft_putchar_pf('0');
		else
			ft_putchar_pf(32);
		size--;
		i++;
	}
	return (i);
}
