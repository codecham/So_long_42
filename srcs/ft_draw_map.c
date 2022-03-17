/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:01 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:24:07 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_ground(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->win_size_x)
	{
		while (y < game->win_size_y)
		{
			mlx_put_image_to_window(game->mlx, game->win_mlx,
				game->ground, x, y);
			y += 40;
		}
		x += 40;
		y = 0;
	}
}

void	ft_draw_wall(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (x < game->win_size_x)
	{
		while (y < game->win_size_y)
		{
			if (game->map->map[j][i] == 1)
				mlx_put_image_to_window(game->mlx, game->win_mlx,
					game->wall, x, y);
			y += 40;
			j++;
		}
		x += 40;
		i++;
		y = 0;
		j = 0;
	}
}

void	ft_draw_map(t_game *game)
{
	ft_draw_ground(game);
	ft_draw_wall(game);
}
