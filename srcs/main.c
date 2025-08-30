#include "../librarys/cub3d.h"

int	main(int ac, char **av)
{
	t_all	*all_structs;

	map_control(ac, av);
	all_structs = malloc(sizeof(t_all));

	ft_free_all(all_structs);
	return (0);
}
