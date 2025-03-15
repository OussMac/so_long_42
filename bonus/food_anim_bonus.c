/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_anim_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:02:19 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/15 03:03:45 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_frames(t_game *g)
{
	int	p;

	p = PIXELS;
	g->blocks.food_anim[0] = mlx_xpm_file_to_image(g->mlx, FRAME1, &p, &p);
	g->blocks.food_anim[1] = mlx_xpm_file_to_image(g->mlx, FRAME2, &p, &p);
	g->blocks.food_anim[2] = mlx_xpm_file_to_image(g->mlx, FRAME3, &p, &p);
	g->blocks.food_anim[3] = mlx_xpm_file_to_image(g->mlx, FRAME4, &p, &p);
	g->blocks.food_anim[4] = mlx_xpm_file_to_image(g->mlx, FRAME5, &p, &p);
	if (!g->blocks.food_anim[0] || !g->blocks.food_anim[1]
		|| !g->blocks.food_anim[2] || !g->blocks.food_anim[3]
		|| !g->blocks.food_anim[4])
	{
		return (-1);
	}
	return (0);
}

void	animate_food(t_game *game, int x, int y)
{
	static int	counter = 0;
	static int	frame = 0;

	counter++;
	if (counter >= DELAY)
	{
		counter = 0;
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.food_anim[frame], PIXELS * x, PIXELS * y);
		frame++;
		if (frame >= 4)
			frame = 0;
	}
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->blocks.food_anim[frame], PIXELS * x, PIXELS * y);
}

int	init_zombies(t_game *g)
{
	int	p;

	p = PIXELS;
	g->zomb.zleft = mlx_xpm_file_to_image(g->mlx, ZLEFT, &p, &p);
	g->zomb.zright = mlx_xpm_file_to_image(g->mlx, ZRIGHT, &p, &p);
	if (!g->zomb.zleft || !g->zomb.zright)
		return (-1);
	return (0);
}

void	render_zombie(t_game *g, int x, int y)
{
	static int	counter = 0;

	counter++;
	if (counter >= ZSPEED)
	{
		move_zombie(g, x, y);
		counter = 0;
	}
}

void	move_zombie(t_game *g, int x, int y)
{
	static int	dir = RIGHT_DIR;

	if (right_wall_collision(g, x, y, dir))
	{
		if (is_player(g, x + 1, y))
			goal(g, 'L');
		g->map[y][x + 1] = 'Z';
		g->map[y][x] = '0';
		zombie_right(g, x, y);
	}
	else
		dir = LEFT_DIR;
	if (left_wall_collision(g, x, y, dir))
	{
		if (is_player(g, x - 1, y))
			goal(g, 'L');
		g->map[y][x - 1] = 'Z';
		g->map[y][x] = '0';
		zombie_left(g, x, y);
	}
	else
		dir = RIGHT_DIR;
}
