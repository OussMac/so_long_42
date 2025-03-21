/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:59:27 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/15 03:01:02 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*max_int(char *str)
{
	char	*tmp;
	int		i;

	tmp = "-2147483648";
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = ft_len(n);
	s = (char *) malloc ((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len--] = 0;
	if (n == 0)
		s[0] = '0';
	if (n == -2147483648)
		return (max_int(s));
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n != 0)
	{
		s[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}

void	zombie_right(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, g->zomb.zright,
		PIXELS * (x + 1), PIXELS * y);
	mlx_put_image_to_window(g->mlx, g->win, g->blocks.grass,
		PIXELS * x, PIXELS * y);
}

void	zombie_left(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, g->zomb.zleft,
		PIXELS * (x - 1), PIXELS * y);
	mlx_put_image_to_window(g->mlx, g->win, g->blocks.grass,
		PIXELS * x, PIXELS * y);
}
