/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:59 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:19:59 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_push_value(t_game *game)
{
	int	i;

	i = 0;
	game->win_size_x = game->map->line_size * 40;
	game->win_size_y = game->map->map_size * 40;
	while (i < game->map->n_all)
	{
		if (game->map->type_array[i] == S)
		{
			game->p_x = game->map->x_array[i];
			game->p_y = game->map->y_array[i];
		}
		i++;
	}
}
