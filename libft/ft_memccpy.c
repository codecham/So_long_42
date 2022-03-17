/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:11:07 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:11:08 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!dst || !src)
		return (0);
	i = 0;
	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	while (i < n && (unsigned char)tmp_src[i] != (unsigned char)c)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	if (i == n)
		return (NULL);
	tmp_dst[i] = tmp_src[i];
	return (&tmp_dst[i + 1]);
}
