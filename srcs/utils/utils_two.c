#include "../../includes/cub3d.h"

void	init_map_texture(t_all *all)
{
	char	**map;
	int		i;

	map = all->game->map;
	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(map[i], "NO", 2) == 0)
			all->texture->no = ft_strdup(map[i] + 2);
		else if (ft_strncmp(map[i], "SO", 2) == 0)
			all->texture->so = ft_strdup(map[i] + 2);
		else if (ft_strncmp(map[i], "WE", 2) == 0)
			all->texture->we = ft_strdup(map[i] + 2);
		else if (ft_strncmp(map[i], "EA", 2) == 0)
			all->texture->ea = ft_strdup(map[i] + 2);
		else if (ft_strncmp(map[i], "F", 1) == 0)
			all->texture->f = ft_strdup(map[i] + 1);
		else if (ft_strncmp(map[i], "C", 1) == 0)
			all->texture->c = ft_strdup(map[i] + 1);
		i++;
	}
	//clear_2d_pointer(map);

}

