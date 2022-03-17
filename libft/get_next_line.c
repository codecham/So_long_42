/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:17:39 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:17:40 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	while (save && save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save && save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*super_join(char *save, char *temp, int lu)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc((ft_strlen(save) + lu + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (save && save[i])
	{
		new[i] = save[i];
		i++;
	}
	j = 0;
	while (j < lu)
	{
		new[i + j] = temp[j];
		j++;
	}
	new[i + j] = '\0';
	if (save)
		free(save);
	return (new);
}

static char	*update_line(char *save, int *lu, int j)
{
	char	*new;
	int		i;

	*lu = 0;
	i = is_line(save);
	if (i < 0)
	{
		if (i == -1)
			free(save);
		return (0);
	}
	new = (char *)malloc((ft_strlen(save) - i + 1) * sizeof(char));
	if (!new)
	{
		*lu = -1;
		free(save);
		return (0);
	}
	i++;
	ft_copy_line(save, new, i, j);
	if (save)
		free(save);
	return (new);
}

static int	get_next_l(int fd, char **line, char **save, int lu)
{
	*line = get_line(save[fd]);
	if (!line)
		return (-1);
	save[fd] = update_line(save[fd], &lu, 0);
	if (!save[fd])
		return (lu);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*temp;
	static char	*save[10240];
	int			lu;

	if (BUFFER_SIZE <= 0)
		return (-1);
	temp = (char *) malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (-1);
	if (!line || read(fd, temp, 0) < 0)
		return (ft_error_gnl(save, temp, fd));
	*line = NULL;
	if (is_line(save[fd]) < 0)
		lu = read(fd, temp, BUFFER_SIZE);
	while (is_line(save[fd]) < 0 && lu > 0)
	{
		save[fd] = super_join(save[fd], temp, lu);
		if (!save[fd])
			return (-1);
		if (is_line(save[fd]) < 0 && lu >= 0)
			lu = read(fd, temp, BUFFER_SIZE);
	}
	if (temp)
		free(temp);
	return (get_next_l(fd, line, save, lu));
}
