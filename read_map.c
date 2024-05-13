/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:47:54 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/13 21:19:40 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shit(t_map	*game)
{
	write(2, "Error 💩\n", 11);
	if (game)
		free_map(game->map);
	exit(1);
}

int	count_lines(char *argv)
{
	int		i;
	char	*map;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	map = get_next_line(fd);
	i = 0;
	while (map)
	{
		map = get_next_line(fd);
		i++;
	}
	close(fd);
	free(map);
	return (i);
}

int	count_chars(t_map *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != '\0')
		i++;
	return (i);
}

void	read_map(char *argv, t_map *game)
{
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(1);
	game->rows = count_lines(argv);
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		free(game->map);
	i = 0;
	while (game->rows > i)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	game->map[i] = NULL;
	game->col = count_chars(game);
}
