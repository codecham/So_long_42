/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:18:42 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:18:42 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_copy_map_ext(t_game *game, char *line, int i, int fd)
{
	int	ret;

	ret = get_next_line(fd, &line);
	if (!line)
		ft_errors_gnl(game, line, "GNL error", fd);
	ft_wall_line(game, line, i, fd);
	free(line);
	close(fd);
}
