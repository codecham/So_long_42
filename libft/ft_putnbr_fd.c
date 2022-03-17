/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:14:58 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:14:58 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_print(long nbr, int is_negative, int div, int fd)
{
	char	nb_to_write;

	if (is_negative == 1)
	{
		write(fd, "-", 1);
	}
	while (div != 0)
	{
		nb_to_write = (nbr / div) + 48;
		ft_putchar(nb_to_write, fd);
		nbr = nbr % div;
		div = div / 10;
	}
}

static void	ft_count(long nbr, int is_negative, int fd)
{
	int		cpt;
	int		div;
	long	nbrtemp;

	nbrtemp = nbr;
	cpt = 1;
	div = 1;
	while (nbr / 10 != 0 && nbr != 0)
	{
		cpt++;
		nbr = nbr / 10;
	}
	while (cpt > 1)
	{
		div = div * 10;
		cpt--;
	}
	ft_print(nbrtemp, is_negative, div, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	nbr;
	int		is_negative;

	nbr = nb;
	is_negative = 0;
	if (nbr < 0)
	{
		is_negative = 1;
		nbr = nbr * -1;
	}
	ft_count(nbr, is_negative, fd);
}
