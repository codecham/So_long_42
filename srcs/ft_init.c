/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:35 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:19:36 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_map(t_game *game)
{
	game->map = 0;
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
		ft_errors(game, "Malloc error");
	game->map->line_size = 0;
	game->map->n_collectible = 0;
	game->map->n_exit = 0;
	game->map->n_start = 0;
	game->map->map_size = 0;
	game->map->n_all = 0;
	game->map->i_array = 0;
	game->map->map = 0;
	game->map->type_array = 0;
	game->map->x_array = 0;
	game->map->y_array = 0;
}

void	ft_init_struct(t_game *game)
{
	game->mlx = 0;
	game->win_mlx = 0;
	game->map = 0;
	game->p_img = 0;
	game->e_img = 0;
	game->c_img = 0;
	game->ground = 0;
	game->wall = 0;
	game->win_size_x = 0;
	game->win_size_y = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->moves = 0;
}

void	ft_init(t_game *game)
{
	ft_init_struct(game);
	ft_init_map(game);
}
