/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:26:41 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/15 02:56:13 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_anim(t_game *game)
{
	if (game->blocks.food_anim[0])
		mlx_destroy_image(game->mlx, game->blocks.food_anim[0]);
	if (game->blocks.food_anim[1])
		mlx_destroy_image(game->mlx, game->blocks.food_anim[1]);
	if (game->blocks.food_anim[2])
		mlx_destroy_image(game->mlx, game->blocks.food_anim[2]);
	if (game->blocks.food_anim[3])
		mlx_destroy_image(game->mlx, game->blocks.food_anim[3]);
	if (game->blocks.food_anim[4])
		mlx_destroy_image(game->mlx, game->blocks.food_anim[4]);
}

void	destroy_images(t_game *game)
{
	if (game->blocks.cobble)
		mlx_destroy_image(game->mlx, game->blocks.cobble);
	if (game->blocks.cobble_t)
		mlx_destroy_image(game->mlx, game->blocks.cobble_t);
	if (game->blocks.grass)
		mlx_destroy_image(game->mlx, game->blocks.grass);
	if (game->blocks.catr)
		mlx_destroy_image(game->mlx, game->blocks.catr);
	if (game->blocks.catl)
		mlx_destroy_image(game->mlx, game->blocks.catl);
	if (game->blocks.catu)
		mlx_destroy_image(game->mlx, game->blocks.catu);
	if (game->blocks.catd)
		mlx_destroy_image(game->mlx, game->blocks.catd);
	if (game->blocks.food)
		mlx_destroy_image(game->mlx, game->blocks.food);
	if (game->blocks.exit_c)
		mlx_destroy_image(game->mlx, game->blocks.exit_c);
	if (game->blocks.exit_o)
		mlx_destroy_image(game->mlx, game->blocks.exit_o);
	if (game->zomb.zleft)
		mlx_destroy_image(game->mlx, game->zomb.zleft);
	if (game->zomb.zright)
		mlx_destroy_image(game->mlx, game->zomb.zright);
	destroy_anim(game);
}

void	goal(t_game *game, char state)
{
	if (state == 'W')
	{
		ft_putstr_fd("You Won!\n", STDOUT_FILENO);
		clean_up(game);
	}
	else if (state == 'L')
	{
		ft_putstr_fd("You Lost!\n", STDOUT_FILENO);
		clean_up(game);
	}
}

bool	right_wall_collision(t_game *g, int x, int y, int dir)
{
	if (g->map[y][x + 1] != '1' && g->map[y][x + 1] != 'C'
		&& g->map[y][x + 1] != 'E' && g->map[y][x + 1] != 'O'
		&& dir == RIGHT_DIR)
		return (true);
	return (false);
}

bool	left_wall_collision(t_game *g, int x, int y, int dir)
{
	if (g->map[y][x - 1] != '1' && g->map[y][x - 1] != 'C'
		&& g->map[y][x - 1] != 'E' && g->map[y][x - 1] != 'O'
		&& dir == LEFT_DIR)
		return (true);
	return (false);
}
