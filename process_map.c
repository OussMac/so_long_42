/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:35:04 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/16 01:04:38 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*cut_row(char *row_uncut)
{
	int		len;
	char	*temp;
	char	*new_row;

	if (!row_uncut)
		return (NULL);
	len = ft_strlen(row_uncut);
	temp = row_uncut;
	if (ft_strchr(row_uncut, '\n'))
		new_row = ft_substr(row_uncut, 0, len - 1);
	else
		new_row = ft_strdup(row_uncut);
	free(temp);
	return (new_row);
}

int	process_symbol(char symbol, t_parse *parse)
{
	if ((parse->x == 0 || parse->x == parse->x_max - 1) && symbol != '1')
		return (print_error(MAP_GAP), INVALID_S);
	if ((parse->y == 0 || parse->y == parse->y_max - 1) && symbol != '1')
		return (print_error(MAP_GAP), INVALID_S);
	if (cmp_symbol(symbol) == false)
		return (print_error(SYMBOL), INVALID_S);
	else
		count_params(symbol, parse);
	return (VALID_SYMBOL);
}

void	process_map(int fd, t_parse *parse)
{
	char	*row;

	row = cut_row(get_next_line(fd));
	while (row)
	{
		parse->x = 0;
		width_check(row, fd, parse);
		while (row[parse->x])
		{
			if (process_symbol(row[parse->x], parse) == INVALID_S)
			{
				free(row);
				get_next_line(INVALID_S);
				close(fd);
				exit (EXIT_FAILURE);
			}
			parse->x++;
		}
		free(row);
		row = cut_row(get_next_line(fd));
		parse->y++;
	}
	close(fd);
	params_check(parse);
}

void	get_max_x_y(int fd, t_parse *parse)
{
	int		i;
	char	*row;

	i = 0;
	row = get_next_line(fd);
	if (!row)
	{
		close(fd);
		print_error(EMPTY);
		exit(EXIT_FAILURE);
	}
	while (row[i + 1])
	{
		parse->x_max++;
		i++;
	}
	while (row)
	{
		free(row);
		row = get_next_line(fd);
		parse->y_max++;
	}
}

void	primary_parse(char *map_name, t_parse *parse, int fd)
{
	ft_bzero(parse, sizeof(t_parse));
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(OP_FAIL);
		exit(EXIT_FAILURE);
	}
	get_max_x_y(fd, parse);
	close(fd);
	if (parse->y_max > 21 || parse->x_max > 40)
	{
		print_error(BIG_MAP);
		exit(EXIT_FAILURE);
	}
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(OP_FAIL);
		exit(EXIT_FAILURE);
	}
}
