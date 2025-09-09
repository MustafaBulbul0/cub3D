#include "../../includes/cub3d.h"

int	longest_row(char **map)
{
	int	longest;
	int	i;
	int	j;

	i = 0;
	longest = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > longest)
			longest = j;
		i++;
	}
	return (longest + 2);
}

int	num_row(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i + 2);
}

void	make_copy_and_space(char *src, char *dest, int col)
{
	int	j;

	j = 1;
	dest[0] = 32;
	if (src)
	{
		while (src[j - 1])
		{
			dest[j] = src[j - 1];
			j++;
		}
	}
	while (j < col)
	{
		dest[j] = 32;
		j++;
	}
	dest[j] = '\0';
}

char	**new_map(char **map, int row, int col, t_all *all)
{
	char	**new_map;
	int		i;

	new_map = malloc((row + 1) * sizeof(char *));
	if (!new_map)
		exit_print("Malloc failed.", all);
	i = 1;
	new_map[0] = malloc(col + 1);
	make_copy_and_space(NULL, new_map[0], col);
	while (i < row - 1)
	{
		new_map[i] = malloc(col + 1);
		make_copy_and_space(map[i - 1], new_map[i], col);
		i++;
	}
	new_map[i] = malloc(col + 1);
	make_copy_and_space(NULL, new_map[i], col);
	new_map[row] = NULL;
	return (new_map);
}

void	hole_control(t_all *all)
{
	char	**map;
	char	**n_map;
	int		i;
	int		j;
	int		xy[2];

	ft_memset(xy, 0, sizeof(xy));
	i = -1;
	map = all->game->map;
	n_map = new_map(map, num_row(map), longest_row(map), all);
	flood_fill(n_map, xy, num_row(map), longest_row(map));
	while (n_map[++i])
	{
		j = 0;
		while (n_map[i][j])
		{
			if (is_space(n_map[i][j]))
			{
				clear_2d_pointer(n_map);
				exit_print("Map is wrong.", all);
			}
			j++;
		}
	}
	clear_2d_pointer(n_map);
}
