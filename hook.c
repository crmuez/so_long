/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:27:56 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/11 12:41:01 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_map *game, mlx_key_data_t keydata)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->images->player->instances[0].y -= PIX;
		game->player_y--;
		game->movs++;
		ft_printf("Movs: %d\n", game->movs);
	}
}

void	key_s(t_map *game, mlx_key_data_t keydata)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->images->player->instances[0].y += PIX;
		game->player_y++;
		game->movs++;
		ft_printf("Movs: %d\n", game->movs);
	}
}

void	key_a(t_map *game, mlx_key_data_t keydata)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->images->player->instances[0].x -= PIX;
		game->player_x--;
		game->movs++;
		ft_printf("Movs: %d\n", game->movs);
	}
}

void	key_d(t_map *game, mlx_key_data_t keydata)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->images->player->instances[0].x += PIX;
		game->player_x++;
		game->movs++;
		ft_printf("Movs: %d\n", game->movs);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*game;

	game = (t_map *) param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		key_w(game, keydata);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		key_s(game, keydata);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		key_a(game, keydata);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		key_d(game, keydata);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(1);
	collec_coins(game);
}
