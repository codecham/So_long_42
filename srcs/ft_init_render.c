/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:29 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:19:30 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_texture_init(t_game *game)
{
	game->ground = mlx_xpm_file_to_image(game->mlx, "./textures/sand.xpm",
			&game->ground->height, &game->ground->width);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->wall->height, &game->wall->width);
	game->p_img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&game->p_img->height, &game->p_img->width);
	game->c_img = mlx_xpm_file_to_image(game->mlx, "./textures/gas.xpm",
			&game->c_img->height, &game->c_img->width);
	game->e_img = mlx_xpm_file_to_image(game->mlx, "./textures/helicopter.xpm",
			&game->e_img->height, &game->e_img->width);
}

void	ft_init_img_struct(t_img *img)
{
	img->img = 0;
	img->width = 0;
	img->height = 0;
}

void	ft_init_img(t_game *game)
{	
	game->p_img = (t_img *)malloc(sizeof(t_img));
	game->e_img = (t_img *)malloc(sizeof(t_img));
	game->c_img = (t_img *)malloc(sizeof(t_img));
	game->ground = (t_img *)malloc(sizeof(t_img));
	game->wall = (t_img *)malloc(sizeof(t_img));
	if (!game->p_img || !game->e_img || !game->c_img
		|| !game->ground || !game->wall)
		ft_errors(game, "Malloc error");
	ft_init_img_struct(game->p_img);
	ft_init_img_struct(game->e_img);
	ft_init_img_struct(game->c_img);
	ft_init_img_struct(game->ground);
	ft_init_img_struct(game->wall);
}

void	ft_init_render(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == 0)
		ft_errors(game, "Can't load mlx");
	game->win_mlx = mlx_new_window(game->mlx, game->map->line_size * 40,
			game->map->map_size * 40, "so_long");
	if (game->win_mlx == 0)
		ft_errors(game, "Can't create window");
	ft_init_img(game);
	ft_texture_init(game);
}
