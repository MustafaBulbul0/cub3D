#include "../../includes/cub3d.h"

char	**strdup_2d(char **map)
{
	char	**new_map;
	int		len;
	int		i;

	i =	0;
	len = 0;
	while (map[len])
		len++;
	new_map = ft_calloc(len + 1, sizeof(char *));
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	return (new_map);
}
