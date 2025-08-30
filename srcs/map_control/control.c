#include "../../includes/cub3d.h"

static void	name_control(char *s, char **map)
{
	int	i;

	i = 0;
	if (strlen(s) < 4)
	{
		clear_2d_pointer(map);
		printf("The map file  incorrect.\n");
		exit (EXIT_FAILURE);
	}
	while (s[i + 4])
		i++;
	if (ft_strncmp(&s[i], ".cub", 4))
	{
		clear_2d_pointer(map);
		printf("The map file format is incorrect.\n");
		exit (EXIT_FAILURE);
	}
}

void	map_control(int ac, char **av)
{
	char	**map;

	if (ac != 2 || !av[1])
	{
		printf("Map file missing.\n");
		exit (EXIT_FAILURE);
	}
	map = read_and_split(av[1]);
	if (!map)
		exit(EXIT_FAILURE);
	name_control(av[1], map);

	clear_2d_pointer(map);
}
