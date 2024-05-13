/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:21:11 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/13 21:13:46 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rect(t_map *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		if ((game->rows - 1) == i)
		{
			if (ft_strlen(game->map[i]) != (game->col - 1))
				shit(game);
		}
		else
		{
			if (ft_strlen(game->map[i]) != game->col)
				shit(game);
		}
		i++;
	}
	return (1);
}

int	check_walls(t_map *game)
{
	int		i;

	i = 0;
	while (game->map[0][i] != '\n' && game->map[0][i] != '\0')
	{
		if (game->map[0][i] != '1' || game->map[game->rows -1][i] != '1')
			shit(game);
		i++;
	}
	i = 0;
	while (game->rows > (i + 1))
	{
		if (game->map[i][0] != '1' || game->map[i][game->col - 2] != '1')
			shit(game);
		i++;
	}
	return (1);
}

int	check_ep(t_map *game)
{
	int		i;
	int		j;
	int		exit;
	int		player;

	j = 0;
	i = 0;
	exit = 0;
	player = 0;
	while (game->map[j][i] != '\0')
	{
		i = 0;
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] == 'E')
				exit++;
			if (game->map[j][i] == 'P')
				player++;
			i++;
		}
		j++;
	}
	if (player == 1 && exit == 1)
		return (1);
	return (0);
}

int	check_collect(t_map *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (game->map[j][i] != '\0')
	{
		i = 0;
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	if (c < 1)
		shit(game);
	return (c);
}

int	check_letters(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j][i] != '\0')
	{
		i = 0;
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] != '1' && game->map[j][i] != '0'
				&& game->map[j][i] != 'C' && game->map[j][i] != 'P'
				&& game->map[j][i] != 'E')
				shit(game);
			i++;
		}
		j++;
	}
	return (1);
}
