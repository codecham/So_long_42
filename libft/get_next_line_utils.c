/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:17:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:17:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_line(char *save)
{
	int	i;

	if (!save)
		return (-2);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_error_gnl(char **save, char *temp, int fd)
{
	if (save[fd])
		free(save[fd]);
	if (temp)
		free(temp);
	return (-1);
}

void	ft_copy_line(char *save, char *new, int i, int j)
{
	while (save[i + j])
	{
		new[j] = save[i + j];
		j++;
	}
	new[j] = '\0';
}
