/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:26:41 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/14 03:59:28 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
