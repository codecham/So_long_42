/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:54 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:19:55 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_exit(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map->n_all)
	{
		if (game->map->type_array[i] == C)
			return ;
		i++;
	}
	i = 0;
	while (i < game->map->n_all)
	{
		if (game->map->type_array[i] == E && game->map->x_array[i] == x
			&& game->map->y_array[i] == y)
		{
			ft_printf("\n\n\t-----------------\n");
			ft_printf("\t|CONGRATULATION!|\n");
			ft_printf("\t-----------------\n");
			ft_printf("\tYour score --> %d\n\n", game->moves);
			ft_exit(game);
		}
		i++;
	}
}

void	ft_check_collectible(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map->n_all)
	{
		if (game->map->type_array[i] == C)
		{
			if (x == game->map->x_array[i] && y == game->map->y_array[i])
				game->map->type_array[i] = 0;
		}
		i++;
	}
}

void	ft_move_player(t_game *game, int keypress)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (keypress == 2 && game->map->map[x][y + 1] != 1)
		game->p_y++;
	if (keypress == 0 && game->map->map[x][y - 1] != 1)
		game->p_y--;
	if (keypress == 1 && game->map->map[x + 1][y] != 1)
		game->p_x++;
	if (keypress == 13 && game->map->map[x - 1][y] != 1)
		game->p_x--;
	if (game->p_x != x || game->p_y != y)
	{
		game->moves++;
		ft_printf("Moves = %d\n", game->moves);
	}
	ft_check_collectible(game, x, y);
	ft_check_exit(game, game->p_x, game->p_y);
	ft_draw_map(game);
	ft_draw_item(game);
}
