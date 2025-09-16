#include "../../includes/cub3d.h"

void	file_control(t_all *all, int ac, char **av)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	if (ac != 2 || !av[1])
		exit_print("Map file missing.", all);
	s = av[1];
	if (ft_strlen(s) <= 4 || secret_file(s))
		exit_print("The map file format is incorrect.", all);
	while (s[i + 4])
		i++;
	if (ft_strncmp(&s[i], ".cub", 4) != 0)
		exit_print("The map file format is incorrect.", all);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_print("The file could not be opened.", all);
	close (fd);
}

static int	inner_loop(char **map, int i, int j)
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
