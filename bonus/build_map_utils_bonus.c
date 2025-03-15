/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:01:17 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/15 02:29:32 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static bool	wall(t_game *game)
{
	if (game->map[game->player.p_y][game->player.p_x] != '1'
		&& game->map[game->player.p_y][game->player.p_x] != 'E')
		return (true);
	return (false);
}

void	fill_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->blocks_y)
	{
		x = 0;
		while (x < g->blocks_x)
		{
			fill_blocks(g, x, y);
			x++;
		}
		y++;
	}
}

void	update_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	if (game->food <= 0)
		game->map[game->door_y][game->door_x] = 'O';
	while (y < game->blocks_y)
	{
		x = 0;
		while (x < game->blocks_x)
		{
			update_blocks(game, x, y);
			mlx_set_font(game->mlx, game->win,
				"-sony-fixed-medium-r-normal--24-230-75-75-c-120-iso8859-1");
			mlx_string_put(game->mlx, game->win,
				1.2 * PIXELS, 0.56 * PIXELS, 0xFFFFFF, "[+] ==> Moves :");
			game->mvs = ft_itoa(game->moves);
			mlx_string_put(game->mlx, game->win,
				3.1 * PIXELS, 0.56 * PIXELS, 0xFFFFFF, game->mvs);
			free(game->mvs);
			x++;
		}
		y++;
	}
}

void	update_player(t_game *game, int *flag)
{
	if (wall(game) && *flag != 0)
	{
		if (game->map[game->player.p_y][game->player.p_x] == 'C')
			game->food--;
		else if (game->map[game->player.p_y][game->player.p_x] == 'O')
			goal(game, 'W');
		else if (game->map[game->player.p_y][game->player.p_x] == 'Z')
			goal(game, 'L');
		game->map[game->player.old_pos_y][game->player.old_pos_x] = '0';
		game->map[game->player.p_y][game->player.p_x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->blocks.grass,
			PIXELS * game->player.old_pos_x, PIXELS * game->player.old_pos_y);
		player_dir(game);
	}
	else
	{
		*flag = 1;
		game->player.p_x = game->player.old_pos_x;
		game->player.p_y = game->player.old_pos_y;
	}
}
