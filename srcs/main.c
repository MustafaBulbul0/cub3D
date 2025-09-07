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

	if (all_structs->game->map)
	{
		for (int i = 0; all_structs->game->map[i] ; i++)
			printf("%s\n", all_structs->game->map[i]);
	}

	printf("\n");
	if (all_structs->texture->no)
		printf("%s\n", all_structs->texture->no);
	if (all_structs->texture->so)	
		printf("%s\n", all_structs->texture->so);
	if (all_structs->texture->we)
		printf("%s\n", all_structs->texture->we);
	if (all_structs->texture->ea)
		printf("%s\n", all_structs->texture->ea);
	if (all_structs->texture->f)
		printf("%s\n", all_structs->texture->f);
	if (all_structs->texture->c)
		printf("%s\n", all_structs->texture->c);
	
	for (int i = 0; i < 3 ; i++)
		printf("%d\n", all_structs->texture->f_color[i]);
	for (int i = 0; i < 3 ; i++)
		printf("%d\n", all_structs->texture->c_color[i]);


	ft_free_all(all_structs);
	return (0);
}
