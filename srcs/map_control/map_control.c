#include "../../includes/cub3d.h"

int	character_control (char c, t_all *all)
{
	int position;

	position = 0;
	if (!(c == '1' || c == '0' || is_space(c) || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '\0'))
		exit_print("The map is wrong.", all);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		position++;
		all->game->player_position = c;
	}
	return (position);
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

int	space_or_end (char c)
{
	if (is_space(c) || c == '\0')
		return (1);
	return (0);
}

int	check_neighbors(char **map, int i, int j)
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


int	inner_loop(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (!is_space(map[i][j]) && map[i][j] != '\0')
			return (1);
		j++;
	}
	return (0);
}

void	is_single_map(t_all *all)
{
	int		i;
	int		counter;
	int		loop_value;
	char	**map;

	map = all->game->map;
	i = 0;
	counter = 0;
	while (map[i])
	{
		counter = inner_loop(map, i, 0);
		if (counter)
			break ;
		i++;
	}
	i++;
	while (map[i])
	{
		loop_value = inner_loop(map, i, 0);
		if (loop_value == 1 && counter == 0)
			exit_print("The map is wrong.", all);
		counter = loop_value;
		i++;
	}
}
