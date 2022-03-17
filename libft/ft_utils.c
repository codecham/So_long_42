/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:17:22 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:17:23 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_char_to_int(char c)
{
	return (c - 48);
}

int	ft_flags_list(char c)
{
	if (c == '0' || c == '-' || c == '.' || c == '*')
		return (1);
	else if (c >= '1' && c <= '9')
		return (1);
	else
		return (-1);
}

int	ft_type_list(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'p' || c == 'x'
		|| c == 'X' || c == 'c' || c == 's' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}
