#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_all	*all_structs;

	file_control(ac, av);
	all_structs = malloc(sizeof(t_all));
	if (!all_structs)
		return (0);
	init_all_structs(all_structs);
	read_and_split(av[1], all_structs);
	
	for (int i = 0; all_structs->game->map[i] ; i++)
	{
		printf("%s\n", all_structs->game->map[i]);
	}

	ft_free_all(all_structs);
	return (0);
}
