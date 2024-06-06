/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:11:17 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/15 19:38:22 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_player(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j][i] != 'P')
	{
		i = 0;
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] == 'P')
				break ;
			else
				i++;
		}
		if (game->map[j][i] == 'P')
			break ;
		j++;
	}
	game->player_y = j;
	game->player_x = i;
}

void	pos_exit(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j][i] != 'E')
	{
		i = 0;
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] == 'E')
				break ;
			else
				i++;
		}
		if (game->map[j][i] == 'E')
			break ;
		j++;
	}
	game->exit_row = j;
	game->exit_column = i;
}

void	makenull(t_map (*game))
{
	game->mlx = NULL;
	game->map = NULL;
	game->images = NULL;
}

int	main(int argc, char **argv)
{
	t_map	*game;

	game = malloc(sizeof(t_map));
	makenull(game);
	if (argc != 2)
		shit(NULL);
	game->movs = 0;
	read_map(argv[1], game);
	if (check_errors(game, argv[1]) == 1)
	{
		pos_player(game);
		pos_exit(game);
		game->mlx = mlx_init(PIX * (game->col -1), PIX * (game->rows),
				"So Long", true);
		game->images = malloc(sizeof(t_images));
		print_map(game);
		mlx_key_hook(game->mlx, &my_keyhook, game);
		mlx_loop(game->mlx);
		mlx_terminate(game->mlx);
	}
	free_map(game->map);
	free(game->mlx);
	free(game->images);
	free(game);
	return (0);
}
