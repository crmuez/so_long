/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:27:56 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/09 20:53:18 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*game;

	game = (t_map *) param;
	printf("2 Pos player x: %d\n", game->player_x);
	printf("2 Pos player y: %d\n", game->player_y);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (game->map[game->player_y - 1][game->player_x] != '1')
		{
			game->images->player->instances[0].y -= PIXELS;
			game->player_y--;
		}
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (game->map[game->player_y + 1][game->player_x] != '1')
		{
			game->images->player->instances[0].y += PIXELS;
			game->player_y++;
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (game->map[game->player_y][game->player_x - 1] != '1')
		{
			game->images->player->instances[0].x -= PIXELS;
			game->player_x--;
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (game->map[game->player_y][game->player_x + 1] != '1')
		{
			game->images->player->instances[0].x += PIXELS;
			game->player_x++;
		}
	}
	printf("3 Pos player x: %d\n", game->player_x);
	printf("3 Pos player y: %d\n", game->player_y);
}
