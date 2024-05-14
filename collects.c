/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collects.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:35:03 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/14 18:15:25 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_coins(t_map *game)
{
	int	i;

	i = 0;
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		load_floor(game, game->player_x, game->player_y);
		load_tig(game, game->player_x, game->player_y);
		load_player(game, game->player_x, game->player_y);
		game->collects--;
	}
}

void	collec_coins(t_map *game)
{
	if (game->map[game->images->player->instances->y / PIX]
		[game->images->player->instances->x / PIX] == 'C')
	{
		delete_coins(game);
		if (game->collects == 0)
		{
			game->images->door->instances->enabled = false;
			load_open_door(game, game->exit_column, game->exit_row);
		}
	}
	if (game->map[game->images->player->instances->y / PIX]
		[game->images->player->instances->x / PIX] == 'E')
	{
		check_exit(game);
		if (game->collects == 0)
			mlx_close_window(game->mlx);
	}
}
