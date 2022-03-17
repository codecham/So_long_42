/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:11:27 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:12:37 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp_s;

	if (!s || n <= 0)
		return (0);
	i = 0;
	tmp_s = (char *)s;
	while (i < n)
	{
		if (tmp_s[i] == c)
			return (&tmp_s[i]);
		i++;
	}
	return (0);
}
