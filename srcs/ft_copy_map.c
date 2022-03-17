/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:18:49 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:18:50 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_malloc_map(t_game *game)
{
	int	i;

	i = 0;
	game->map->map = (int **) malloc(sizeof(int *) * game->map->map_size + 1);
	if (!game->map->map)
		ft_errors(game, "Allocation Failed");
	while (i <= game->map->map_size)
	{
		game->map->map[i] = 0;
		game->map->map[i] = (int *) malloc(sizeof(int)
				* game->map->line_size + 1);
		if (!game->map->map[i])
			ft_errors(game, "Allocation Failed");
		i++;
	}
	game->map->type_array = (int *) malloc(sizeof(int) * game->map->n_all + 1);
	game->map->x_array = (int *) malloc(sizeof(int) * game->map->n_all + 1);
	game->map->y_array = (int *) malloc(sizeof(int) * game->map->n_all + 1);
	if (!game->map->type_array || !game->map->x_array || !game->map->y_array)
		ft_errors(game, "Alloction Failed");
}

void	ft_ecp_array(t_game *game, char c, int i, int j)
{
	if (c == 'C')
		game->map->type_array[game->map->i_array] = C;
	if (c == 'P')
		game->map->type_array[game->map->i_array] = S;
	if (c == 'E')
		game->map->type_array[game->map->i_array] = E;
	game->map->x_array[game->map->i_array] = i;
	game->map->y_array[game->map->i_array] = j;
	game->map->i_array++;
	game->map->type_array[game->map->i_array] = -1;
}

void	ft_wall_line(t_game *game, char *line, int i, int fd)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != '1')
			ft_errors_gnl(game, line, "Map is not closed by walls", fd);
		game->map->map[i][j] = 1;
		j++;
	}
	game->map->map[i][j] = -1;
}

void	ft_middle_line(t_game *game, char *line, int i, int fd)
{
	int	j;

	j = 0;
	if (line[0] != '1' || line[game->map->line_size - 1] != '1')
		ft_errors_gnl(game, line, "Map is not closed by walls", fd);
	while (line[j])
	{
		if (line[j] != '0' && line[j] != '1')
		{
			ft_ecp_array(game, line[j], i, j);
			game->map->map[i][j] = 0;
		}
		else if (line[j] == '0')
			game->map->map[i][j] = 0;
		else
			game->map->map[i][j] = 1;
		j++;
	}
	game->map->map[i][j] = -1;
}

void	ft_copy_map(t_game *game, char *file)
{
	int		fd;
	int		i;
	int		ret;
	char	*line;

	i = 1;
	fd = ft_open_file(game, file);
	ft_malloc_map(game);
	ret = get_next_line(fd, &line);
	if (!line)
		ft_errors_gnl(game, line, "GNL error", fd);
	ft_wall_line(game, line, 0, fd);
	free(line);
	while (i < game->map->map_size - 1)
	{
		ret = get_next_line(fd, &line);
		if (!line)
			ft_errors_gnl(game, line, "GNL error", fd);
		ft_middle_line(game, line, i, fd);
		free(line);
		i++;
	}
	ft_copy_map_ext(game, line, i, fd);
}
