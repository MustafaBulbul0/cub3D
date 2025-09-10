#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>   
# include <sys/time.h>
# include <math.h>
# include <errno.h>
# include "structs.h"
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/minilibx-linux/mlx_int.h"

# define Y_PI 3.14159265359

void	file_control(t_all *all, int ac, char **av);
t_all	*map_control(int ac, char **av);
void	map_character(t_all *all);
void	wall_control(t_all *all);
void	is_single_map(t_all *all);
void	hole_control(t_all *all);
void	texture_control(t_all *all);

void	read_and_split(char *path, t_all *all);
void	clear_2d_pointer(char **map);
char	*ft_realloc(char *s, int size);
char	**ft_realloc_2d(char **ptr, size_t size);
void	init_all_structs(t_all *all);
char	**strdup_2d(char **map);
void	init_map_texture(t_all *all);
void	read_map(t_all *all, char *path);
char	**special_split(char *s);
int		is_space(char c);
int		space_or_end(char c);
int		character_control(char c, t_all *all);
void	flood_fill(char **map, int xz[2], int row, int col);
int		secret_file(char *path);

void	shut_program_error(t_all *all, char *s);
void	ft_free_all(t_all *all);
void	exit_print(char *s, t_all *all);

void	start_game(t_all *all);

#endif