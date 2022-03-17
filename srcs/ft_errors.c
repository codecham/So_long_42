/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:08 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:19:09 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_errors(t_game *game, char *message)
{
	ft_free(game);
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(0);
}

void	ft_errors_gnl(t_game *game, char *line, char *message, int fd)
{
	if (fd)
		close(fd);
	if (line)
		free(line);
	ft_errors(game, message);
}
