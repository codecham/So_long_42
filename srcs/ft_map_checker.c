/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:47 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:19:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_file_name(t_game *game, char *file)
{
	int	i;

	if (!file)
		ft_errors(game, "Problem while line reading");
	i = ft_strlen(file);
	if (file[i - 1] != 'r' || file[i - 2] != 'e'
		|| file[i - 3] != 'b' || file[i - 4] != '.')
		ft_errors(game, "Bad file name");
}

void	ft_check_line(t_game *game, char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		ft_errors_gnl(game, str, "Problem while line reading", fd);
	if ((int) ft_strlen(str) != game->map->line_size)
		ft_errors_gnl(game, str, "Map is not rectangular", fd);
	while (str[i])
	{
		if (ft_char_list(game, str[i]) == -1)
			ft_errors_gnl(game, str, "Bad character on map", fd);
		i++;
	}
}

void	ft_check_ecp(t_game *game)
{
	if (game->map->n_collectible <= 0)
		ft_errors(game, "Must has at least of one collectible");
	if (game->map->n_exit <= 0)
		ft_errors(game, "Must has at least of one exit");
	if (game->map->n_start != 1)
		ft_errors(game, "Must has one player starting position");
}

void	ft_ext(t_game *game, char *file, int fd)
{
	close(fd);
	ft_check_ecp(game);
	game->map->n_all = game->map->n_collectible
		+ game->map->n_exit + game->map->n_start;
	ft_copy_map(game, file);
}

void	ft_map_checker(t_game *game, char *file)
{
	char	*line;
	int		fd;
	int		ret;

	if (!file)
		ft_errors(game, "Error with file in map checker");
	ft_file_name(game, file);
	fd = ft_open_file(game, file);
	ret = get_next_line(fd, &line);
	if (!line)
		ft_errors_gnl(game, line, "Get_next_line error", fd);
	game->map->line_size = ft_strlen(line);
	ft_check_line(game, line, fd);
	free(line);
	game->map->map_size++;
	while (ret > 0)
	{
		game->map->map_size++;
		ret = get_next_line(fd, &line);
		if (!line)
			ft_errors_gnl(game, line, "Get_next_line error", fd);
		ft_check_line(game, line, fd);
		free(line);
	}
	ft_ext(game, file, fd);
}
