/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:18:56 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:18:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->n_all)
	{
		if (game->map->type_array[i] == E)
			mlx_put_image_to_window(game->mlx, game->win_mlx, game->e_img,
				game->map->y_array[i] * 40, game->map->x_array[i] * 40);
		i++;
	}	
}

void	ft_draw_col(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->n_all)
	{
		if (game->map->type_array[i] == C)
		{
			if ((game->map->x_array[i] != game->p_x
					|| game->map->y_array[i] != game->p_y))
				mlx_put_image_to_window(game->mlx, game->win_mlx, game->c_img,
					game->map->y_array[i] * 40, game->map->x_array[i] * 40);
		}
		i++;
	}	
}

void	ft_draw_item(t_game *game)
{
	ft_draw_col(game);
	ft_draw_exit(game);
	mlx_put_image_to_window(game->mlx, game->win_mlx, game->p_img,
		game->p_y * 40, game->p_x * 40);
}
