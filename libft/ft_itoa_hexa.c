/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:09:00 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:09:01 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calcul_size(unsigned long long n)
{
	int	i;

	i = 0;
	while (n / 16 != 0)
	{
		n /= 16;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_convert_hexa(unsigned long long n, char *base)
{
	int		i;
	char	*str;

	i = ft_calcul_size(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (n / 16 != 0 && n != 0)
	{
		str[i] = base[n % 16];
		n /= 16;
		i--;
	}
	str[i] = base[n];
	return (str);
}

static void	ft_fill_base(char *base, int type)
{
	int		i;
	char	c;

	i = 0;
	c = '0';
	while (i < 10)
	{
		base[i] = c;
		c++;
		i++;
	}
	if (type == 0)
		c = 'a';
	else
		c = 'A';
	while (i < 16)
	{
		base[i] = c;
		c++;
		i++;
	}
	base[i] = '\0';
}

char	*ft_itoa_hexa(unsigned long long nbr, int type)
{
	char	base[17];
	char	*str;

	if (nbr == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	ft_fill_base(base, type);
	str = ft_convert_hexa(nbr, base);
	return (str);
}
