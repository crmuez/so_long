/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:04:50 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/13 21:18:30 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# define PIX 71

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*door;
	mlx_image_t	*open_door;
	mlx_image_t	*coins;
}					t_images;

typedef struct s_map
{
	char		**map;
	int			col;
	int			rows;
	int			collects;
	int			player_y;
	int			player_x;
	int			exit_row;
	int			exit_column;
	int			movs;
	mlx_t		*mlx;
	t_images	*images;
}			t_map;

int		main(int argc, char **argv);
char	*get_next_line(int fd);
int		ft_printf(char const *s, ...);
int		ft_conversion(char s, va_list args);
char	*manage_storage(int fd, int bytesread, char **text);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_malloc_line(char *text);
char	*ft_free_line(char *text);
int		count_lines(char *argv);
int		count_chars(t_map *game);
void	read_map(char *argv, t_map *game);
int		check_rect(t_map *game);
int		check_walls(t_map *game);
int		check_ep(t_map *game);
int		check_collect(t_map *game);
int		check_letters(t_map *game);
int		floodfill(char	*argv, t_map *game);
void	pos_player(t_map *game);
void	pos_exit(t_map *game);
void	shit(t_map *game);
int		check_errors(t_map *game, char *argv);
void	load_wall(t_map	*game, int i, int j);
void	load_floor(t_map	*game, int i, int j);
void	load_door(t_map	*game, int i, int j);
void	load_player(t_map	*game, int i, int j);
void	load_coin(t_map	*game, int i, int j);
void	load_open_door(t_map	*game, int i, int j);
void	print_map(t_map	*game);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	collec_coins(t_map *game);
int		check_exit(t_map *game);
void	free_map(char **map);

#endif