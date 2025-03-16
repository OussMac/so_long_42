/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path_coll_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:07:41 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/16 02:07:56 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**grid_dup(char **grid, t_parse *parse)
{
	int		y;
	char	**new_grid;

	new_grid = (char **) malloc (sizeof(char *) * (parse->y_max + 1));
	if (!new_grid)
	{
		free_grid(grid);
		print_error(MALLOC_F);
		exit (EXIT_FAILURE);
	}
	y = 0;
	while (y < parse->y_max)
	{
		new_grid[y] = ft_strdup(grid[y]);
		y++;
	}
	new_grid[y] = NULL;
	return (new_grid);
}

void	coll(char **grid, t_pos p, t_parse *prs)
{
	if (p.x < 0 || p.y < 0 || p.x >= prs->x_max || p.y >= prs->y_max)
		return ;
	if (grid[p.y][p.x] == '1' || grid[p.y][p.x] == 'V'
		|| grid[p.y][p.x] == 'E' || grid[p.y][p.x] == 'Z')
		return ;
	if (grid[p.y][p.x] == 'C')
		prs->found_c++;
	grid[p.y][p.x] = 'V';
	coll(grid, (t_pos){p.x + 1, p.y}, prs);
	coll(grid, (t_pos){p.x - 1, p.y}, prs);
	coll(grid, (t_pos){p.x, p.y + 1}, prs);
	coll(grid, (t_pos){p.x, p.y - 1}, prs);
}
