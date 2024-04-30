/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cosas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:57 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/04/30 20:11:35 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_map	*game)
{
	game->images.floor = mlx_load_png("./assets/floor.png");
	game->images.door = mlx_load_png("./assets/door.png");
	game->images.wall = mlx_load_png("./assets/wall.png");
	game->images.player = mlx_load_png("./assets/player.png");
	game->images.coins = mlx_load_png("./assets/coin.png");
}

mlx_image_t	*get_png(t_map *game, char pos)
{
	mlx_image_t	*img;

	if (pos == '1')
		img = mlx_texture_to_image(game->mlx, game->images.wall);
	if (pos == '0')
		img = mlx_texture_to_image(game->mlx, game->images.floor);
	if (pos == 'C')
		img = mlx_texture_to_image(game->mlx, game->images.coins);
	if (pos == 'P')
		img = mlx_texture_to_image(game->mlx, game->images.player);
	if (pos == 'E')
		img = mlx_texture_to_image(game->mlx, game->images.door);
	if (!img)
		shit();
	return (img);
}

void	print_map(t_map	*game)
{
	mlx_image_t	*img;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (game->map[j])
	{
		printf("%d", j);
		i = 0;
		while (game->map[j][i] != '\n' && game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'P' || game->map[j][i] == 'C')
			{
				img = get_png(game, '0');
				mlx_image_to_window(game->mlx, img, i * 71, j * 71);
			}
			img = get_png(game, game->map[j][i]);
			if (mlx_image_to_window(game->mlx, img, i * 71, j * 71) < 0)
				shit();
			i++;
		}
		j++;
	}
}