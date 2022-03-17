/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:20:05 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:20:06 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_char_list(t_game *game, char c)
{
	if (c == '0' || c == '1')
		return (1);
	if (c == 'C')
	{
		game->map->n_collectible++;
		return (1);
	}
	if (c == 'E')
	{
		game->map->n_exit++;
		return (1);
	}
	if (c == 'P')
	{
		game->map->n_start++;
		return (1);
	}
	return (-1);
}

int	ft_open_file(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		ft_errors(game, "L'argument est un dossier");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_errors(game, "Le fichier .ber est invalide");
	return (fd);
}
