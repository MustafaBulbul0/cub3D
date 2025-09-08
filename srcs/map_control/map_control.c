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

void	wall_control(t_all *all)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = all->game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_space(map[i][j]))
			{
				if (space_or_end(map[i - 1][j]) || space_or_end(map[i + 1][j])
					|| space_or_end(map[i][j - 1]) || space_or_end(map[i][j + 1]))
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

void	hole_control(t_all *all)
{
	int		i;
	int		j;
	char	**map;
	int		counter;

	map = all->game->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			
		}
		i++;
	}
}
