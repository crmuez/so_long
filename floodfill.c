/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:23:23 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/04/25 12:25:14 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **map, int rows, int columns)
{
	map[rows][columns] = 1;
	if (map[rows - 1][columns] != 1)
		fill(map, (rows - 1), columns);
	else if (map[rows + 1][columns] != 1)
		fill(map, (rows + 1), columns);
	else if (map[rows][columns - 1] != 1)
		fill(map, rows, (columns -1));
	else if (map[rows][columns + 1] != 1)
		fill(map, rows, (columns + 1));
}

int	floodfill(char	*argv, t_map *game)
{
	char	**copymap;
	int		rows;
	int		columns;

	rows = count_lines(argv);
	columns = count_chars(game);
	copymap = game->map;
	fill(copymap, rows, columns);
	rows = 0;
	columns = 0;
	while (copymap[columns][rows] != '\0')
	{
		rows = 0;
		while (copymap[columns][rows] != '\n')
		{
			if (copymap[columns][rows] == 'C' && copymap[columns][rows] == 'E')
				shit();
			rows++;
		}
		columns++;
	}
	return (1);
}