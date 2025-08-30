#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_all	*all_structs;

	file_control(ac, av);
	all_structs = malloc(sizeof(t_all));
	read_and_split(av[1], all_structs);

	ft_free_all(all_structs);
	return (0);
}
