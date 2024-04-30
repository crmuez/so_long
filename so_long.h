/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:04:50 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/04/30 20:00:49 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_images
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*door;
	mlx_texture_t	*coins;
}					t_images;

typedef struct s_map
{
	char		**map;
	int			columns;
	int			rows;
	int			collects;
	int			player_row;
	int			player_column;
	int			exit_row;
	int			exit_column;
	int			movs;
	mlx_t		*mlx;
	t_images	images;
}			t_map;

int		main(int argc, char **argv);
char	*get_next_line(int fd);
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
void	shit(void);
void	load_images(t_map	*game);
void	print_map(t_map	*game);

#endif