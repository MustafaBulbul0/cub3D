#include "../../includes/cub3d.h"

t_all	*map_control(int ac, char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		exit_print("Malloc failed.", NULL);
	init_all_structs(all);
	file_control(all, ac, av);
	read_and_split(av[1], all);
	init_map_texture(all);
	read_map(all, av[1]);
	texture_control(all);
	map_character(all);
	wall_control(all);
	is_single_map(all);
	hole_control(all);
	return (all);
}

void	map_character(t_all *all)
{
	int		i;
	int		j;
	int		position;
	char	**map;

	i = 0;
	position = 0;
	map = all->game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			position += character_control(map[i][j], all);
			j++;
		}
		i++;
	}
	if (position != 1)
		exit_print("The map is wrong.", all);
}

static int	check_neighbors(char **map, int i, int j)
{
	int	up_row;
	int	down_row;

	if (i == 0 || !map[i + 1])
		return (1);
	if (j == 0 || j == (int)ft_strlen(map[i]) - 1)
		return (1);
	up_row = ft_strlen(map[i - 1]);
	down_row = ft_strlen(map[i + 1]);
	if (j >= up_row || j >= down_row)
		return (1);
	if (space_or_end(map[i - 1][j]) || space_or_end(map[i + 1][j])
		|| space_or_end(map[i][j - 1]) || space_or_end(map[i][j + 1]))
		return (1);
	if (space_or_end(map[i - 1][j - 1]) || space_or_end(map[i + 1][j + 1])
		|| space_or_end(map[i + 1][j - 1]) || space_or_end(map[i - 1][j + 1]))
		return (1);
	return (0);
}

void	wall_control(t_all *all)
{
	int		i;
	int		j;
	char	**map;

	map = all->game->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_space(map[i][j]))
			{
				if (check_neighbors(map, i, j))
				{
					if (map[i][j] != '1')
						exit_print("The map is wrong.", all);
				}
			}
			j++;
		}
		i++;
	}
}

