/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:51:58 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/04/25 16:53:45 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_images(t_map	*game)
{
	mlx_texture_t* texture = mlx_load_png("./assets/floor.xpm");
	if (!texture)
        shit();
	mlx_image_t* img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
        shit();
	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
        shit();
	mlx_loop(game->mlx);
}