/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:16:51 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:16:51 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_cpy(const char *s1, char *s2, int i, int j)
{
	int	k;

	k = 0;
	while (s1[i + k] && i + k < j + 1)
	{
		s2[k] = s1[i + k];
		k++;
	}
	s2[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;
	char	*s2;

	i = 0;
	if (!s1)
		return (0);
	j = ft_strlen(s1) - 1;
	while (ft_ischarset(s1[i], set) == 1 && s1[i])
		i++;
	while (ft_ischarset(s1[j], set) == 1 && j >= 0)
		j--;
	if (j >= i)
		size = j - i + 2;
	else
		size = 1;
	s2 = (char *)malloc(sizeof(char) * size);
	if (!s2)
		return (0);
	ft_cpy(s1, s2, i, j);
	return (s2);
}
