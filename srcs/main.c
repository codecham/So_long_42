/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:20:11 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:20:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nBad number of argument\n");
		exit(0);
	}
	game = 0;
	game = ft_malloc();
	ft_init(game);
	ft_map_checker(game, argv[1]);
	ft_init_render(game);
	ft_push_value(game);
	ft_draw_map(game);
	ft_draw_item(game);
	ft_game(game);
}
