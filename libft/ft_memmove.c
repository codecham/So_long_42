/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:13:02 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:13:02 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dst || !src)
		return (0);
	i = len;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (tmp_src < tmp_dst)
	{
		while (i > 0)
		{
			tmp_dst[i - 1] = tmp_src[i - 1];
			i--;
		}
	}
	else if (tmp_src > tmp_dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
