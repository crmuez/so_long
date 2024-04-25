/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:11:17 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/04/25 17:08:07 by crmunoz-         ###   ########.fr       */
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
			if (game->map[j][i] != 'P')
				i++;
		}
		j++;
	}
	game->player_row = j;
	game->player_column = i;
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
			if (game->map[j][i] != 'E')
				i++;
		}
		j++;
	}
	game->exit_row = j;
	game->exit_column = i;
}

int	main(int argc, char **argv)
{
	t_map	*game;

	game = malloc(sizeof(t_map));
	if (argc != 2)
		shit();
	read_map(argv[1], game);
	if (check_rect(game) && check_walls(argv[1], game) && check_ep(game)
		&& check_collect(game) && check_letters(game))
	{
		pos_player(game);
		pos_exit(game);
		game->mlx = malloc(sizeof(mlx_t));
		game->mlx = mlx_init(300, 300,
				"puto juego the 42balls", true);
		mlx_loop(game->mlx);
		print_images(game);
	}else
		write(1,"caca",4);*/
	return (0);
}

	/*int i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}*/