/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:18:15 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 00:18:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define S 2
# define E 3
# define C 4

typedef struct s_map
{
	int		n_collectible;
	int		n_exit;
	int		n_start;
	int		n_all;
	int		line_size;
	int		map_size;
	int		**map;
	int		*type_array;
	int		*x_array;
	int		*y_array;
	int		i_array;
}			t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win_mlx;
	int			win_size_x;
	int			win_size_y;
	int			p_x;
	int			p_y;
	int			moves;
	t_map		*map;
	t_img		*p_img;
	t_img		*e_img;
	t_img		*c_img;
	t_img		*ground;
	t_img		*wall;
}	t_game;

void	ft_map_checker(t_game *game, char *file);
void	ft_errors(t_game *game, char *message);
int		ft_char_list(t_game *game, char c);
int		ft_open_file(t_game *game, char *file);
void	ft_init(t_game *game);
void	ft_init_render(t_game *game);
void	ft_copy_map(t_game *game, char *file);
void	ft_free(t_game *game);
t_game	*ft_malloc(void);
void	ft_push_value(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_draw_item(t_game *game);
void	ft_game(t_game *game);
void	ft_move_player(t_game *game, int keypress);
void	ft_exit(t_game *game);
int		ft_close_click(int keycode, t_game *game);
void	ft_errors_gnl(t_game *game, char *line, char *message, int fd);
void	ft_texture_init(t_game *game);
void	ft_wall_line(t_game *game, char *line, int i, int fd);
void	ft_copy_map_ext(t_game *game, char *line, int i, int fd);

#endif