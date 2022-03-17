/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:15:20 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:15:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	words_count;

	i = 0;
	words_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			words_count++;
		i++;
	}
	return (words_count);
}

static void	write_words(char *dest, const char *from, char c)
{
	int	i;

	i = 0;
	while (from[i] != c && from[i] != '\0')
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_free_split(char **split, int words)
{
	while (words)
	{
		free(split[words]);
		words--;
	}
	free(split);
	return (0);
}

static int	write_split(char **split, const char *str, char c)
{
	int	i;
	int	j;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			split[words] = (char *)malloc(sizeof(char) * (j + 1));
			if (!split[words])
				return (ft_free_split(split, words - 1));
			write_words(split[words], str + i, c);
			i = i + j;
			words++;
		}
	}
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		words_count;

	if (!str)
		return (NULL);
	words_count = ft_count_words(str, c);
	split = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!split)
		return (NULL);
	split[words_count] = 0;
	if (write_split(split, str, c) == 0)
		return (NULL);
	return (split);
}
