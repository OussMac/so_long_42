/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_more_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:09:22 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/14 03:26:31 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_blocks(t_game *g, int x, int y)
{
	int	p;

	p = PIXELS;
	if (g->map[y][x] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->blocks.grass, p * x, p * y);
	else if (g->map[y][x] == '1' && y + 1 < g->blocks_y
		&& g->map[y + 1][x] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win,
			g->blocks.cobble_t, p * x, p * y);
	}
	else if (g->map[y][x] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win,
			g->blocks.cobble, p * x, p * y);
	}
	if (g->map[y][x] == 'P')
		player_fill(g, x, y);
}

void	render_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P' || game->map[y][x] == 'R')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.catr, PIXELS * x, PIXELS * y);
	}
	else if (game->map[y][x] == 'L')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.catl, PIXELS * x, PIXELS * y);
	}
}

bool	is_door(t_game *game, int x, int y)
{
	int		i;
	char	*doors;

	i = 0;
	doors = "CEO";
	while (doors[i])
	{
		if (game->map[y][x] == doors[i])
			return (true);
		i++;
	}
	return (false);
}

void	render_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.food, PIXELS * x, PIXELS * y);
	}
	else if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.exit_c, PIXELS * x, PIXELS * y);
	}
	else if (game->map[y][x] == 'O')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.exit_o, PIXELS * x, PIXELS * y);
	}
}

void	update_y_dir(t_game *game)
{
	if (game->player.old_pos_y < game->player.p_y)
	{
		game->map[game->player.p_y][game->player.p_x] = 'D';
		mlx_put_image_to_window(game->mlx, game->win, game->blocks.catd,
			PIXELS * game->player.p_x, PIXELS * game->player.p_y);
	}
	else if (game->player.old_pos_y > game->player.p_y)
	{
		game->map[game->player.p_y][game->player.p_x] = 'U';
		mlx_put_image_to_window(game->mlx, game->win, game->blocks.catu,
			PIXELS * game->player.p_x, PIXELS * game->player.p_y);
	}
}
