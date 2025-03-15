/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:49:23 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/14 01:50:43 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_game *game)
{
	free_grid(game->map);
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

static void	init_images(t_game *g)
{
	int	p;

	p = PIXELS;
	g->blocks.grass = mlx_xpm_file_to_image(g->mlx, GRASS, &p, &p);
	g->blocks.cobble = mlx_xpm_file_to_image(g->mlx, COBBLE, &p, &p);
	g->blocks.cobble_t = mlx_xpm_file_to_image(g->mlx, COBBLE_T, &p, &p);
	g->blocks.catr = mlx_xpm_file_to_image(g->mlx, CATR, &p, &p);
	g->blocks.catl = mlx_xpm_file_to_image(g->mlx, CATL, &p, &p);
	g->blocks.catu = mlx_xpm_file_to_image(g->mlx, CATU, &p, &p);
	g->blocks.catd = mlx_xpm_file_to_image(g->mlx, CATD, &p, &p);
	g->blocks.food = mlx_xpm_file_to_image(g->mlx, FOOD, &p, &p);
	g->blocks.exit_c = mlx_xpm_file_to_image(g->mlx, EXITC, &p, &p);
	g->blocks.exit_o = mlx_xpm_file_to_image(g->mlx, EXITO, &p, &p);
	if (!g->blocks.grass || !g->blocks.cobble
		|| !g->blocks.cobble_t || !g->blocks.catr || !g->blocks.catl
		|| !g->blocks.catu || !g->blocks.catd || !g->blocks.food
		|| !g->blocks.exit_c || !g->blocks.exit_o)
	{
		print_error(IMAGE);
		clean_up(g);
	}
}

static void	init_window(t_parse *parse, t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nFailed To Initalize MLX Instance.\n", 2);
		exit (EXIT_FAILURE);
	}
	game->map_w = parse->x_max * PIXELS;
	game->map_h = parse->y_max * PIXELS;
	game->blocks_x = parse->x_max;
	game->blocks_y = parse->y_max;
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, TITLE);
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_putstr_fd("Error\nFailed To Open Window.\n", 2);
		exit (EXIT_FAILURE);
	}
}

static void	build_map(char *map_name, t_parse *parse, t_game *game, int fd)
{
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(OP_FAIL);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	game->map = create_2d_grid(fd, parse);
	close(fd);
	game->moves = 0;
	game->player.p_x = parse->player_x;
	game->player.p_y = parse->player_y;
	game->door_x = parse->door_x;
	game->door_y = parse->door_y;
	game->food = parse->c_count;
	init_images(game);
	fill_map(game);
}

void	load_game(char *map_name, t_parse *parse, int fd)
{
	t_game	game;

	init_window(parse, &game);
	build_map(map_name, parse, &game, fd);
	game_loop(&game);
}
