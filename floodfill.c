/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:23:23 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/13 21:15:51 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*fill(char **map, int rows, int columns)
{
	map[rows][columns] = '1';
	if (map[rows - 1][columns] != '1')
		fill(map, (rows - 1), columns);
	if (map[rows + 1][columns] != '1')
		fill(map, (rows + 1), columns);
	if (map[rows][columns - 1] != '1')
		fill(map, rows, (columns -1));
	if (map[rows][columns + 1] != '1')
		fill(map, rows, (columns + 1));
	return (*map);
}

int	floodfill(char	*argv, t_map *game)
{
	char	**copymap;
	int		rows;
	int		columns;
	int		i;

	i = 0;
	pos_player(game);
	copymap = malloc(sizeof(char *) * game->rows + 1);
	while (i < game->rows)
	{
		copymap[i] = ft_strdup(game->map[i]);
		i++;
	}
	copymap[i] = NULL;
	fill(copymap, game->player_y, game->player_x);
	rows = 0;
	columns = 0;
	while (copymap[columns][rows] != '\0')
	{
		rows = 0;
		while (copymap[columns][rows] != '\n')
		{
			if (copymap[columns][rows] == 'C' || copymap[columns][rows] == 'E')
			{
				free_map(copymap);	
				shit(game);
			}
			rows++;
		}
		columns++;
	}
	free_map(copymap);
	return (1);
}
