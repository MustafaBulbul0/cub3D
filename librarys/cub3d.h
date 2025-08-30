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
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "structs.h"

int		map_control(int ac, char **av);

char	**read_and_split(char *path);
void	clear_2d_pointer(char **map);

void	shut_program_error(t_all *all, char *s);
void	ft_free_all(t_all *all);

#endif