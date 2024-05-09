/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:57 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/06 20:25:53 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(t_map	*game, int i, int j)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./assets/wall.png");
	if (!wall)
		shit();
	game->images->wall = mlx_texture_to_image(game->mlx, wall);
	if (!game->images->wall)
		shit();
	mlx_image_to_window(game->mlx, game->images->wall, i * PIXELS, j * PIXELS);
	if (mlx_image_to_window(game->mlx, \
		game->images->wall, i * PIXELS, j * PIXELS) < 0)
		shit();
}

void	load_floor(t_map	*game, int i, int j)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./assets/floor.png");
	if (!floor)
		shit();
	game->images->floor = mlx_texture_to_image(game->mlx, floor);
	if (!game->images->floor)
		shit();
	mlx_image_to_window(game->mlx, game->images->floor, i * PIXELS, j * PIXELS);
	if (mlx_image_to_window(game->mlx, \
		game->images->floor, i * PIXELS, j * PIXELS) < 0)
		shit();
}

void	load_door(t_map	*game, int i, int j)
{
	mlx_texture_t	*door;

	door = mlx_load_png("./assets/door.png");
	if (!door)
		shit();
	game->images->door = mlx_texture_to_image(game->mlx, door);
	if (!game->images->door)
		shit();
	mlx_image_to_window(game->mlx, game->images->door, i * PIXELS, j * PIXELS);
	if (mlx_image_to_window(game->mlx, \
		game->images->door, i * PIXELS, j * PIXELS) < 0)
		shit();
}

void	load_player(t_map	*game, int i, int j)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/player.png");
	if (!player)
		shit();
	game->images->player = mlx_texture_to_image(game->mlx, player);
	if (!game->images->player)
		shit();
	mlx_image_to_window(game->mlx, \
		game->images->player, i * PIXELS, j * PIXELS);
}

void	load_coin(t_map	*game, int i, int j)
{
	mlx_texture_t	*coin;

	coin = mlx_load_png("./assets/coin.png");
	if (!coin)
		shit();
	game->images->coins = mlx_texture_to_image(game->mlx, coin);
	if (!game->images->coins)
		shit();
	mlx_image_to_window(game->mlx, game->images->coins, i * PIXELS, j * PIXELS);
	if (mlx_image_to_window(game->mlx, \
		game->images->coins, i * PIXELS, j * PIXELS) < 0)
		shit();
}
