/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:24 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:19:25 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 1 || keycode == 0
		|| keycode == 2 || keycode == 53)
	{
		ft_draw_map(game);
		ft_draw_item(game);
	}
	return (0);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 1 || keycode == 0
		|| keycode == 2 || keycode == 53)
	{
		if (keycode == 53)
		{
			ft_exit(game);
		}
		else
			ft_move_player(game, keycode);
	}
	return (0);
}

void	ft_game(t_game *game)
{
	mlx_hook(game->win_mlx, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->win_mlx, 3, 1L << 1, ft_key_release, game);
	mlx_hook(game->win_mlx, 17, 0, ft_close_click, game);
	mlx_loop(game->mlx);
}
