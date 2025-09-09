#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_all	*all_structs;

	all_structs = map_control(ac, av);

	ft_free_all(all_structs);
	return (0);
}
