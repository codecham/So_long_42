/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:17:17 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:17:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(long nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static void	ft_fill_tab(char *tab, long div, long nb, int i)
{
	while (div)
	{
		tab[i] = (nb / div) + '0';
		nb = nb % div;
		div = div / 10;
		i++;
	}
	tab[i] = '\0';
}

char	*ft_uitoa(unsigned long long nb)
{
	int		size;
	int		i;
	long	div;
	char	*tab;

	size = ft_size(nb);
	i = 0;
	div = 1;
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	while (nb / div > 9)
		div = div * 10;
	ft_fill_tab(tab, div, nb, i);
	return (tab);
}
