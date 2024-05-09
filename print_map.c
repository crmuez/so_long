/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:57 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/06 20:28:41 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map	*game)
{
	mlx_image_t	*img;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\n' && game->map[j][i] != '\0')
		{
			load_floor(game, i, j);
			if (game->map[j][i] == '1')
				load_wall(game, i, j);
			else if (game->map[j][i] == 'E')
				load_door(game, i, j);
			else if (game->map[j][i] == 'C')
				load_coin(game, i, j);
			i++;
		}
		j++;
	}
	load_player(game, game->player_x, game->player_y);
}
