/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_helpers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:33 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/15 03:00:10 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_player(t_game *game, int x, int y)
{
	int		i;
	char	*dirs;

	dirs = "PRLUD";
	i = 0;
	while (dirs[i])
	{
		if (game->map[y][x] == dirs[i])
			return (true);
		i++;
	}
	return (false);
}

static bool	closest(int x, t_game *game)
{
	int	diff;

	diff = (game->blocks_x / 2) - x;
	if (diff >= 0)
		return (true);
	return (false);
}

void	player_fill(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->blocks.grass, PIXELS * x, PIXELS * y);
	if (closest(x, game))
	{
		game->map[y][x] = 'R';
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.catr, PIXELS * x, PIXELS * y);
	}
	else
	{
		game->map[y][x] = 'L';
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.catl, PIXELS * x, PIXELS * y);
	}
}

void	update_blocks(t_game *game, int x, int y)
{
	if (is_player(game, x, y))
		render_player(game, x, y);
	else if (game->map[y][x] == 'Z')
		render_zombie(game, x, y);
	else if (is_door(game, x, y))
		render_exit(game, x, y);
	else if (game->map[y][x] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.grass, PIXELS * x, PIXELS * y);
	}
	else if (game->map[y][x] == '1' && y + 1 < game->blocks_y
		&& game->map[y + 1][x] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.cobble_t, PIXELS * x, PIXELS * y);
	}
	else if (game->map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.cobble, PIXELS * x, PIXELS * y);
	}
}

void	player_dir(t_game *game)
{
	static int	moves = 1;

	game->moves = moves++;
	if (game->player.old_pos_x < game->player.p_x)
	{
		game->map[game->player.p_y][game->player.p_x] = 'R';
		mlx_put_image_to_window(game->mlx, game->win, game->blocks.catr,
			PIXELS * game->player.p_x, PIXELS * game->player.p_y);
	}
	else if (game->player.old_pos_x > game->player.p_x)
	{
		game->map[game->player.p_y][game->player.p_x] = 'L';
		mlx_put_image_to_window(game->mlx, game->win, game->blocks.catl,
			PIXELS * game->player.p_x, PIXELS * game->player.p_y);
	}
	update_y_dir(game);
}
