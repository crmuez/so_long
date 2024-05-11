/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collects.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:35:03 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/11 13:34:51 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_coins(t_map *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->collects;
	while (count > 0)
	{
		if (((game->images->coins->instances[i].y
					== game->images->player->instances->y)
				&& (game->images->coins->instances[i].x
					== game->images->player->instances->x))
			&& game->images->coins->instances[i].enabled == true)
		{
			game->images->coins->instances[i].enabled = false;
			game->map[game->player_y][game->player_x] = '0';
			print_map(game);
			count--;
			return ;
		}
		i++;
	}
}

void	collec_coins(t_map *game)
{
	if (game->map[game->images->player->instances->y / PIX]
		[game->images->player->instances->x / PIX] == 'C')
	{
		delete_coins(game);
		game->map[game->images->player->instances->y / PIX]
		[game->images->player->instances->x / PIX] = '0';
		game->collects--;
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