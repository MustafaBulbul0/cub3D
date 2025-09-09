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
	init_map_texture(all_structs);
	read_map(all_structs, av[1]);
	map_control(all_structs);

	ft_free_all(all_structs);
	return (0);
}
