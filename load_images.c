/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:57 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/13 21:24:10 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(t_map	*game, int i, int j)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./assets/wall.png");
	if (!wall)
		shit(game);
	game->images->wall = mlx_texture_to_image(game->mlx, wall);
	mlx_delete_texture(wall);
	if (!game->images->wall)
		shit(game);
	mlx_image_to_window(game->mlx, game->images->wall, i * PIX, j * PIX);
	if (mlx_image_to_window(game->mlx, \
		game->images->wall, i * PIX, j * PIX) < 0)
		shit(game);
}

void	load_floor(t_map	*game, int i, int j)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./assets/floor.png");
	if (!floor)
		shit(game);
	game->images->floor = mlx_texture_to_image(game->mlx, floor);
	mlx_delete_texture(floor);
	if (!game->images->floor)
		shit(game);
	mlx_image_to_window(game->mlx, game->images->floor, i * PIX, j * PIX);
	if (mlx_image_to_window(game->mlx, \
		game->images->floor, i * PIX, j * PIX) < 0)
		shit(game);
}

void	load_door(t_map	*game, int i, int j)
{
	mlx_texture_t	*door;

	door = mlx_load_png("./assets/door.png");
	if (!door)
		shit(game);
	game->images->door = mlx_texture_to_image(game->mlx, door);
	mlx_delete_texture(door);
	if (!game->images->door)
		shit(game);
	mlx_image_to_window(game->mlx, game->images->door, i * PIX, j * PIX);
	if (mlx_image_to_window(game->mlx, \
		game->images->door, i * PIX, j * PIX) < 0)
		shit(game);
}

void	load_player(t_map	*game, int i, int j)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/player.png");
	if (!player)
		shit(game);
	game->images->player = mlx_texture_to_image(game->mlx, player);
	mlx_delete_texture(player);
	if (!game->images->player)
		shit(game);
	mlx_image_to_window(game->mlx, \
		game->images->player, i * PIX, j * PIX);
}

void	load_coin(t_map	*game, int i, int j)
{
	mlx_texture_t	*coin;

	coin = mlx_load_png("./assets/coin.png");
	if (!coin)
		shit(game);
	game->images->coins = mlx_texture_to_image(game->mlx, coin);
	mlx_delete_texture(coin);
	if (!game->images->coins)
		shit(game);
	mlx_image_to_window(game->mlx, game->images->coins, i * PIX, j * PIX);
	if (mlx_image_to_window(game->mlx, \
		game->images->coins, i * PIX, j * PIX) < 0)
		shit(game);
}
