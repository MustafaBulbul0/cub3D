#ifndef cub3d_H
# define cub3d_H

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

void	file_control(int ac, char **av);
void	map_control(t_all *all);

void	read_and_split(char *path, t_all *all);
void	clear_2d_pointer(char **map);
char	*ft_realloc(char *s, int size);
void	init_all_structs(t_all *all);
char	**strdup_2d(char **map);
void	init_map_texture(t_all *all);
void	read_map(t_all *all, char *path);
char	**special_split(char *s);
int		is_space(char c);

void	shut_program_error(t_all *all, char *s);
void	ft_free_all(t_all *all);
void	exit_print(char *s, t_all *all);

#endif