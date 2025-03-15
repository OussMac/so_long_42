/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:53:37 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/15 02:10:06 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	player_input(int key, t_game *game)
{
	static int	flag = 0;

	if (key == ESC)
		clean_up(game);
	game->player.old_pos_x = game->player.p_x;
	game->player.old_pos_y = game->player.p_y;
	if (key == RIGHT)
		game->player.p_x++;
	else if (key == LEFT)
		game->player.p_x--;
	else if (key == UP)
		game->player.p_y--;
	else if (key == DOWN)
		game->player.p_y++;
	if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		update_player(game, &flag);
	return (0);
}

int	close_window(t_game *game)
{
	clean_up(game);
	return (0);
}

int	player_hold(t_game *game)
{
	(void)game;
	return (0);
}

int	update_frames(t_game *game)
{
	update_map(game);
	return (0);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, player_hold, &game);
	mlx_key_hook(game->win, player_input, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, update_frames, game);
	mlx_loop(game->mlx);
}
