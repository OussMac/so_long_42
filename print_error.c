/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:36:05 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/16 01:49:00 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error == USAGE)
		ft_putstr_fd("Usage: ./so_long <map_name>.ber\n", STDERR_FILENO);
	else if (error == INVALID)
		ft_putstr_fd("Invalid Map.\n", STDERR_FILENO);
	else if (error == OP_FAIL)
		ft_putstr_fd("Failed To Open File.\n", STDERR_FILENO);
	else if (error == EMPTY)
		ft_putstr_fd("Empty Map.\n", STDERR_FILENO);
	else if (error == MAP_GAP)
		ft_putstr_fd("Found A Gap In The Map.\n", STDERR_FILENO);
	else if (error == SYMBOL)
		ft_putstr_fd("Please Enter A Valid Map Configuration.\n", STDERR_FILENO);
	else if (error == RECT)
		ft_putstr_fd("The Map Must Be Rectangular.\n", STDERR_FILENO);
	else if (error == PARAMS)
		ft_putstr_fd("Invalid (Player-Exit-Collec) Count.\n", STDERR_FILENO);
	else if (error == MALLOC_F)
		ft_putstr_fd("Malloc Failure.\n", STDERR_FILENO);
	else if (error == PATH_BLOCKED)
		ft_putstr_fd("Player Path Blocked.\n", STDERR_FILENO);
	else if (error == IMAGE)
		ft_putstr_fd("Invalid Texture.\n", STDERR_FILENO);
	else if (error == BIG_MAP)
		ft_putstr_fd("Map Is Way Too Big.\n", STDERR_FILENO);
}
