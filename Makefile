# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 00:20:18 by dcorenti          #+#    #+#              #
#    Updated: 2022/03/18 00:20:19 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = so_long

SRCS =    	srcs/main.c 					\
			srcs/ft_close_click.c			\
			srcs/ft_copy_map_ext.c			\
			srcs/ft_copy_map.c				\
			srcs/ft_draw_item.c				\
			srcs/ft_malloc.c				\
			srcs/ft_map_checker.c			\
			srcs/ft_draw_map.c				\
			srcs/ft_errors.c				\
			srcs/ft_exit.c					\
			srcs/ft_free.c					\
			srcs/ft_game.c					\
			srcs/ft_init_render.c			\
			srcs/ft_init.c					\
			srcs/ft_move_player.c			\
			srcs/ft_push_values.c			\
			srcs/ft_utils.c					\

CC = gcc

FLAGS = -Wall -Wextra -Werror -l mlx -framework OpenGL -framework Appkit

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRCS)-o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
# rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
