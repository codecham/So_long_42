/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:19 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:19:20 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_img(t_game *game)
{
	if (game->p_img != 0)
		mlx_destroy_image(game->mlx, game->p_img);
	if (game->e_img != 0)
		mlx_destroy_image(game->mlx, game->e_img);
	if (game->c_img != 0)
		mlx_destroy_image(game->mlx, game->c_img);
	if (game->ground != 0)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->wall != 0)
		mlx_destroy_image(game->mlx, game->wall);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->map != 0)
	{
		while (i <= game->map->map_size)
		{
			if (game->map->map[i] != 0)
				free(game->map->map[i]);
			i++;
		}
		free(game->map->map);
		free(game->map);
	}
	if (game->map->type_array != 0)
		free(game->map->type_array);
	if (game->map->x_array != 0)
		free(game->map->x_array);
	if (game->map->y_array != 0)
		free(game->map->y_array);
}

void	ft_free(t_game *game)
{
	if (game)
	{
		ft_free_map(game);
		ft_free_img(game);
		if (game->win_mlx)
			mlx_destroy_window(game->mlx, game->win_mlx);
		(void) game->win_mlx;
		(void) game->mlx;
		free(game);
	}
}
