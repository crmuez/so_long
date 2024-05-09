/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:11:17 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/09 20:17:37 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// comprobar la función de pos_player
// comprobar la función de pos_exit
//void	star_game(t_map *game)

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
				break;
			else
				i++;
		}
		if (game->map[j][i] == 'P')
			break;
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
				break;
			else
				i++;
		}
		if (game->map[j][i] == 'E')
			break;
		j++;
	}
	game->exit_row = j;
	game->exit_column = i;
}

int	main(int argc, char **argv)
{
	t_map	*game;

	game = malloc(sizeof(t_map));
	if (!game)
		free(game);
	if (argc != 2)
		shit();
	read_map(argv[1], game);
	if (check_rect(game) && check_walls(game) && check_collect(game)
		&& check_ep(game) && check_letters(game) && floodfill(argv[1], game))
	{
		pos_player(game);
		printf("1 Pos player x: %d\n", game->player_x);
		printf("1 Pos player y: %d\n", game->player_y);
		pos_exit(game);
		game->mlx = malloc(sizeof(mlx_t));
		if (!game->mlx)
		{
			puts(mlx_strerror(mlx_errno));
			return (EXIT_FAILURE);
		}
		game->mlx = mlx_init(PIXELS * (game->columns -1), PIXELS * (game->rows),
				"So Long", true);
		game->images = malloc(sizeof(t_images));
		print_map(game);
		mlx_key_hook(game->mlx, &my_keyhook, game);
		mlx_loop(game->mlx);
	}
	return (0);
}
